#ifndef __VESTIGE_ACTION_DISCARD_HPP
#define __VESTIGE_ACTION_DISCARD_HPP

#include "Action.hpp"

namespace vestige {
namespace action {

class Discard : public Action
{
    protected:
    public:
        Discard(state::Node* node);
        
        std::string text();
};

}}

#endif
