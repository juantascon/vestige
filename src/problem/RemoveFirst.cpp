#include "RemoveFirst.hpp"

namespace vestige {
namespace problem {

RemoveFirst::RemoveFirst(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 4 elements expected on the board:
    // * L: list ( at least 2 elements )
    // * TMP1: list ( empty )
    // * TMP2: list ( empty )
    // * E: item ( element to be removed )
    
    state::NodeSet* nodes = s->clone_nodes();
    nodes->filter_by_no_parent();
    if (nodes->size() != 4) { throw std::runtime_error("4 elements are expected on the table"); }
    
    L = nodes->remove_single_list_by_size_range(2, (std::numeric_limits<int>::max)());
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 elements"); }
    
    TMP1 = nodes->remove_single_list_by_size_range(0, 0);
    if (!TMP1) { throw std::runtime_error("missing 1 empty list"); }
    
    TMP2 = nodes->remove_single_list_by_size_range(0, 0);
    if (!TMP2) { throw std::runtime_error("missing 1 empty list"); }
    
    E = nodes->remove_single_item();
    if (!E) { throw std::runtime_error("missing 1 item"); }
    
    /***/
    /* -- Prepare return list ids -- */
    /***/
    
    // items from L minus items equals to E
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        state::Item* item = dynamic_cast<state::Item*>(n);
        if (E->value() != item->value()) {
            D(( "node: %s", n->id().c_str() ));
            _ids->push_back(n->id());
        }
    }
}

rule::RuleSet* RemoveFirst::create_rules() {
    rule::RuleSet* rules = new rule::RuleSet();
    
    // 1. move all the elements from L to TMP1 minus items equals to E
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        rules->add(new rule::PopPush(n->id(), L->id(), TMP1->id()));
    }
    
    // 2. move the same elements from TMP1 to TMP2
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        rules->add(new rule::PopPush(n->id(), TMP1->id(), TMP2->id()));
    }
    
    return rules;
}

}}
