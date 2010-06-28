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
    
    std::string LL_id = L->id();
    std::string P_id = "L#1";
    std::string Q_id = "L#2";
    
    std::list<std::string>* P_ids = new std::list<std::string>();
    std::list<std::string>* Q_ids = new std::list<std::string>();
    
    rules->add(new rule::Rule(new rule::Create(Q_id), "isort(L) -> isort(L,[],[])."));
    rules->add(new rule::Rule(new rule::Create(P_id), "isort(L) -> isort(L,[],[])."));
    
    state::NodeSet* LL = L->children()->clone();
    state::NodeSet* P = new state::NodeSet();
    state::NodeSet* Q = new state::NodeSet();
    
    while(true) {
        state::Item* I = LL->size() > 0 ? dynamic_cast<state::Item*>(LL->back()) : NULL;
        state::Item* J = P->size() > 0 ? dynamic_cast<state::Item*>(P->back()) : NULL;
        state::Item* K = Q->size() > 0 ? dynamic_cast<state::Item*>(Q->back()) : NULL;
        
        if (LL->size() == 0 && P->size() == 0) {
            rules->add(new rule::Rule(new rule::Discard(LL_id), "isort([],[],Q) -> Q;"));
            rules->add(new rule::Rule(new rule::Discard(P_id), "isort([],[],Q) -> Q;"));
            break;
        }
        else if (LL->size() == 0 && J) {
            rules->add(new rule::Rule(
                           new rule::PopPush( J->id(), P_id, Q_id),
                           "isort([],[J|P],Q) -> isort([],P,[J|Q]);"));
            P->pop_back();
            Q->push_back(J);
            continue;
        }
        else if (I && K && K->ivalue() > I->ivalue()) {
            rules->add(new rule::Rule(
                           new rule::PopPush( K->id(), Q_id, P_id),
                           "isort([I|L],P,[K|Q]) when K>I -> isort([I|L],[K|P],Q);"));
            Q->pop_back();
            P->push_back(K);
            continue;
        }
        else if (I && J && I->ivalue() > J->ivalue()) {
            rules->add(new rule::Rule(
                           new rule::PopPush( J->id(), P_id, Q_id),
                           "isort([I|L],[J|P],Q) when I>J -> isort([I|L],P,[J|Q]);" ));
            Q->push_back(J);
            P->pop_back();
            continue;
        }
        else if (I) {
            rules->add(new rule::Rule(
                           new rule::PopPush( I->id(), LL_id, Q_id),
                           "isort([I|L],P,Q) -> isort(L,P,[I|Q])."));
            Q->push_back(I);
            LL->pop_back();
            continue;
        }
    }
    
    return rules;
}

}}
