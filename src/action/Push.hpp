#ifndef __VESTIGE_ACTION_PUSH_HPP
#define __VESTIGE_ACTION_PUSH_HPP

#include "Action.hpp"

namespace vestige {
namespace action {

class Push : public Action
{
    protected:
        state::Node* _into;
        
    public:
        Push(state::Node* node, state::Node* into);
        
        state::Node* into();
        
        std::string text();
};

}}

#endif
