#ifndef __VESTIGE_RULE_CREATE_HPP
#define __VESTIGE_RULE_CREATE_HPP

#include "Rule.hpp"
#include "../action/Create.hpp"

namespace vestige {
namespace rule {

class Create : public Rule
{
    protected:
    public:
        Create(std::string node, std::string clause);
        
        virtual int valid(action::Action* action);
        virtual std::string text();
};

}}

#endif
