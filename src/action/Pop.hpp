#ifndef __VESTIGE_ACTION_POP_HPP
#define __VESTIGE_ACTION_POP_HPP

#include "Action.hpp"

namespace vestige {
namespace action {

class Pop : public Action
{
    protected:
        state::Node* from;
        
    public:
        Pop(state::Node* item, state::Node* from);
        
        std::string from_id();
        
        virtual std::string text();
};

}}

#endif
