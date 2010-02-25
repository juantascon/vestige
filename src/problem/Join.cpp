#include "Join.hpp"

namespace vestige {
namespace problem {

Join::Join(state::State* s) : ListProblem()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 3 items expected on the board:
    // * TMP: empty list
    // * L: list with at least 2 elements
    // * R: list with at least 2 elements
    
    state::NodeSet* lists = s->nodes();
    lists->filter_by_no_parent();
    if (lists->size() != 3) { throw std::runtime_error("3 items are expected on the table"); }
    
    lists->filter_by_type(0, 1);
    if (lists->size() != 3) { throw std::runtime_error("3 lists are expected on the table"); }
    
    TMP = lists->filter_single_by_size_range(0, 0);
    if (!TMP) { throw std::runtime_error("missing 1 empty list"); }
    
    L = lists->filter_single_by_size_range(2, (std::numeric_limits<int>::max)());
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 elements"); }
    
    R = lists->filter_single_by_size_range(2, (std::numeric_limits<int>::max)());
    if (!R) { throw std::runtime_error("missing 1 list with at least 2 elements"); }
    
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
