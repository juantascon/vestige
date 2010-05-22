#ifndef __VESTIGE_STATE_STATE_HPP
#define __VESTIGE_STATE_STATE_HPP

#include "NodeSet.hpp"

namespace vestige {
namespace state {

class State : public Node::Map
{
    protected:
        
    public:
        State();
        
        NodeSet* clone_nodes();
        std::string text();
        
        void capture();
};

}}

#endif
