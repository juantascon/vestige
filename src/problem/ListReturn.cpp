#include "ListReturn.hpp"

namespace vestige {
namespace problem {

ListReturn::ListReturn() {
    _ids = new std::vector<std::string>();
}

int ListReturn::validate_return(state::Node* ret) {
    state::List* l = dynamic_cast<state::List*>(ret);
    
    if ( ! l ) { return 0; }
    
    // sizes must match
    if ( l->children()->size() != _ids->size() ) {
        return 0;
    }
    
    int index = 0;
    BOOST_FOREACH(state::Node* n, *(l->children())) {
        if (n->id() != (*_ids)[index]) {
            return 0;
        }
        index++;
    }
    
    return 1;
}

}}
