#include "Join.hpp"

namespace vestige {
namespace problem {

Join::Join(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 3 elements expected on the board:
    // * TMP: list ( empty )
    // * L: list ( at least 2 elements )
    // * R: list ( at least 2 elements )
    
    state::NodeSet* lists = s->clone_nodes();
    lists->filter_by_no_parent();
    if (lists->size() != 3) { throw std::runtime_error("3 elements are expected on the table"); }
    
    lists->filter_by_type_lists();
    
    L = lists->remove_single_list_by_size_range(2, -1);
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 elements"); }
    
    R = lists->remove_single_list_by_size_range(2, -1);
    if (!R) { throw std::runtime_error("missing 1 list with at least 2 elements"); }
    
    TMP = lists->remove_single_list_by_size_range(0, 0);
    if (!TMP) { throw std::runtime_error("missing 1 empty list"); }
    
    /***/
    /* -- Prepare return list ids -- */
    /***/
    
    // items from R plus items from L
    BOOST_FOREACH(state::Node *n, *(R->children())) {
        _ids->push_back(n->id());
    }
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        _ids->push_back(n->id());
    }
}

rule::RuleSet* Join::create_rules() {
    rule::RuleSet* rules = new rule::RuleSet();
    
    // 1. move all the elements from L to TMP
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        D(("node: %s, from: %s, to: %s", n->id().c_str(), L->id().c_str(), TMP->id().c_str() ));
        rules->add(new rule::PopPush(n->id(), L->id(), TMP->id()));
    }
    
    // 2. move the same elements from tmp to R
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        D(("node: %s, from: %s, to: %s", n->id().c_str(), TMP->id().c_str(), R->id().c_str() ));
        rules->add(new rule::PopPush(n->id(), TMP->id(), R->id()));
    }
    
    return rules;
}

}}
