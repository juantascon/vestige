#include "ListReturn.hpp"

namespace vestige {
namespace problem {

ListReturn::ListReturn() {
    _ids = new std::list<std::string>();
}

int ListReturn::validate_return(state::State* s) {
    state::NodeSet* lists = s->clone_nodes();
    lists->filter_by_no_parent();
    if (lists->size() != 1) { return 0; }
    
    state::List* l = lists->remove_single_list();
    if ( ! l ) { return 0; }
    
    // sizes must match
    if ( l->children()->size() != _ids->size() ) {
        return 0;
    }

    std::list<std::string>::iterator it = _ids->begin();
    BOOST_FOREACH(state::Node* n, *(l->children())) {
        if (it == _ids->end()) { return 0; }
        if (n->id() != (*it)) { return 0; }
        ++it;
    }
    
    return 1;
}

}}
