#include "Reverse.hpp"

namespace vestige {
namespace problem {

Reverse::Reverse(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 2 elements expected on the board:
    // * L: list ( at least 2 elements )
    // * R: list ( empty )
    
    state::NodeSet* lists = s->clone_nodes();
    lists->filter_by_no_parent();
    if (lists->size() != 2) { throw std::runtime_error("2 elements are expected on the table"); }
    
    lists->filter_by_type_lists();
    
    L = lists->remove_single_list_by_size_range(2, -1);
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 elements"); }
    
    R = lists->remove_single_list_by_size_range(0, 0);
    if (!R) { throw std::runtime_error("missing 1 empty list"); }

    /***/
    /* -- Prepare return list ids -- */
    /***/
    // store an inverse order list of L's items ids
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        _ids->push_back(n->id());
    }
}

rule::RuleSet* Reverse::create_rules() {
    rule::RuleSet* rules = new rule::RuleSet();

    // Generate a reversed order of poppush instructions
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        rules->add(new rule::PopPush(n->id(), L->id(), R->id()));
    }

    return rules;
}

}}
