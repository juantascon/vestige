#ifndef __VESTIGE_STATE_LIST_HPP
#define __VESTIGE_STATE_LIST_HPP

#include "Node.hpp"
#include "../marker/List.hpp"

namespace vestige {
namespace state {

class NodeSet;

class List : public Node
{
    protected:
        NodeSet* _children;
        
    public:
        List(marker::List* list);
        
        void add_child(Node* c);
        NodeSet* children();
};

}}

#endif
