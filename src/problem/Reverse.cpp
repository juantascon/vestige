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
    std::string R_id = "L#1";
    
    rule::RuleSet* rules = new rule::RuleSet();
    rule::Names* names = new rule::Names();
    
    (*names)[L->id()] = "L";
    (*names)[R_id] = "T";
    rules->add(new rule::Rule(new rule::Create(R_id), names->clone(), "rev(L) -> rev(L,[])."));
    
    // Generate a reversed order of poppush instructions
    std::string prev = "";
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        (*names)[n->id()] = "I";
        (*names)[prev] = "";
        rules->add(new rule::Rule(new rule::PopPush(n->id(), L->id(), R_id), names->clone(), "rev([I|L],T) -> rev(L,[I|T]);"));
        
        prev = n->id();
    }
    
    (*names)[prev] = "";
    rules->add(new rule::Rule(new rule::Discard(L->id()), names->clone(), "rev([],T) -> T."));
    
    return rules;
}

}}
