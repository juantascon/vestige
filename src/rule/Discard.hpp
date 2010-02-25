#ifndef __VESTIGE_RULE_DISCARD_HPP
#define __VESTIGE_RULE_DISCARD_HPP

#include "Rule.hpp"
#include "../action/Discard.hpp"

namespace vestige {
namespace rule {

class Discard : public Rule
{
    protected:
    public:
        Discard(std::string node);
        
        virtual int valid(action::Action* action);
        virtual std::string text();
};

}}

#endif
