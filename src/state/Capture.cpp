#include "Capture.hpp"

#include "../marker/GlobalMarkers.hpp"

namespace far {
namespace state {

Capture* Capture::instance() { return &boost::serialization::singleton<far::state::Capture>::get_mutable_instance(); }

Capture::Capture () {
}

Node* Capture::do_block(marker::Marker* m) {
	//D(( ":: cast block" ));
	marker::Block* b = dynamic_cast<marker::Block*>( m );
	if (!b) { return NULL; }
	
	//D(( "BEGIN" ));
	
	state::Block* n = new state::Block(m);
	
	if (marker::GlobalMarkers::instance()->m_return->value() == m) {
		_state->return_value = n;
	}
	
	//D(( "END" ));
	return static_cast<Node*>(n);
}

Node* Capture::do_list(marker::Marker* m) {
	//D(( "cast list" ));
	marker::List* l = dynamic_cast<marker::List*>( m );
	if (!l) { return NULL; }
	
	//D(( "BEGIN" ));
	
	state::List* n = new state::List(m);
	
	for (marker::Marker::List::iterator it = _markers->begin(); it != _markers->end(); ++it) {
		if ( l->aligned(*it) ) {
			Node* child = do_block(*it);
			if (child) {
				n->push(child);
				_markers->erase(it);
				it--;
			}
		}
	}
	
	if (marker::GlobalMarkers::instance()->m_return->value() == m) {
		_state->return_value = n;
	}
	
	//D(( "END" ));
	return static_cast<Node*>(n);
}

State* Capture::capture() {
	//D(( "BEGIN" ));
	
	_markers = marker::GlobalMarkers::instance()->sort_y_axis();
	
	if (_markers->size() <= 0) { return NULL; }
	
	_state = new State();
	
	for (marker::Marker::List::iterator it = _markers->begin(); it != _markers->end(); ++it) {
		//D(("IT: %x, RETURN: %x", *it, ))
		Node* n = do_list(*it);
		if (n) {
			_state->push(n);
			_markers->erase(it);
			it--;
		}
	}
	
	for (marker::Marker::List::iterator it = _markers->begin(); it != _markers->end(); ++it) {
		Node* n = do_block(*it);
		if (n) {
			_state->push(n);
			_markers->erase(it);
			it--;
		}
	}
	
	_state->create_flat_view();
	
	//D(( "END" ));
	
	return _state;
}

}}
