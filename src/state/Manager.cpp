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
	D(("BEGIN"));
	
	markers = new marker::Marker::List();
	
	BOOST_FOREACH( marker::Marker* m, (*marker::Manager::instance()) ) {
		D((":: check marker: "));
		
		if (!m->visible()) { continue; }
		if (! dynamic_cast<marker::Block*>(m) && !dynamic_cast<marker::List*>(m) ) { continue; }
		
		int inserted = 0;
		
		for (marker::Marker::List::iterator it = markers->begin(); it != markers->end(); ++it) {
			//D(( (*it)->value ));
			
			if ( (*it)->position().y() > m->position().y() ) {
				markers->insert( it, m );
				inserted = 1;
				break;
			}
		}
		
		if (!inserted) { markers->push_back( m ); }
	}
	
	for (marker::Marker::List::iterator it = markers->begin(); it != markers->end(); it++) {
		D(("marker: %s ref: %x", (*it)->id.c_str(), *it));
	}
	
	D(( "END" ));
}

Node* Manager::do_block(marker::Marker* m) {
	D(( ":: cast block" ));
	marker::Block* b = dynamic_cast<marker::Block*>( m );
	if (!b) { return NULL; }
	
	D(( "BEGIN" ));
	
	state::Block* n = new state::Block();
	n->id = b->id;
	
	D(( "END" ));
	return static_cast<Node*>(n);
}

Node* Manager::do_list(marker::Marker* m) {
	D(( "cast list" ));
	marker::List* l = dynamic_cast<marker::List*>( m );
	if (!l) { return NULL; }
	
	D(( "BEGIN" ));
	
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
	
	D(( "END" ));
	return static_cast<Node*>(n);
}

State* Manager::capture() {
	D(( "BEGIN" ));
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
	
	D(( "END" ));
	s->print();
	return s;
}

}}
