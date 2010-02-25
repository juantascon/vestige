#include "RuleSet.hpp"

namespace vestige {
namespace rule {

RuleSet::RuleSet() : Rule::List() {
    current = this->begin();
}

void RuleSet::add(Rule* rule) {
    this->push_back(rule);
    current = this->begin();
}

int RuleSet::apply(action::Action* action) {
    if ( (*current)->valid(action) ) {
        ++current;
        return 1;
    }
    
    action->alert("APPLY-RULE");
    return 0;
}

}}
