#ifndef __VESTIGE_RULE_POP_HPP
#define __VESTIGE_RULE_POP_HPP

#include "Rule.hpp"
#include "../action/Pop.hpp"

namespace vestige {
namespace rule {

class Pop : public Rule
{
    protected:
        std::string _from;
        
    public:
        Pop(std::string node, std::string from, std::string clause);
        
        virtual int valid(action::Action* action);
        virtual std::string text();
};

}}

#endif
