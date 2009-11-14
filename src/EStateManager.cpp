#include "EIncludes.hpp"

EStateManager* EStateManager::_instance = 0;

EStateManager* EStateManager::instance() {
	if (!_instance) {
		_instance = new EStateManager();
	}
	return _instance;
}


EStateManager::EStateManager()
{
	current = 0;
}

ENode* EStateManager::do_block(EMarkerBlock* b) {
	ENodeBlock* n = new ENodeBlock();
	//TODO: aqui deberia sacarse el valor de la variable del block
	
	b->processed = 1;
	return static_cast<ENode*>(n);
}

ENode* EStateManager::do_list(EMarkerList* l) {
	ENodeList* n = new ENodeList();
	
	BOOST_FOREACH( EMarker* m, (*EMarkerContainer::instance()) ) {
		if (m->processed) { continue; }
		
		EMarkerBlock* b = dynamic_cast<EMarkerBlock*>( m );
		if (!b) { continue; }
		
		if ( l->aligned(b)) {
			ENode* child = do_block(b);
			n->push(child);
		}
	}
	
	l->processed = 1;
	return static_cast<ENode*>(n);
}

EState* EStateManager::capture() {
	//TODO: conectar el estado anterior con el siguiente
	EState* state = new EState();
	
	BOOST_FOREACH( EMarker* m, (*EMarkerContainer::instance()) ) {
		m->processed = 0;
	}
	
	BOOST_FOREACH( EMarker* m, (*EMarkerContainer::instance()) ) {
		if (m->processed) { continue; }
		
		EMarkerList* l = dynamic_cast<EMarkerList*>( m );
		if (!l) { continue; }
		
		ENode* n = do_list(l);
		state->push(n);
	}
	
	BOOST_FOREACH( EMarker* m, (*EMarkerContainer::instance()) ) {
		if (m->processed) { continue; }
		
		EMarkerBlock* b = dynamic_cast<EMarkerBlock*>( m );
		if (!b) { continue; }
		
		ENode* n = do_block(b);
		state->push(n);
	}
	
	//std::cout << "capture()" << std::endl;
	//state->print();
	return state;
}
