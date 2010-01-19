#include "Capture.hpp"

#include "../marker/GlobalMarkers.hpp"

namespace far {
namespace state {

Capture* Capture::instance() { return &boost::serialization::singleton<far::state::Capture>::get_mutable_instance(); }

Capture::Capture ()
{
}

Node* Capture::do_block(marker::Marker* m) {
	//D(( ":: cast block" ));
	marker::Block* b = dynamic_cast<marker::Block*>( m );
	if (!b) { return NULL; }
	
	//D(( "BEGIN" ));
	
	state::Block* n = new state::Block(m);
	
	//D(( "END" ));
	return static_cast<Node*>(n);
}

Node* Capture::do_list(marker::Marker* m) {
	//D(( "cast list" ));
	marker::List* l = dynamic_cast<marker::List*>( m );
	if (!l) { return NULL; }
	
	//D(( "BEGIN" ));
	
	state::List* n = new state::List(m);
	
	for (marker::Marker::List::iterator it = tmp_markers->begin(); it != tmp_markers->end(); ++it) {
		if ( l->aligned(*it)) {
			Node* child = do_block(*it);
			if (child) {
				n->push(child);
				tmp_markers->erase(it);
				it--;
			}
		}
	}
	
	//D(( "END" ));
	return static_cast<Node*>(n);
}

State* Capture::capture() {
	//D(( "BEGIN" ));
	
	tmp_markers = marker::GlobalMarkers::instance()->sort_y_axis();
	
	if (tmp_markers->size() <= 0) { return NULL; }
	
	State* s = new State();
	
	for (marker::Marker::List::iterator it = tmp_markers->begin(); it != tmp_markers->end(); ++it) {
		//D(("IT: %x, OUTPUT: %x", *it, ))
		Node* n = do_list(*it);
		if (n) {
			s->push(n);
			tmp_markers->erase(it);
			it--;
		}
	}
	
	for (marker::Marker::List::iterator it = tmp_markers->begin(); it != tmp_markers->end(); ++it) {
		Node* n = do_block(*it);
		if (n) {
			s->push(n);
			tmp_markers->erase(it);
			it--;
		}
	}
	
	s->create_flat_view();
	
	//D(( "END" ));
	
	return s;
}

}}
