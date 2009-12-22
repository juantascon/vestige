#include "State.hpp"
#include "List.hpp"

namespace far{
namespace state{

State::State() : List(NULL)
{
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
			
			if (this_n->id == comp_n->id) {
				
				// verifica si el nodo tiene una nueva ruta
				if (this_n->path() != comp_n->path()) {
					
					// verifica hacia donde cambio el nodo, tener en cuenta los posibles cambios
					// si antes estaba sobre el tablero o si estaba en una lista y ahora está en el tabler
					if (this_n->parent->id == this->id) {
						// el bloque pasó del tablero a una lista
						v->push_back( new action::Action( this_n, action::Action::Push) );
					}
					else {
						if (comp_n->parent->id == comp->id) {
							// el bloque pasó de una lista al tablero
							v->push_back( new action::Action( this_n, action::Action::Pop) );
						} else {
							// el bloque pasó de una lista a otra lista
							v->push_back( new action::Action( this_n, action::Action::PopPush) );
						}
					}
				}
				else {
					//TODO: verificar si el nodo cambió de posición en la lista
				}
				
				found = 1;
				break;
			}
		}
		
		if (!found) {
			//TODO: verificar cuando sea DiscardList
			v->push_back( new action::Action( this_n, action::Action::DiscardBlock) );
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
