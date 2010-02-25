#include "RemoveFirst.hpp"

namespace vestige {
namespace problem {

RemoveFirst::RemoveFirst(state::State* s) : ListProblem()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 4 elements expected on the board:
    // * L: list ( at least 2 elements )
    // * TMP1: list ( empty )
    // * TMP2: list ( empty )
    // * E: item ( element to be removed )
    
    state::NodeSet* nodes = s->nodes();
    nodes->filter_by_no_parent();
    if (lists->size() != 4) { throw std::runtime_error("4 elements are expected on the table"); }
    
    state::NodeSet* lists = nodes->clone();
    lists->filter_by_type(0, 1);

    L = lists->filter_single_by_size_range(2, (std::numeric_limits<int>::max)());
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 elements"); }
    
    TMP1 = lists->filter_single_by_size_range(0, 0);
    if (!TMP1) { throw std::runtime_error("missing 1 empty list"); }
    
    TMP2 = lists->filter_single_by_size_range(0, 0);
    if (!TMP2) { throw std::runtime_error("missing 1 empty list"); }
    
    state::NodeSet* items = nodes->clone();
    items->filter_by_type(1, 0);
    E = items->back();
    if (!E) { throw std::runtime_error("missing 1 item"); }
    
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

rule::RuleSet* RemoveFirst::create_rules() {
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
