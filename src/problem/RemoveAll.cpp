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
    rule::RuleSet* rules = new rule::RuleSet();
    
    std::string TMP1_id = "L#1";
    std::string TMP2_id = "L#2";
    
    // 1. create two tmp lists
    rules->add(new rule::Create(TMP1_id, "remall(L,E) -> remall(L,E,[],[])."));
    rules->add(new rule::Create(TMP2_id, "remall(L,E) -> remall(L,E,[],[])."));
    
    // 2. move all the elements from L to TMP1 minus items equals to E
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        if ( E->value() != dynamic_cast<state::Item*>(n)->value() ) {
            rules->add(new rule::PopPush(n->id(), L->id(), TMP1_id, "remall([I|L],E,T,P) -> remall(L,E,[I|T],P)."));
        } else {
            rules->add(new rule::Discard(n->id(), "remall([E|L],E,T,P) -> remall(L,E,T,P);"));
        }
    }
    
    // 3. move the same elements from TMP1 to TMP2
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        if ( E->value() != dynamic_cast<state::Item*>(n)->value() ) {
            rules->add(new rule::PopPush(n->id(), TMP1_id, TMP2_id, "remall([],E,[I|T],P) -> remall([],E,T,[I|P]);"));
        }
    }
    
    // 4. delete E L and TMP1
    rules->add(new rule::Discard(E->id(), "remall([],_,[],P) -> P;"));
    rules->add(new rule::Discard(L->id(), "remall([],_,[],P) -> P;"));
    rules->add(new rule::Discard(TMP1_id, "remall([],_,[],P) -> P;"));

    
    return rules;
}

}}
