#include "RuleSet.hpp"

namespace vestige {
namespace rule {

RuleSet::RuleSet() {
    nodes = new Rule::Vector();
    current = nodes->begin();
}

void RuleSet::add(Rule* rule) {
    nodes->push_back(rule);
    current = nodes->begin();
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
