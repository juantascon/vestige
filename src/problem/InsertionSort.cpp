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
    std::string LL_id = L->id();
    std::string P_id = "L#1";
    std::string Q_id = "L#2";
    std::string last_id = "";
    
    rule::RuleSet* rules = new rule::RuleSet();
    rule::Names* names = new rule::Names();
    
    std::list<std::string>* P_ids = new std::list<std::string>();
    std::list<std::string>* Q_ids = new std::list<std::string>();

    (*names)[LL_id] = "L";
    rules->add(new rule::Rule(new rule::Create(Q_id), names->clone(), "isort(L) -> isort(L,[],[])."));
    rules->add(new rule::Rule(new rule::Create(P_id), names->clone(), "isort(L) -> isort(L,[],[])."));
    
    (*names)[P_id] = "P";
    (*names)[Q_id] = "Q";
    
    state::NodeSet* LL = L->children()->clone();
    state::NodeSet* P = new state::NodeSet();
    state::NodeSet* Q = new state::NodeSet();
    
    while(true) {
        state::Item* I = LL->size() > 0 ? dynamic_cast<state::Item*>(LL->back()) : NULL;
        state::Item* J = P->size() > 0 ? dynamic_cast<state::Item*>(P->back()) : NULL;
        state::Item* K = Q->size() > 0 ? dynamic_cast<state::Item*>(Q->back()) : NULL;
        
        if (LL->size() == 0 && P->size() == 0) {
            rules->add(new rule::Rule(new rule::Discard(LL_id), names->clone(), "isort([],[],Q) -> Q;"));
            rules->add(new rule::Rule(new rule::Discard(P_id), names->clone(), "isort([],[],Q) -> Q;"));
            break;
        }
        else if (LL->size() == 0 && J) {
            (*names)[J->id()] = "J";
            rules->add(new rule::Rule(new rule::PopPush( J->id(), P_id, Q_id), names->clone(),
                           "isort([],[J|P],Q) -> isort([],P,[J|Q]);"));
            (*names)[J->id()] = "";
            P->pop_back();
            Q->push_back(J);
            continue;
        }
        else if (I && K && K->ivalue() > I->ivalue()) {
            (*names)[K->id()] = "K";
            (*names)[I->id()] = "I<";
            rules->add(new rule::Rule(new rule::PopPush( K->id(), Q_id, P_id), names->clone(), 
                           "isort([I|L],P,[K|Q]) when I<K -> isort([I|L],[K|P],Q);"));
            (*names)[K->id()] = "";
            (*names)[I->id()] = "";
            Q->pop_back();
            P->push_back(K);
            continue;
        }
        else if (I && J && I->ivalue() > J->ivalue()) {
            (*names)[I->id()] = "I>";
            (*names)[J->id()] = "J";
            rules->add(new rule::Rule(new rule::PopPush( J->id(), P_id, Q_id), names->clone(),
                           "isort([I|L],[J|P],Q) when I>J -> isort([I|L],P,[J|Q]);" ));
            (*names)[I->id()] = "";
            (*names)[J->id()] = "";
            Q->push_back(J);
            P->pop_back();
            continue;
        }
        else if (I) {
            (*names)[I->id()] = "I";
            rules->add(new rule::Rule(new rule::PopPush( I->id(), LL_id, Q_id), names->clone(),
                           "isort([I|L],P,Q) -> isort(L,P,[I|Q])."));
            (*names)[I->id()] = "";
            Q->push_back(I);
            LL->pop_back();
            continue;
        }
    }
    
    return rules;
}

}}
