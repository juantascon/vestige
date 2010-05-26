#ifndef __VESTIGE_STATE_NODE_HPP
#define __VESTIGE_STATE_NODE_HPP

#include "../marker/Marker.hpp"

namespace vestige {
namespace state {

class Node
{
    protected:
        marker::Marker* _marker;
        Node* _parent;
        int _index_x;
        int _index_y;
        
    public:
        typedef std::vector <Node*> Vector;
        typedef std::list <Node*> List;
        typedef std::map <std::string, Node*> Map;
        typedef std::pair<std::string, Node*> MapPair;
        
        Node(marker::Marker* marker);
        Node();
        
        Node* clone();
        
        marker::Marker* marker();
        std::string id();
        
        Node* parent();
        int index_x();
        int index_y();
        
        void set_parent(Node* parent);
        void set_index_x(int index_x);
        void set_index_y(int index_y);
        
        std::string path();
        virtual std::string text();
        void alert(std::string message);
};

}}

#endif
