#ifndef __VESTIGE_RULE_RULESET_HPP
#define __VESTIGE_RULE_RULESET_HPP

#include "Rule.hpp"
#include "../action/ActionSet.hpp"

namespace vestige {
namespace rule {

class RuleSet : public Rule::List
{
    protected:
        RuleSet::iterator current;
        Rule* last;
        
    public:
        RuleSet();
        
        std::string text();
        void add(Rule* rule);
        
        void verify(action::ActionSet* as);
        int verify(action::Action* action);
        
        std::string clause();
};

}}

#endif
