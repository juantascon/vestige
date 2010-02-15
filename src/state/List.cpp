#include "List.hpp"

namespace vestige {
namespace state {

List::List(marker::Marker *m) : Node(m)
{
	items = new state::Node::Vector();
}

List::List(std::string id) : Node(id)
{
	items = new state::Node::Vector();
}

void List::push(Node *n) {
	n->index = items->size();
	n->parent = this;
	
	items->push_back(n);
}

int List::check_items_ids(std::vector<std::string>* ids) {
	// sizes must match
	if ( items->size() != ids->size() ) {
		return 0;
	}
	
	int index = 0;
	BOOST_FOREACH(state::Node *n, *(items)) {
		if (n->id != (*ids)[index]) {
			return 0;
		}
		index++;
	}
	
	return 1;
}

std::string List::text() {
	std::string ret = "--- LIST-ID: " + this->id + " BLOCKS: | " ;
	
	BOOST_FOREACH(Node *n, *items) {
		ret += n->text() + " ";
	}
	ret += "|";
	
	return ret;
}

Node::List* List::flat_view() {
	Node::List* l = new Node::List();
	
	l->push_back(this);
	
	BOOST_FOREACH(Node *n, *items) {
	
		l->splice(l->end(), *(n->flat_view()));
	}
	
	//D(("LIST SIZE=%i", l->size()));
	return l;
}

}}
