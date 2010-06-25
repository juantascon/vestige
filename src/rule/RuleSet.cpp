#include "RuleSet.hpp"

namespace vestige {
namespace rule {

RuleSet::RuleSet() : Rule::List() {
    current = this->begin();
}

std::string RuleSet::text() {
    std::string ret = "RULES: [[ ";
    
    BOOST_FOREACH(rule::Rule *r, *this) {
        ret += r->text() + " ";
    }
    
    ret += "]]";
    
    return ret;
}

void RuleSet::add(Rule* rule) {
    this->push_back(rule);
    current = this->begin();
}

int RuleSet::verify(action::Action* action) {
    if ( (*current)->valid(action) ) {
        D(( "RULE: [[ %s ]] OK", (*current)->text().c_str() ));
        action->valid_rules = 1;
        last = *current;
        ++current;
        return 1;
    }
    D(( "RULE: [[ %s ]] FAIL", (*current)->text().c_str() ));
    return 0;
}

void RuleSet::verify(action::ActionSet* as) {
    for (int i = 0; i < as->size(); i++) {
        BOOST_FOREACH(action::Action *a, *as) {
            if (verify(a)) { break; }
        }
    }
}

std::string RuleSet::clause() {
    return last->clause();
}

}}
