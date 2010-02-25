#ifndef __VESTIGE_ACTION_INVALID_HPP
#define __VESTIGE_ACTION_INVALID_HPP

#include "Action.hpp"

namespace vestige {
namespace action {

class Invalid : public Action
{
    protected:
    public:
        Invalid(state::Node* item);
        
        virtual std::string text();
};

}}

#endif
