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
    D(("hola"));
    rule::RuleSet* rules = new rule::RuleSet();
    
    std::string X_id = L->id();
    std::string D_id = "L#1";
    std::string A_id = "L#2";
    
    std::list<std::string>* D_ids = new std::list<std::string>();
    std::list<std::string>* A_ids = new std::list<std::string>();
    
    rules->add(new rule::Create(A_id));
    rules->add(new rule::Create(D_id));
    
    state::NodeSet* X = L->children()->clone();
    state::NodeSet* D = new state::NodeSet();
    state::NodeSet* A = new state::NodeSet();

    /*
      f(L) -> f(L, [], []).
      
      f(X=[I|L], D, []) -> f(L, D, [I]);
      
      f(X=[I|L], D, A=[AI|AL]) when (I < AI) -> f(X, [AI|D], AL);
      
      f(X=[I|L], [], A=[AI|AL]) when (I > AI) -> f(L, [], [I|A]);
      f(X=[I|L], D=[DI|DL], A=[AI|AL]) when (I > AI) and (I < DI) -> f(L, D, [I|A]);
      f(X=[I|L], D=[DI|DL], A=[AI|AL]) when (I > AI) and (I > DI) -> f(X, DL, [DI|A]);
      
      f([], D=[DI|DL], A=[AI|AL]) -> f([], DL, [DI|A]);
      f([], [], AL) -> AL.
    */
    
    while(true) {
        state::Item* I = X->size() > 0 ? dynamic_cast<state::Item*>(X->back()) : NULL;
        state::Item* AI = A->size() > 0 ? dynamic_cast<state::Item*>(A->back()) : NULL;
        state::Item* DI = D->size() > 0 ? dynamic_cast<state::Item*>(D->back()) : NULL;
        
        if (X->size() == 0) {
            if (D->size() != 0) {
                D(("poppush1"));
                rules->add(new rule::PopPush( DI->id(), D_id, A_id ));
                A->push_back(DI);
                D->pop_back();
                continue;
            }
            
            if (D->size() == 0) {
                D(("discard"));
                rules->add(new rule::Discard(X_id));
                rules->add(new rule::Discard(D_id));
                break;
            }
        }
        
        if (A->size() == 0) {
            D(("poppush2"));
            rules->add(new rule::PopPush( I->id(), X_id, A_id ));
            A->push_back(I);
            X->pop_back();
            continue;
        }
        
        if (I->ivalue() < AI->ivalue()) {
            D(("poppush3"));
            rules->add(new rule::PopPush( AI->id(), A_id, D_id ));
            D->push_back(AI);
            A->pop_back();
            continue;
        }
        
        if (I->ivalue() > AI->ivalue()) {
            if (D->size() == 0) {
                D(("poppush4"));
                rules->add(new rule::PopPush( I->id(), X_id, A_id ));
                A->push_back(I);
                X->pop_back();
                continue;
            }
            if (I->ivalue() < DI->ivalue()) {
                D(("poppush5"));
                rules->add(new rule::PopPush( I->id(), X_id, A_id ));
                A->push_back(I);
                X->pop_back();
                continue;
            }
            if (I->ivalue() > DI->ivalue()) {
                D(("poppush6"));
                rules->add(new rule::PopPush( DI->id(), D_id, A_id ));
                A->push_back(DI);
                D->pop_back();
                continue;
            }
        }
    }
    
    return rules;
}

}}
