#ifndef __VESTIGE_RULE_RULESET_HPP
#define __VESTIGE_RULE_RULESET_HPP

#include "Rule.hpp"
#include "../action/ActionSet.hpp"

namespace vestige {
namespace rule {

class RuleSet : public Rule::List
{
    protected:
        // Moves and names are matched with iter but and clause with current
        RuleSet::iterator iter;
        Rule* _current;
        
    public:
        RuleSet();
        
        void add(Rule* rule);
        void sync();
        
        std::string clause();
        void set_labels(state::State* s);
        void verify(action::ActionSet* as);
        int verify(action::Action* action);
        
        std::string text();
};


}}

#endif
