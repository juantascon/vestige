#include "NodeSet.hpp"

namespace vestige {
namespace state {

NodeSet::NodeSet() : Node::List()
{
}

NodeSet* NodeSet::clone() {
    NodeSet* ret = new NodeSet();
    
    BOOST_FOREACH( state::Node* n, *this ) {
        ret->push_back( n );
    }
    
    return ret;
}

void NodeSet::filter_by_no_parent() {
    for (NodeSet::iterator it = this->begin(); it != this->end(); ++it) {
        if ( ! (*it)->parent() ) {
            continue;
        }
        
        this->erase(it);
        it--;
    }
}

void NodeSet::filter_by_type_items() {
    for (NodeSet::iterator it = this->begin(); it != this->end(); ++it) {
        if ( dynamic_cast<state::Item*>( *it ) ) { continue; }
        
        this->erase(it);
        it--;
    }
}

void NodeSet::filter_by_type_lists() {
    for (NodeSet::iterator it = this->begin(); it != this->end(); ++it) {
        if ( dynamic_cast<state::List*>( *it ) ) { continue; }
        
        this->erase(it);
        it--;
    }
}

state::Item* NodeSet::remove_single_item() {
    for (NodeSet::iterator it = this->begin(); it != this->end(); ++it) {
        state::Item* ret = dynamic_cast<state::Item*>(*it);
        
        if (!ret) { continue; }
        
        this->erase(it);
        it--;
        
        return ret;
    }
    
    return NULL;
}

state::List* NodeSet::remove_single_list_by_size_range(int min, int max) {
    if (max == -1) { max = (std::numeric_limits<int>::max)(); }
    if (min == -1) { min = (std::numeric_limits<int>::max)(); }
    
    for (NodeSet::iterator it = this->begin(); it != this->end(); ++it) {
        state::List* ret = dynamic_cast<state::List*>(*it);
        
        if (!ret) { continue; }
        if (! (ret->children()->size() >= min) ) { continue; }
        if (! (ret->children()->size() <= max) ) { continue; }
        
        this->erase(it);
        it--;
        
        return ret;
    }
    
    return NULL;
}

std::string NodeSet::text() {
    std::string ret = "NODES: [[ ";
    
    BOOST_FOREACH(Node* n, *this) {
        ret += n->text() + " ";
    }
    ret += "]]";
    
    return ret;
}

}}
