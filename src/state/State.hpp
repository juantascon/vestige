#ifndef __VESTIGE_STATE_STATE_HPP
#define __VESTIGE_STATE_STATE_HPP

#include "NodeSet.hpp"

namespace vestige {
namespace state {

class State : public Node::Map
{
    protected:
        Node* _return_value;
        
    public:
        State();
        
        NodeSet* clone_nodes();
        Node* return_value();
        std::string text();
        
        void capture();
};

}}

#endif
