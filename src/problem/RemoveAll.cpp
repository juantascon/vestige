#include "RemoveAll.hpp"

namespace vestige {
namespace problem {

RemoveAll::RemoveAll(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 2 elements expected on the board:
    // * L: list ( at least 2 elements )
    // * E: item ( element to be removed )
    
    state::NodeSet* nodes = s->clone_nodes();
    nodes->filter_by_no_parent();
    if (nodes->size() != 2) { throw std::runtime_error("1 list and 1 item are expected"); }
    
    L = nodes->remove_single_list_by_size_range(2, (std::numeric_limits<int>::max)());
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 items"); }
    
    E = nodes->remove_single_item();
    if (!E) { throw std::runtime_error("missing 1 item"); }
    
    /***/
    /* -- Prepare return list ids -- */
    /***/
    
    // items from L minus items equals to E
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        if ( E->value() != dynamic_cast<state::Item*>(n)->value() ) {
            _ids->push_back(n->id());
        }
    }
}

rule::RuleSet* RemoveAll::create_rules() {
    std::string T_id = "L#1";
    std::string P_id = "L#2";
    std::string last_id = "";
    
    rule::RuleSet* rules = new rule::RuleSet();
    rule::Names* names = new rule::Names();
    
    // 1. create two tmp lists
    (*names)[L->id()] = "L";
    (*names)[E->id()] = "E";
    rules->add(new rule::Rule(new rule::Create(T_id), names->clone(), "remall(L,E) -> remall(L,E,[],[])."));
    rules->add(new rule::Rule(new rule::Create(P_id), names->clone(), "remall(L,E) -> remall(L,E,[],[])."));
    
    (*names)[T_id] = "T";
    (*names)[P_id] = "P";
    
    // 2. move all the elements from L to T minus items equals to E
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        (*names)[last_id] = "";
        last_id = n->id();
        if ( E->value() != dynamic_cast<state::Item*>(n)->value() ) {
            (*names)[n->id()] = "I";
            rules->add(new rule::Rule(new rule::PopPush(n->id(), L->id(), T_id), names->clone(),
                                      "remall([I|L],E,T,P) -> remall(L,E,[I|T],P)."));
        } else {
            (*names)[n->id()] = "E";
            rules->add(new rule::Rule(new rule::Discard(n->id()), names->clone(),
                                      "remall([E|L],E,T,P) -> remall(L,E,T,P);"));
        }
    }
    
    // 3. move the same elements from T to P
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        if ( E->value() == dynamic_cast<state::Item*>(n)->value() ) {
            continue;
        }
        (*names)[n->id()] = "I";
        (*names)[last_id] = "";
        last_id = n->id();
        rules->add(new rule::Rule(new rule::PopPush(n->id(), T_id, P_id), names->clone(),
                                  "remall([],E,[I|T],P) -> remall([],E,T,[I|P]);"));
    }
    
    // 4. delete E L and T
    (*names)[last_id] = "";
    rules->add(new rule::Rule(new rule::Discard(E->id()), names->clone(), "remall([],_,[],P) -> P;"));
    rules->add(new rule::Rule(new rule::Discard(L->id()), names->clone(), "remall([],_,[],P) -> P;"));
    rules->add(new rule::Rule(new rule::Discard(T_id), names->clone(), "remall([],_,[],P) -> P;"));
    
    return rules;
}

}}
