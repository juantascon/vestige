#ifndef __VESTIGE_ACTION_CREATE_HPP
#define __VESTIGE_ACTION_CREATE_HPP

#include "Action.hpp"

namespace vestige {
namespace action {

class Create : public Action
{
    protected:
    public:
        Create(state::Node* node);
        
        std::string text();
};

}}

#endif
