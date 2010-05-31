#include "ActionSet.hpp"

namespace vestige {
namespace action {

ActionSet::ActionSet() : Action::Vector()
{
}

std::string ActionSet::text() {
    std::string ret = "ACTIONS: [[ ";
    
    BOOST_FOREACH(action::Action *a, *this) {
        ret += a->text() + " ";
    }
    
    ret += "]]";
    
    return ret;
}

// Type { PopPush, Pop, Push, Discard, Create, Invalid }
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
                else if (past_n->index_y() != present_n->index_y()) {
                    D(("invalid: %s (index_y0: %i index_y1: %i)", present_n->id().c_str(), past_n->index_y(), present_n->index_y() ));
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
    
    BOOST_FOREACH(state::Node::MapPair present_p, *present) {
        state::Node* present_n = present_p.second;
        
        int found = 0;
        
        BOOST_FOREACH(state::Node::MapPair past_p, *past) {
            state::Node* past_n = past_p.second;
            
            //D(( "past_n: %s, present_n: %s", past_n->text().c_str(), present_n->text().c_str() ));
            
            if (present_n->id() == past_n->id()) {
                found = 1;
            }
        }
        
        if (!found) {
            this->push_back( new action::Create( present_n ) );
        }
    }
}

void ActionSet::alert(std::string message) {
    BOOST_FOREACH(Action *a, *this) {
        a->alert(message);
    }
}

int ActionSet::valid_logic() {
    BOOST_FOREACH(Action *a, *this) {
        if ( dynamic_cast<action::Invalid*>(a) ) {
            return 0;
        }
    }
    
    // 2 or more movements implies error unless:
    // they are all discard
    // they are all create
    if (this->size() >= 2) {
        int all_discard = 1;
        int all_create = 1;
        BOOST_FOREACH(Action *a, *this) {
            if ( ! dynamic_cast<action::Discard*>(a) ) {
                all_discard = 0;
            }
            if ( ! dynamic_cast<action::Create*>(a) ) {
                all_create = 0;
            }
        }
        
        if (!all_create && !all_discard) {
            return 0;
        }
    }
    
    return 1;
}

// if the rules procedure have verified all the actions as valid
int ActionSet::valid_rules() {
    BOOST_FOREACH(Action *a, *this) {
        if (! a->valid_rules) {
            return 0;
        }
    }
    
    return 1;
}

}}
