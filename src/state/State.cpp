#include "State.hpp"

namespace far {
namespace state {

State::State() : List(NULL)
{
}

void State::push(Node *n) {
	n->index = 0;
	n->parent = this;
	
	_items.push_back(n);
}

void State::print() {
	std::cout << "*******************************************************************" << std::endl;
	
	
	BOOST_FOREACH(Node *n, _items) {
		n->print();
		std::cout << std::endl;
	}
	
	std::cout << "*******************************************************************" << std::endl << std::endl;
}


void State::create_flat_view() {
	flat_items = flat_view();
	
	D(("FLAT PRINT"));
	//D(("FLAT ITEMS SIZE = %i", flat_items->size()));
	
	BOOST_FOREACH(Node *n, *flat_items) {
		D(( n->path().c_str() ));
	}
	
	D(("END"));
}

// *this* should be past and *comp* should be present
// Type { PopPush, Pop, Push, DiscardBlock, DiscardList, Invalid, None }
action::Action::Vector* State::diff(State* comp) {
	action::Action::Vector* v = new action::Action::Vector();
	
	BOOST_FOREACH(Node *this_n, *flat_items) {
		
		int found = 0;
		
		BOOST_FOREACH(Node *comp_n, *(comp->flat_items)) {
			
			//D(("Comp: %s This: %s", comp_n->id.c_str(), this_n->id.c_str()));
			
			if (this_n->id == comp_n->id) {
				
				// verifica si el nodo tiene una nueva ruta
				if (this_n->path() != comp_n->path()) {
					
					// verifica hacia donde cambio el nodo, tener en cuenta los posibles cambios
					// si antes estaba sobre el tablero o si estaba en una lista y ahora está en el tabler
					if (this_n->parent->id == this->id) {
						// el bloque pasó del tablero a una lista
						v->push_back( new action::Push( comp_n, comp_n->parent) );
					}
					else {
						if (comp_n->parent->id == comp->id) {
							// el bloque pasó de una lista al tablero
							v->push_back( new action::Pop( comp_n, this_n->parent) );
						} else {
							// el bloque pasó de una lista a otra lista
							v->push_back( new action::PopPush( comp_n, this_n->parent, comp_n->parent) );
						}
					}
				}
				else if (this_n->index != comp_n->index) {
					D(("invalid: %s (index0: %i index1: %i)", comp_n->id.c_str(), this_n->index, comp_n->index ));
					v->push_back( new action::Invalid( comp_n ) );
				}
				
				found = 1;
				break;
			}
		}
		
		if (!found) {
			v->push_back( new action::Discard( this_n ) );
		}
	}
	
	D(("DIFF PRINT"));
	
	BOOST_FOREACH(action::Action *a, *v) {
		a->print();
	}
	
	D(("END"));
	
	return v;
}

}}
