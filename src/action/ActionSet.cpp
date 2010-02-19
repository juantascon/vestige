#include "ActionSet.hpp"

namespace vestige {
namespace action {

ActionSet::ActionSet() : Action::Vector()
{
}

std::string ActionSet::text() {
	std::string ret = "ACTIONSET: [[ ";
	
	BOOST_FOREACH(action::Action *a, *this) {
		ret += a->text() + " ";
	}
	
	ret += "]]";
	
	return ret;
}

// Type { PopPush, Pop, Push, DiscardBlock, DiscardList, Invalid, None }
void ActionSet::diff(state::State* past, state::State* present) {
	if (! past || ! present) {
		return;
	}
	
	//D(("past::%s", past->text().c_str()));
	//D(("present::%s", present->text().c_str()));

	BOOST_FOREACH(state::Node::MapPair past_p, *past) {
		state::Node* past_n = past_p.second;
		
		int found = 0;

		BOOST_FOREACH(state::Node::MapPair present_p, *present) {
			state::Node* present_n = present_p.second;
			
			//D(( "past_n: %s, present_n: %s", past_n->text().c_str(), present_n->text().c_str() ));
			
			if (past_n->id() == present_n->id()) {
				
				// verifica si el nodo tiene una nueva ruta
				if (past_n->path() != present_n->path()) {
					
					// verifica hacia donde cambio el nodo, tener en cuenta los posibles cambios:
					// tablero->lista lista->tablero lista->lista
					
					// el bloque estaba en el tablero, ahora debe estar en una lista
					if (!past_n->parent()) {
						this->push_back( new action::Push(present_n, present_n->parent()) );
					}
					// el bloque esta en el tablero, antes debio estar en una lista
					else if (!present_n->parent()) {
						this->push_back( new action::Pop( present_n, past_n->parent()) );
					}
					// el bloque ni estaba ni esta en el tablero, el cambio fue de lista a lista
					else {
						this->push_back( new action::PopPush( present_n, past_n->parent(), present_n->parent() ) );
					}
				}
				else if (past_n->index() != present_n->index()) {
					D(("invalid: %s (index0: %i index1: %i)", present_n->id().c_str(), past_n->index(), present_n->index() ));
					this->push_back( new action::Invalid( present_n ) );
				}
				
				found = 1;
				break;
			}
		}
		
		if (!found) {
			this->push_back( new action::Discard( past_n ) );
		}
	}
}

Action* ActionSet::single() {
	// no movements
	if (this->size() == 0) {
		return NULL;
	}
	
	// 2 or more movements implies error
	if (this->size() >= 2) {
		BOOST_FOREACH(Action *a, *this) {
			a->alert("INVALID-ACTION");
		}
		return new Invalid(NULL);
	}
	
	// only 1 difference means good movement
	if (this->size() == 1) {
		return (*this)[0];
	}
	
	// this point shouldnt be reached
	return NULL;
}

}}
