#include "ListProblem.hpp"

namespace vestige {
namespace problem {

ListProblem::ListProblem() {
    _ids = new std::vector<std::string>();
}

int ListProblem::validate_return(state::Node* ret) {
    if ( ! ret ) {
        return 0;
    }
    
    if ( ! dynamic_cast<marker::List*>(ret->marker()) ) {
        return 0;
    }
    
    // sizes must match
    if ( ret->children()->size() != _ids->size() ) {
        return 0;
    }
    
    int index = 0;
    BOOST_FOREACH(state::Node* n, *(ret->children())) {
        if (n->id() != (*_ids)[index]) {
            return 0;
        }
        index++;
    }
    
    return 1;
}

}}
