#ifndef __VESTIGE_RULE_RULESET_HPP
#define __VESTIGE_RULE_RULESET_HPP

#include "Rule.hpp"

namespace vestige {
namespace rule {

class RuleSet : public Rule::List
{
    protected:
        RuleSet::iterator current;
        
    public:
        RuleSet();

        std::string text();
        void add(Rule* rule);
        int apply(action::Action* action);
};

}}

#endif
