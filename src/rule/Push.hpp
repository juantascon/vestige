#ifndef __VESTIGE_RULE_PUSH_HPP
#define __VESTIGE_RULE_PUSH_HPP

#include "Move.hpp"
#include "../action/Push.hpp"

namespace vestige {
namespace rule {

class Push : public Move
{
    protected:
        std::string _into;
        
    public:
        Push(std::string node, std::string into);
        
        virtual int valid(action::Action* action);
        virtual std::string text();
};

}}

#endif
