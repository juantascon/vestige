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

int RuleSet::apply(action::Action* action) {
    D(( "RULE: [[ %s ]]", (*current)->text().c_str() ));
    if ( (*current)->valid(action) ) {
        ++current;
        return 1;
    }
    
    action->alert("APPLY-RULE");
    return 0;
}

}}
