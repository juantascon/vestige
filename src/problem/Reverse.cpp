#include "Reverse.hpp"

namespace vestige {
namespace problem {

Reverse::Reverse(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 1 element expected on the board:
    // * L: list ( at least 2 elements )
    
    state::NodeSet* lists = s->clone_nodes();
    lists->filter_by_no_parent();
    if (lists->size() != 1) { throw std::runtime_error("1 list is expected"); }
    
    L = lists->remove_single_list_by_size_range(2, -1);
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 items"); }
    
    /***/
    /* -- Prepare return list ids -- */
    /***/
    // store an inverse order list of L items ids
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        _ids->push_back(n->id());
    }
}

rule::RuleSet* Reverse::create_rules() {
    rule::RuleSet* rules = new rule::RuleSet();
    rule::Rule* r = 0;
    
    std::string R_id = "L#1";
    
    r = new rule::Create(R_id);
    r->set_clause("rev(L) -> rev(L,[]).");
    rules->add(r);
    
    // Generate a reversed order of poppush instructions
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        r = new rule::PopPush(n->id(), L->id(), R_id);
        r->set_clause("rev([I|L],T) -> rev(L,[I|T]);");
        rules->add(r);
    }

    r = new rule::Discard(L->id());
    r->set_clause("rev([],T) -> T.");
    rules->add(r);
    
    return rules;
}

}}
