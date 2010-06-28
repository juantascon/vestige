#include "Join.hpp"

namespace vestige {
namespace problem {

Join::Join(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 2 elements expected on the board:
    // * L: list ( at least 2 elements )
    // * M: list ( at least 2 elements )
    
    state::NodeSet* lists = s->clone_nodes();
    lists->filter_by_no_parent();
    if (lists->size() != 2) { throw std::runtime_error("2 lists are expected"); }
    
    lists->filter_by_type_lists();
    
    M = lists->remove_single_list_by_size_range(2, -1);
    if (!M) { throw std::runtime_error("missing 1 list with at least 2 items"); }
    
    L = lists->remove_single_list_by_size_range(2, -1);
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 items"); }
    
    /***/
    /* -- Prepare return list ids -- */
    /***/
    
    // items from M plus items from L
    BOOST_FOREACH(state::Node *n, *(M->children())) {
        _ids->push_back(n->id());
    }
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        _ids->push_back(n->id());
    }
}

rule::RuleSet* Join::create_rules() {
    std::string T_id = "L#2";
    std::string last_id = "";
    
    rule::RuleSet* rules = new rule::RuleSet();
    rule::Names* names = new rule::Names();
    
    // 1. create the T list
    (*names)[L->id()] = "M";
    (*names)[M->id()] = "L";
    rules->add(new rule::Rule(new rule::Create(T_id), names->clone(), "join(L,M) -> join(L,M,[])."));
    
    (*names)[T_id] = "T";
    // 2. move all the elements from L to T
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        (*names)[n->id()] = "I";
        (*names)[last_id] = "";
        last_id = n->id();
        rules->add(new rule::Rule(new rule::PopPush(n->id(), L->id(), T_id), names->clone(),
                                  "join(L,[I|M],T) -> join(L,M,[I|T]);"));
    }
    
    // 3. move the same elements from T to M
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        (*names)[n->id()] = "I";
        rules->add(new rule::Rule(new rule::PopPush(n->id(), T_id, M->id()), names->clone(),
                                  "join(L,[],[I|T]) -> join([I|L],[],T);"));
        
        (*names)[last_id] = "";
        last_id = n->id();
    }
    
    // 4. delete L and T lists
    (*names)[last_id] = "";
    rules->add(new rule::Rule(new rule::Discard(T_id), names->clone(), "join(L,[],[]) -> L."));
    rules->add(new rule::Rule(new rule::Discard(L->id()), names->clone(), "join(L,[],[]) -> L."));
    
    return rules;
}

}}
