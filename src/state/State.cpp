#include "State.hpp"
#include "../marker/GlobalMarkers.hpp"

namespace vestige {
namespace state {

State::State() : Node::Map()
{
}

NodeSet* State::clone_nodes() {
    NodeSet* ret = new NodeSet();
    
    BOOST_FOREACH(Node::MapPair p, *this) {
        ret->push_back(p.second);
    }
    
    return ret;
}

std::string State::text() {
    std::string ret = "STATE: [[ ";
    
    BOOST_FOREACH(Node::MapPair p, *this) {
        ret += p.second->path() + " ";
    }
    
    ret += "]]";
    
    return ret;
}

void State::capture() {
    marker::MarkerSet* markers = marker::GlobalMarkers::instance()->markers_clone();
    markers->filter_by_visible(1);
    markers->sort_by_y_axis();
    
    // Add lists
    marker::MarkerSet* lists = markers->clone();
    lists->filter_by_type_lists();
    
    BOOST_FOREACH(marker::Marker* m, *lists) {
        (*this)[m->ar_id()] = new List(dynamic_cast<marker::List*>(m));
    }
    
    // Add Items
    marker::MarkerSet* items = markers->clone();
    items->filter_by_type_items();
    
    BOOST_FOREACH(marker::Marker* m, *items) {
        (*this)[m->ar_id()] = new Item(dynamic_cast<marker::Item*>(m));
    }
    
    // TODO: posible bug, cuando un item este alineado con 2 listas
    
    // Link Nodes
    BOOST_FOREACH(marker::Marker* m, *lists) {
        state::Node* n = (*this)[m->ar_id()];
        state::List* l = dynamic_cast<state::List*>( n );
        
        marker::MarkerSet* children = items->clone();
        children->filter_by_aligned_with_marker(m);
        children->filter_by_over_marker(m);
        
        BOOST_FOREACH(marker::Marker* c, *children) {
            l->add_child( (*this)[c->ar_id()] );
        }
    }
}

}}
