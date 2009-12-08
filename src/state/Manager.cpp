#include "Manager.hpp"
#include "../marker/Block.hpp"

namespace far{
namespace state{

Manager* Manager::instance() { return &boost::serialization::singleton<far::state::Manager>::get_mutable_instance(); }

Manager::Manager()
{
	current = 0;
}

void Manager::sort_markers() {
	std::cout << "sort_markers()" << std::endl;
	
	markers = new marker::Marker::List();
	
	BOOST_FOREACH( marker::Marker* m, (*marker::Manager::instance()) ) {
		std::cout << ":: check marker: " << m->id << std::endl;
		
		if (!m->visible()) { continue; }
		if (! dynamic_cast<marker::Block*>(m) && !dynamic_cast<marker::List*>(m) ) { continue; }
		
		int inserted = 0;
		
		for (marker::Marker::List::iterator it = markers->begin(); it != markers->end(); ++it) {
			//std::cout << ((*it)->value) << std::endl;
			
			if ( (*it)->position().y() > m->position().y() ) {
				markers->insert( it, m );
				inserted = 1;
				break;
			}
		}
		
		if (!inserted) { markers->push_back( m ); }
	}
	
	for (marker::Marker::List::iterator it = markers->begin(); it != markers->end(); it++) {
		std::cout << ":: marker : " << (*it)->id << " ref: " << *it << std::endl;
	}
	
	std::cout << "end_sort_markers" << std::endl;
}

Node* Manager::do_block(marker::Marker* m) {
	std::cout << ":: cast block" << std::endl;
	marker::Block* b = dynamic_cast<marker::Block*>( m );
	if (!b) { return NULL; }
	
	std::cout << "do_block()" << std::endl;
	
	state::Block* n = new state::Block();
	n->id = b->id;
	
	std::cout << "end_do_block" << std::endl;
	return static_cast<Node*>(n);
}

Node* Manager::do_list(marker::Marker* m) {
	std::cout << ":: cast list" << std::endl;
	marker::List* l = dynamic_cast<marker::List*>( m );
	if (!l) { return NULL; }
	
	std::cout << "do_list()" << std::endl;
	
	state::List* n = new state::List();
	
	for (marker::Marker::List::iterator it = markers->begin(); it != markers->end(); ++it) {
		if ( l->aligned(*it)) {
			Node* child = do_block(*it);
			if (child) {
				n->push(child);
				markers->erase(it);
				it--;
			}
		}
	}
	
	std::cout << "end_do_list" << std::endl;
	return static_cast<Node*>(n);
}

State* Manager::capture() {
	std::cout << "capture()" << std::endl;
	//TODO: conectar el estado anterior con el siguiente
	State* s = new State();
	
	sort_markers();
	
	for (marker::Marker::List::iterator it = markers->begin(); it != markers->end(); ++it) {
		Node* n = do_list(*it);
		if (n) {
			s->push(n);
			markers->erase(it);
			it--;
		}
	}
	
	for (marker::Marker::List::iterator it = markers->begin(); it != markers->end(); ++it) {
		Node* n = do_block(*it);
		if (n) {
			s->push(n);
			markers->erase(it);
			it--;
		}
	}
	
	std::cout << "end_capture" << std::endl;
	s->print();
	return s;
}

}}
