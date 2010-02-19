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

void NodeSet::filter_by_type(int blocks, int lists) {
	for (NodeSet::iterator it = this->begin(); it != this->end(); ++it) {
		if (blocks) {
			if ( dynamic_cast<marker::Block*>( (*it)->marker() ) ) { continue; }
		}

		if (lists) {
			if ( dynamic_cast<marker::List*>( (*it)->marker() ) ) { continue; }
		}
		
		this->erase(it);
		it--;
	}
}

state::Node* NodeSet::filter_single_by_size_range(int min, int max) {
	state::Node* ret = 0;
	
	for (NodeSet::iterator it = this->begin(); it != this->end(); ++it) {
		// validate size range
		if (! ((*it)->children()->size() >= min && (*it)->children()->size() <= max) ) {
			continue;
		}
		
		ret = (*it);
		
		this->erase(it);
		it--;
		
		break;
	}
	
	return ret;
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
