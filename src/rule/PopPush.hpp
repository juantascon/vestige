#ifndef __VESTIGE_RULE_POPPUSH_HPP
#define __VESTIGE_RULE_POPPUSH_HPP

#include "Move.hpp"
#include "../action/PopPush.hpp"

namespace vestige {
namespace rule {

class PopPush : public Move
{
    protected:
        std::string _from;
        std::string _into;
        
    public:
        PopPush(std::string node, std::string from, std::string into);
        
        virtual int valid(action::Action* action);
        virtual std::string text();
};

}}

#endif
