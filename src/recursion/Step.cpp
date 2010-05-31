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
    r = NULL;
    
    marker::GlobalMarkers::instance()->markers_reset();
}

StatusMessage* Step::step() {
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
        // Create problem and rules
        try {
            std::string problem_id = core::Parameters::instance()->PROBLEM();
            if (problem_id == "pdebug") { p = new problem::PDebug(s); }
            else if (problem_id == "reverse") { p = new problem::Reverse(s); }
            else if (problem_id == "join") { p = new problem::Join(s); }
            else if (problem_id == "removeall") { p = new problem::RemoveAll(s); }
            else if (problem_id == "compress") { p = new problem::Compress(s); }
            else if (problem_id == "insertionsort") { p = new problem::InsertionSort(s); }
            else {
                D(( "INVALID PROBLEM ID" ));
            }
        }
        catch(std::runtime_error e) {
            reset();
            return new StatusMessage(StatusMessage::CONTINUE, "Invalid initial state: " + std::string(e.what()));
        }
        
        r = p->create_rules();
        D(( r->text().c_str() ));
        
        return new StatusMessage(StatusMessage::CONTINUE, "good initial state");
    }
    
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
    r->verify(as);
    if ( !as->valid_rules() ) {
        as->alert("Invalid move: rules");
        return new StatusMessage(StatusMessage::STANDBY, "Invalid move: check step-by-step");
    }
    
    // check if this state is the valid final state
    if (p->validate_return(current_state)) {
        return new StatusMessage(StatusMessage::STOP, "Great! Problem solved");
    }
    
    // create erlang code message
    VariableSet* vars = new VariableSet();
    vars->fill(previous_state);
    vars->parse(as);
    
    std::string msg = vars->erlang();
    D(( "ERLANG = [[ %s ]]", msg.c_str() ));
    
    return new StatusMessage(StatusMessage::CONTINUE, msg);
}

}}
