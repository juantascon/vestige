#include "Compress.hpp"

namespace vestige {
namespace problem {

Compress::Compress(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 1 element expected on the board:
    // * L: list ( at least 2 elements )
    
    state::NodeSet* nodes = s->clone_nodes();
    nodes->filter_by_no_parent();
    if (nodes->size() != 1) { throw std::runtime_error("1 list is expected"); }
    
    L = nodes->remove_single_list_by_size_range(2, (std::numeric_limits<int>::max)());
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 items"); }
    
    /***/
    /* -- Prepare return list ids -- */
    /***/
    
    // items from L minus adjacent repeated items
    state::Item* last = NULL;
    BOOST_REVERSE_FOREACH(state::Node* n, *(L->children())) {
        if (!last || last->value() != dynamic_cast<state::Item*>(n)->value() ) {
            _ids->push_front(n->id());
        }
        
        last = dynamic_cast<state::Item*>(n);
    }
}

rule::RuleSet* Compress::create_rules() {
    std::string T_id = "L#1";
    std::string P_id = "L#2";
    std::string last_id = "";
    
    rule::RuleSet* rules = new rule::RuleSet();
    rule::Names* names = new rule::Names();
    
    std::list<std::string>* T_items = new std::list<std::string>();
    
    // 1. create two tmp lists
    (*names)[L->id()] = "L";
    rules->add(new rule::Rule(new rule::Create(T_id), names->clone(), "compress(L) -> compress(L,[],[])."));
    rules->add(new rule::Rule(new rule::Create(P_id), names->clone(), "compress(L) -> compress(L,[],[])."));
    
    (*names)[T_id] = "T";
    (*names)[P_id] = "P";
    
    // 2. move all the elements from L to T minus adjacent repeated items
    state::Item* last = NULL;
    BOOST_REVERSE_FOREACH(state::Node* n, *(L->children())) {
        (*names)[n->id()] = "I";
        if ( !last || last->value() != dynamic_cast<state::Item*>(n)->value() ) {
            (*names)[last_id] = "";
            rules->add(new rule::Rule(new rule::PopPush(n->id(), L->id(), T_id), names->clone(),
                                      "compress([I|L],T,P) -> compress(L,[I|T],P)."));
            T_items->push_front(n->id());
        } else {
            rules->add(new rule::Rule(new rule::Discard(n->id()), names->clone(),
                                      "compress([I|L],[I|T],P) -> compress(L,[I|T],P);"));
        }
        
        last_id = n->id();
        last = dynamic_cast<state::Item*>(n);
    }
    
    // 3. move the same elements from T to P
    BOOST_FOREACH(std::string id, *T_items) {
        (*names)[id] = "I";
        (*names)[last_id] = "";
        last_id = id;
        rules->add(new rule::Rule(new rule::PopPush(id, T_id, P_id), names->clone(),
                                  "compress([],[I|T],P) -> compress([],T,[I|P]);"));
    }
    
    // 4. delete L and T
    (*names)[last_id] = "";
    rules->add(new rule::Rule(new rule::Discard(L->id()), names->clone(), "compress([],[],P) -> P;"));
    rules->add(new rule::Rule(new rule::Discard(T_id), names->clone(), "compress([],[],P) -> P;"));
    
    return rules;
}

}}
