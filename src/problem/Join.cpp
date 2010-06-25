#include "Join.hpp"

namespace vestige {
namespace problem {

Join::Join(state::State* s) : ListReturn()
{
    /***/
    /* -- Check initial state -- */
    /***/
    
    // exactly 2 elements expected on the board:
    // * L: list ( at least 2 elements )
    // * R: list ( at least 2 elements )
    
    state::NodeSet* lists = s->clone_nodes();
    lists->filter_by_no_parent();
    if (lists->size() != 2) { throw std::runtime_error("2 lists are expected"); }
    
    lists->filter_by_type_lists();
    
    R = lists->remove_single_list_by_size_range(2, -1);
    if (!R) { throw std::runtime_error("missing 1 list with at least 2 items"); }
    
    L = lists->remove_single_list_by_size_range(2, -1);
    if (!L) { throw std::runtime_error("missing 1 list with at least 2 items"); }
    
    /***/
    /* -- Prepare return list ids -- */
    /***/
    
    // items from R plus items from L
    BOOST_FOREACH(state::Node *n, *(R->children())) {
        _ids->push_back(n->id());
    }
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        _ids->push_back(n->id());
    }
}

rule::RuleSet* Join::create_rules() {
    rule::RuleSet* rules = new rule::RuleSet();
    rule::Rule* r = 0;
    
    std::string TMP_id = "L#2";
    
    // 1. create the TMP list
    r = new rule::Create(TMP_id);
    r->set_clause("join(L,M) -> join(L,M,[]).");
    rules->add(r);
    
    // 2. move all the elements from L to TMP
    BOOST_REVERSE_FOREACH(state::Node *n, *(L->children())) {
        r = new rule::PopPush(n->id(), L->id(), TMP_id);
        r->set_clause("join(L,[I|M],T) -> join(L,M,[I|T]);");
        rules->add(r);
    }
    
    // 3. move the same elements from tmp to R
    BOOST_FOREACH(state::Node *n, *(L->children())) {
        r = new rule::PopPush(n->id(), TMP_id, R->id());
        r->set_clause("join(L,[],[I|T]) -> join([I|L],[],T);");
        rules->add(r);
    }
    
    // 4. delete L and TMP lists
    r = new rule::Discard(TMP_id);
    r->set_clause("join(L,[],[]) -> L.");
    rules->add(r);
    r = new rule::Discard(L->id());
    r->set_clause("join(L,[],[]) -> L.");
    rules->add(r);
    
    return rules;
}

}}
