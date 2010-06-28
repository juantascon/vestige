#ifndef __VESTIGE_RULE_CREATE_HPP
#define __VESTIGE_RULE_CREATE_HPP

#include "Move.hpp"
#include "../action/Create.hpp"

namespace vestige {
namespace rule {

class Create : public Move
{
    protected:
    public:
        Create(std::string node);
        
        virtual int valid(action::Action* action);
        virtual std::string text();
};

}}

#endif
