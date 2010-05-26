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
    markers->sort_by_x_axis();
    
    // Add items and lists
    BOOST_FOREACH(marker::Marker* m, *markers) {
        marker::List* ml = dynamic_cast<marker::List*>(m);
        marker::Item* mi = dynamic_cast<marker::Item*>(m);
        
        Node* n = ml ? dynamic_cast<Node*>(new List(ml)) : dynamic_cast<Node*>(new Item(mi));
        n->set_index_x(this->size());
        
        (*this)[m->ar_id()] = n;
    }

    marker::MarkerSet* lists = markers->clone();
    lists->filter_by_type_lists();
    
    marker::MarkerSet* items = markers->clone();
    items->filter_by_type_items();
    items->sort_by_y_axis();
    
    // Link child Nodes
    // TODO: posible bug, cuando un item este alineado con 2 listas
    BOOST_FOREACH(marker::Marker* m, *lists) {
        state::Node* n = (*this)[m->ar_id()];
        state::List* l = dynamic_cast<state::List*>( n );
        
        marker::MarkerSet* children = items->clone();
        children->filter_by_aligned_with_marker(m);
        children->filter_by_over_marker(m);

        D(("aligned to %s, size: %i", m->id().c_str(), children->size()));
        
        BOOST_FOREACH(marker::Marker* c, *children) {
            l->add_child( (*this)[c->ar_id()] );
        }
    }
}

}}
