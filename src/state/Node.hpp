#ifndef __VESTIGE_STATE_NODE_HPP
#define __VESTIGE_STATE_NODE_HPP

#include "../marker/Marker.hpp"

namespace vestige {
namespace state {

class Node
{
    protected:
        marker::Marker* _marker;
        std::string _id;
        Node* _parent;
        int _index;
        
    public:
        typedef std::vector <Node*> Vector;
        typedef std::list <Node*> List;
        typedef std::map <std::string, Node*> Map;
        typedef std::pair<std::string, Node*> MapPair;
        
        Node(marker::Marker* marker);
        Node();
        
        Node* clone();
        
        virtual void set_parent(Node* parent, int index);
        
        marker::Marker* marker();
        std::string id();
        int index();
        Node* parent();
        
        std::string path();
        std::string text();
        void alert(std::string message);
};

}}

#endif
