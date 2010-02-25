#ifndef __VESTIGE_RULE_POP_HPP
#define __VESTIGE_RULE_POP_HPP

#include "Rule.hpp"
#include "../action/Pop.hpp"

namespace vestige {
namespace rule {

class Pop : public Rule
{
    protected:
        std::string from;
        
    public:
        Pop(std::string item, std::string from);
        
        virtual int valid(action::Action* action);
        virtual std::string text();
};

}}

#endif
