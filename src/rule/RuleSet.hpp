#ifndef __VESTIGE_RULE_RULESET_HPP
#define __VESTIGE_RULE_RULESET_HPP

#include "Rule.hpp"

namespace vestige {
namespace rule {

class RuleSet
{
    protected:
        Rule::Vector::iterator current;
        Rule::Vector* items;
        
    public:
        RuleSet();
        
        void add(Rule* rule);
        int apply(action::Action* action);
};

}}

#endif
