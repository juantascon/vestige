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
    rule::RuleSet* rules = new rule::RuleSet();
    
    std::string TMP1_id = "L#1";
    std::string TMP2_id = "L#2";
    
    std::list<std::string>* TMP1_items = new std::list<std::string>();
    
    // 1. create two tmp lists
    rules->add(new rule::Create(TMP1_id, "compress(L) -> compress(L,[],[])."));
    rules->add(new rule::Create(TMP2_id, "compress(L) -> compress(L,[],[])."));
    
    // 2. move all the elements from L to TMP1 minus adjacent repeated items
    state::Item* last = NULL;
    BOOST_REVERSE_FOREACH(state::Node* n, *(L->children())) {
        if ( !last || last->value() != dynamic_cast<state::Item*>(n)->value() ) {
            rules->add(new rule::PopPush(n->id(), L->id(), TMP1_id, "compress([I|L],T,P) -> compress(L,[I|T],P)."));
            TMP1_items->push_front(n->id());
        } else {
            rules->add(new rule::Discard(n->id(), "compress([I|L],[I|T],P) -> compress(L,[I|T],P);"));
        }
        
        last = dynamic_cast<state::Item*>(n);
    }
    
    // 3. move the same elements from TMP1 to TMP2
    BOOST_FOREACH(std::string id, *TMP1_items) {
        rules->add(new rule::PopPush(id, TMP1_id, TMP2_id, "compress([],[I|T],P) -> compress([],T,[I|P]);"));
    }
    
    // 4. delete L and TMP1
    rules->add(new rule::Discard(L->id(), "compress([],[],P) -> P;"));
    rules->add(new rule::Discard(TMP1_id, "compress([],[],P) -> P;"));
    
    return rules;
}

}}
