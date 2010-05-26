#ifndef __VESTIGE_ACTION_POP_HPP
#define __VESTIGE_ACTION_POP_HPP

#include "Action.hpp"

namespace vestige {
namespace action {

class Pop : public Action
{
    protected:
        state::Node* _from;
        
    public:
        Pop(state::Node* node, state::Node* from);
        
        state::Node* from();
        
        virtual std::string text();
};

}}

#endif
