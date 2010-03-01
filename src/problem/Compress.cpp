#include "Compress.hpp"

namespace vestige {
namespace problem {

Compress::Compress(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 4 elements expected on the board:
    // * L: list ( at least 2 elements )
    // * TMP1: list ( empty )
    // * TMP2: list ( empty )
    // * E: item ( element to be removed )
    
    state::NodeSet* nodes = s->clone_nodes();
    nodes->filter_by_no_parent();
    if (nodes->size() != 3) { throw std::runtime_error("4 elements are expected on the table"); }
    
    L = nodes->remove_single_list_by_size_range(2, (std::numeric_limits<int>::max)());
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 elements"); }
    
    TMP2 = nodes->remove_single_list_by_size_range(0, 0);
    if (!TMP2) { throw std::runtime_error("missing 1 empty list"); }
    
    TMP1 = nodes->remove_single_list_by_size_range(0, 0);
    if (!TMP1) { throw std::runtime_error("missing 1 empty list"); }
    
    /***/
    /* -- Prepare return list ids -- */
    /***/
    
    // items from L minus adjacent repeated items
    state::Item* last = NULL;
    BOOST_FOREACH(state::Node* n, *(L->children())) {
        if (!last || last->value() != dynamic_cast<state::Item*>(n)->value() ) {
            _ids->push_back(n->id());
        }
        
        last = dynamic_cast<state::Item*>(n);
    }
}

rule::RuleSet* Compress::create_rules() {
    rule::RuleSet* rules = new rule::RuleSet();
    
    // 1. move all the elements from L to TMP1 minus adjacent repeated items
    state::Item* last = NULL;
    BOOST_REVERSE_FOREACH(state::Node* n, *(L->children())) {
        if ( !last || last->value() != dynamic_cast<state::Item*>(n)->value() ) {
            rules->add(new rule::PopPush(n->id(), L->id(), TMP1->id()));
        } else {
            rules->add(new rule::Discard(n->id()));
        }

        last = dynamic_cast<state::Item*>(n);
    }
    
    // 2. move the same elements from TMP1 to TMP2
    //TODO: arreglar el poppush de aqui
    last = NULL;
    BOOST_FOREACH(state::Node* n, *(L->children())) {
        if ( !last || last->value() != dynamic_cast<state::Item*>(n)->value() ) {
            rules->add(new rule::PopPush(n->id(), TMP1->id(), TMP2->id()));
        }
        
        last = dynamic_cast<state::Item*>(n);
    }
    
    return rules;
}

}}
