#ifndef __VESTIGE_STATE_NODE_HPP
#define __VESTIGE_STATE_NODE_HPP

#include "../marker/Marker.hpp"

namespace vestige {
namespace state {

class NodeSet;

class Node
{
    protected:
        marker::Marker* _marker;
        std::string _id;
        
        NodeSet* _children;
        Node* _parent;
        int _index;
        
    public:
        typedef std::vector <Node*> Vector;
        typedef std::list <Node*> List;
        typedef std::map <std::string, Node*> Map;
        typedef std::pair<std::string, Node*> MapPair;
        
        Node(marker::Marker* marker);
        
        void set_parent(Node* c);
        void add_child(Node* c);
        std::string path();
        NodeSet* x;
        
        marker::Marker* marker();
        std::string id();
        int index();
        Node* parent();
        NodeSet* children();
        
        std::string text();
        int children_size();
        
        void alert(std::string message);
};

}}

#endif
