#include "InsertionSort.hpp"

namespace vestige {
namespace problem {

InsertionSort::InsertionSort(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 3 elements expected on the board:
    // * L: list ( at least 3 elements )
    // * DSC: list ( empty )
    // * ASC: list ( empty )
    
    state::NodeSet* lists = s->clone_nodes();
    lists->filter_by_no_parent();
    if (lists->size() != 3) { throw std::runtime_error("3 elements are expected on the table"); }
    
    lists->filter_by_type_lists();
    
    L = lists->remove_single_list_by_size_range(3, -1);
    if (!L) { throw std::runtime_error("missing 1 list with at least 3 elements"); }
    
    DSC = lists->remove_single_list_by_size_range(0, 0);
    if (!DSC) { throw std::runtime_error("missing 1 empty list"); }
    
    ASC = lists->remove_single_list_by_size_range(0, 0);
    if (!ASC) { throw std::runtime_error("missing 1 empty list"); }
    
    /***/
    /* -- Prepare return list ids -- */
    /***/
    
    state::NodeSet* Lns = L->children()->clone();
    Lns->sort_by_item_value();
    
    BOOST_FOREACH(state::Node *n, *Lns) {
        _ids->push_back(n->id());
    }
}

rule::RuleSet* InsertionSort::create_rules() {
    rule::RuleSet* rules = new rule::RuleSet();
    
    state::NodeSet* Ll = L->children()->clone();
    state::NodeSet* DSCl = DSC->children()->clone();
    state::NodeSet* ASCl = ASC->children()->clone();
    
    state::Node* LTop = 0;
    state::Node* DSCTop = 0;
    state::Node* ASCTop = 0;
    
    /*
      %state 1
      
      f([TopL|RestL], [TopDSC|RestDSC], []) when TopL < TopDSC ->  f(RestL, [TopL|TopDSC|RestDSC], []);
      %state 2, 3, 4
      
      f([TopL|RestL], [TopDSC|RestDSC], []) when TopL > TopDSC ->  f([TopL|RestL], RestDSC, [TopDSC]);
      %state 5

      f([TopL|RestL], [TopDSC|RestDSC], [TopASC|RestASC]) when TopL > TopDSC -> f([TopL|RestL], RestDSC, [TopDSC|[TopASC|RestASC]]);
      %state 6

      f([TopL|RestL], [TopDSC|RestDSC], [TopASC|RestASC]) when TopL < TopASC ->  f([TopL|RestL], [TopASC|TopDSC|RestDSC], RestASC);
      %state 7, 8

      f([TopL|RestL], [TopDSC|RestDSC], [TopASC|RestASC]) when TopL > TopASC ->  f(RestL, [TopL|TopDSC|RestDSC], [TopASC|RestASC]);
      %state 9

      f([], [TopDSC|RestDSC], [TopASC|RestASC]) when TopL < TopASC ->  f([], RestDSC, [TopDSC|TopASC|RestASC]);
      %state 10, 11, 12

      f([], [], ASC) -> ASC.
      %state 13

      f([TopL|RestL],               [], [TopASC|RestASC])                    -> f(       RestL,                    [TopL],         [TopASC|RestASC]);
      %added
    */
    
    while(DSCl->size() != 0 || DSCl->size() != 0) {
        LTop = Ll->back();
        DSCTop = DSCl->back();
        ASCTop = ASCl->back();

        // f([TopL|RestL], [], []) -> f(RestL, [TopL], []);
        if ( !DSCTop && !ASCTop) {
            Ll->pop_back();
            DSCl->push_back(LTop);
            rules->add(new rule::PopPush(LTop->id(), L->id(), DSC->id()));
            continue;
        }
        
        // TODO: continuar aqui
        if ( !ASCTop && LTop) {
            Ll->pop_back();
            boost::lexical_cast<int>(dynamic_cast<state::Item*>()->value());
            DSCl->push_back(LTop);
            rules->add(new rule::PopPush(LTop->id(), L->id(), DSC->id()));
            continue;
        }
        
        break;
    }
    
    return rules;
}

}}
