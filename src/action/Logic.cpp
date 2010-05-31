#include "Logic.hpp"

namespace vestige {
namespace action {


Logic* Logic::instance() {
    return &boost::serialization::singleton<action::Logic>::get_mutable_instance();
}

Logic::Logic()
{
}

void Logic::set_all_valid(ActionSet* as, int valid) {
    BOOST_FOREACH(Action *a, *as) {
        a->valid_logic = valid;
    }
}

void Logic::verify(ActionSet* as) {
    BOOST_FOREACH(Action *a, *as) {
        if ( dynamic_cast<action::Invalid*>(a) ) {
            D(("invalid action"));
            set_all_valid(as, 0);
            return;
        }
    }
    
    // 2 or more movements implies error unless:
    // they are all discard
    // they are all create
    if (as->size() >= 2) {
        int all_discard = 1;
        int all_create = 1;
        BOOST_FOREACH(Action *a, *as) {
            if ( ! dynamic_cast<action::Discard*>(a) ) {
                all_discard = 0;
            }
            if ( ! dynamic_cast<action::Create*>(a) ) {
                all_create = 0;
            }
        }
        
        if (!all_create && !all_discard) {
            D(("not all create or discard"));
            set_all_valid(as, 0);
            return;
        }
    }
    
    set_all_valid(as, 1);
}

}}
