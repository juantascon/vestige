#include "InsertionSort.hpp"

namespace vestige {
namespace problem {

InsertionSort::InsertionSort(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 1 element expected on the board:
    // * L: list ( at least 3 elements )
    
    state::NodeSet* lists = s->clone_nodes();
    lists->filter_by_no_parent();
    if (lists->size() != 1) { throw std::runtime_error("1 list is expected"); }
    
    lists->filter_by_type_lists();
    
    L = lists->remove_single_list_by_size_range(3, -1);
    if (!L) { throw std::runtime_error("missing 1 list with at least 3 items"); }
    
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
    
    std::string DSC_id = "L#1";
    std::string ASC_id = "L#2";

    rules->add(new rule::Create(ASC_id));
    rules->add(new rule::Create(DSC_id));
    
    state::NodeSet* Ll = L->children()->clone();
    
    // discarded items
    //std::list<std::string>* TMP1_items = new std::list<std::string>();
    
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
    
    /*while(DSCl->size() != 0 || DSCl->size() != 0) {
        LTop = Ll->back();
        DSCTop = DSCl->back();
        ASCTop = ASCl->back();

        // f([TopL|RestL], [], []) -> f(RestL, [TopL], []);
        if ( !DSCTop && !ASCTop) {
            Ll->pop_back();
            DSCl->push_back(LTop);
            rules->add(new rule::PopPush(LTop->id(), L->id(), DSC->id()));
            continue;
            }*/
        
        // TODO: continuar aqui
        /*if ( !ASCTop && LTop) {
            Ll->pop_back();
            boost::lexical_cast<int>(dynamic_cast<state::Item*>()->value());
            DSCl->push_back(LTop);
            rules->add(new rule::PopPush(LTop->id(), L->id(), DSC->id()));
            continue;
            }*/
        
    //break;
    // }
    
    return rules;
}

}}
