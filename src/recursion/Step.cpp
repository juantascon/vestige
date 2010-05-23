#include "Step.hpp"

#include "../marker/GlobalMarkers.hpp"

namespace vestige {
namespace recursion {

Step* Step::instance() {
    return &boost::serialization::singleton<recursion::Step>::get_mutable_instance();
}

Step::Step() {
    previous_state = 0;
    current_state = 0;
}

StatusMessage* Step::step() {
    // Capture state
    state::State *s = new state::State();
    s->capture();
    
    // fix ids of new markers
    marker::GlobalMarkers::instance()->assign_empty_ids();
    D(( s->text().c_str() ));
    
    // ignore states with no nodes
    if (s->size() == 0) {
        return new StatusMessage(0, "");
    }
    
    // initialize the problem specification
    if (!p) {
        // Create problem and rules
        try {
            // p = new problem::PDebug(s);
            // p = new problem::Reverse(s);
            // p = new problem::Join(s);
            // p = new problem::RemoveAll(s);
            // p = new problem::Compress(s);
            p = new problem::InsertionSort(s);
        }
        catch(std::runtime_error e) {
            return new StatusMessage(0, "Invalid initial state: " + std::string(e.what()));
        }
        
        r = p->create_rules();
        D(( r->text().c_str() ));
    }

    // at this poiint it is safe to switch states
    previous_state = current_state;
    current_state = s;
    
    // check if this state is the valid final state
    if (p->validate_return(current_state)) {
        return new StatusMessage(1, "Great! Problem solved");
    }
    
    action::ActionSet *as = new action::ActionSet();
    as->diff(previous_state, current_state);
    D(( as->text().c_str() ));
    
    // Empty actions are ignored
    if (as->size() == 0) { return new StatusMessage(0, ""); }

    // valid logic move
    if (!as->valid_logic()) {
        as->alert("Invalid move: logic");
        return new StatusMessage(1, "Invalid move: check logic");
    }

    // valid rules move
    r->verify(as);
    if ( !as->valid_rules() ) {
        as->alert("Invalid move: rules");
        return new StatusMessage(1, "Invalid move: check step-by-step");
    }
    
    return new StatusMessage(0, "");
}

}}
