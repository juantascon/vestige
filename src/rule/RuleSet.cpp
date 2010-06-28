#include "RuleSet.hpp"

namespace vestige {
namespace rule {

RuleSet::RuleSet() : Rule::List() {
    iter = this->begin();
}

void RuleSet::sync() {
    _current = *iter;
}

void RuleSet::add(Rule* rule) {
    this->push_back(rule);
    iter = this->begin();
}

std::string RuleSet::clause() {
    return _current->clause();
}

void RuleSet::set_labels(state::State* s) {
    return (*iter)->names()->set_labels(s);
}

int RuleSet::verify(action::Action* action) {
    if ( (*iter)->move()->valid(action) ) {
        D(( "RULE: [[ %s ]] OK", (*iter)->text().c_str() ));
        action->valid_rules = 1;
        ++iter;
        return 1;
    }
    D(( "RULE: [[ %s ]] FAIL", (*iter)->text().c_str() ));
    return 0;
}

void RuleSet::verify(action::ActionSet* as) {
    for (int i = 0; i < as->size(); i++) {
        BOOST_FOREACH(action::Action *a, *as) {
            if (verify(a)) { break; }
        }
    }
}

std::string RuleSet::text() {
    std::string ret = "RULES: [[ ";
    
    BOOST_FOREACH(rule::Rule *r, *this) {
        ret += r->text() + " ";
    }
    
    ret += "]]";
    
    return ret;
}

}}
