#include "Step.hpp"

#include "../marker/GlobalMarkers.hpp"

namespace vestige {
namespace recursion {

Step* Step::instance() {
    return &boost::serialization::singleton<recursion::Step>::get_mutable_instance();
}

Step::Step() {
    reset();
}

void Step::reset() {
    previous_state = 0;
    current_state = 0;
    
    p = NULL;
    rs = NULL;
    
    marker::GlobalMarkers::instance()->markers_reset();
}

StatusMessage* Step::initial() {
    // Create problem and rules
    try {
        std::string problem_id = core::Parameters::instance()->PROBLEM();
        if (problem_id == "pdebug") { p = new problem::PDebug(current_state); }
        else if (problem_id == "reverse") { p = new problem::Reverse(current_state); }
        else if (problem_id == "join") { p = new problem::Join(current_state); }
        else if (problem_id == "removeall") { p = new problem::RemoveAll(current_state); }
        else if (problem_id == "compress") { p = new problem::Compress(current_state); }
        else if (problem_id == "insertionsort") { p = new problem::InsertionSort(current_state); }
        else {
            D(( "INVALID PROBLEM ID" ));
        }
    }
    catch(std::runtime_error e) {
        reset();
        return new StatusMessage(StatusMessage::CONTINUE, "Invalid initial state: " + std::string(e.what()));
    }

    // Create rules
    rs = p->create_rules();
    D(( rs->text().c_str() ));

    // Syncronize rules
    rs->sync();
    
    // Rename labels
    rs->set_labels(current_state);
    
    return new StatusMessage(StatusMessage::CONTINUE, "good initial state");
}

StatusMessage* Step::recursive() {
    // Syncronize rules
    rs->sync();
    
    // get the executed actions
    action::ActionSet *as = new action::ActionSet();
    as->diff(previous_state, current_state);
    D(( as->text().c_str() ));
    
    // Empty actions are ignored
    if (as->size() == 0) { return new StatusMessage(StatusMessage::CONTINUE, ""); }
    
    // valid logic move
    action::Logic::instance()->verify(as);
    if (!as->valid_logic()) {
        as->alert("Invalid move: logic");
        return new StatusMessage(StatusMessage::STANDBY, "Invalid move: check logic");
    }
    
    // valid rules move
    rs->verify(as);
    if ( !as->valid_rules() ) {
        as->alert("Invalid move: rules");
        return new StatusMessage(StatusMessage::STANDBY, "Invalid move: check step-by-step");
    }
    
    // get erlang clause
    std::string msg = rs->clause();
    D(( "ERLANG = [[ %s ]]", msg.c_str() ));
    
    // check if this state is the valid final state
    if (p->validate_return(current_state)) {
        return new StatusMessage(StatusMessage::STOP, msg+"\n\nGreat! Problem solved");
    }
    
    // Rename labels
    rs->set_labels(current_state);
    
    return new StatusMessage(StatusMessage::CONTINUE, msg);
}

StatusMessage* Step::step() {
    // capture position and visibility of markers
    marker::GlobalMarkers::instance()->capture_info();
    
    // fix ids of new markers
    marker::GlobalMarkers::instance()->assign_empty_ids();
    
    // Capture state
    state::State *s = new state::State();
    s->capture();
    
    D(( s->text().c_str() ));
    
    // ignore states with no nodes
    if (s->size() == 0) {
        return new StatusMessage(StatusMessage::CONTINUE, "empty state");
    }
    
    // at this point is safe to switch states
    previous_state = current_state;
    current_state = s;
    
    // initialize the problem specification
    if (!p) {
        initial();
    }
    else {
        recursive();
    }
    
    
}

}}
