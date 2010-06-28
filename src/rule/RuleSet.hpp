#ifndef __VESTIGE_RULE_RULESET_HPP
#define __VESTIGE_RULE_RULESET_HPP

#include "Rule.hpp"
#include "Move.hpp"
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
        
        void add(Rule* rule);
        std::string clause();
        
        void verify(action::ActionSet* as);
        int verify(action::Action* action);
        
        std::string text();
};


}}

#endif
