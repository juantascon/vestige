#include "State.hpp"
#include "../marker/GlobalMarkers.hpp"

namespace vestige {
namespace state {

State::State() : Node::Map()
{
	_return_value = 0;
}

Node* State::return_value() { return this->_return_value; }

NodeSet* State::nodes() {
	NodeSet* ret = new NodeSet();
	
	BOOST_FOREACH(Node::MapPair p, *this) {
		ret->push_back(p.second);
	}
	
	return ret;
}

std::string State::text() {
	std::string ret = "STATE: [[ ";
	
	BOOST_FOREACH(Node::MapPair p, *this) {
		ret += p.second->text() + " ";
	}
	
	ret += "]]";
	
	if (_return_value) {
		ret += " -> " + _return_value->id();
	}
	
	return ret;
}

void State::capture() {
	marker::MarkerSet* markers = marker::GlobalMarkers::instance()->items_clone();
	markers->filter_by_visible(1);
	markers->sort_by_y_axis();
	
	BOOST_FOREACH(marker::Marker* m, *markers) {
		(*this)[m->id()] = new Node(m);
	}

	if (marker::GlobalMarkers::instance()->m_return->value()) {
		_return_value = (*this)[marker::GlobalMarkers::instance()->m_return->value()->id()];
	}
	
	marker::MarkerSet* lists = markers->clone();
	lists->filter_by_type(0, 1);
	
	marker::MarkerSet* blocks = markers->clone();
	blocks->filter_by_type(1, 0);
	
	BOOST_FOREACH(marker::Marker* l, *lists) {
		marker::MarkerSet* children = blocks->clone();
		children->filter_by_aligned_with_marker(l);
		children->filter_by_over_marker(l);
		
		BOOST_FOREACH(marker::Marker* c, *children) {
			(*this)[l->id()]->add_child( (*this)[c->id()] );
		}
	}
}

}}
