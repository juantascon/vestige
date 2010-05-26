#ifndef __VESTIGE_ACTION_POPPUSH_HPP
#define __VESTIGE_ACTION_POPPUSH_HPP

#include "Action.hpp"

namespace vestige {
namespace action {

class PopPush : public Action
{
    protected:
        state::Node* _from;
        state::Node* _into;
        
    public:
        PopPush(state::Node* node, state::Node* from, state::Node* into);
        
        state::Node* from();
        state::Node* into();
        
        virtual std::string text();
};

}}

#endif
