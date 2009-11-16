#include "../Includes.hpp"

namespace far{
namespace state{

Manager* Manager::_instance = 0;

Manager* Manager::instance() {
	if (!_instance) {
		_instance = new Manager();
	}
	return _instance;
}


Manager::Manager()
{
	current = 0;
}

Node* Manager::do_block(marker::Block* b) {
	Block* n = new Block();
	//TODO: aqui deberia sacarse el valor de la variable del block
	
	b->processed = 1;
	return static_cast<Node*>(n);
}

Node* Manager::do_list(marker::List* l) {
	List* n = new List();
	
	BOOST_FOREACH( marker::Marker* m, (*marker::Manager::instance()) ) {
		if (m->processed) { continue; }
		
		marker::Block* b = dynamic_cast<marker::Block*>( m );
		if (!b) { continue; }
		
		if ( l->aligned(b)) {
			Node* child = do_block(b);
			n->push(child);
		}
	}
	
	l->processed = 1;
	return static_cast<Node*>(n);
}

State* Manager::capture() {
	//TODO: conectar el estado anterior con el siguiente
	State* s = new State();
	
	BOOST_FOREACH( marker::Marker* m, (*marker::Manager::instance()) ) {
		m->processed = 0;
	}
	
	BOOST_FOREACH( marker::Marker* m, (*marker::Manager::instance()) ) {
		if (m->processed) { continue; }
		
		marker::List* l = dynamic_cast<marker::List*>( m );
		if (!l) { continue; }
		
		Node* n = do_list(l);
		s->push(n);
	}
	
	BOOST_FOREACH( marker::Marker* m, (*marker::Manager::instance()) ) {
		if (m->processed) { continue; }
		
		marker::Block* b = dynamic_cast<marker::Block*>( m );
		if (!b) { continue; }
		
		Node* n = do_block(b);
		s->push(n);
	}
	
	//std::cout << "capture()" << std::endl;
	//s->print();
	return s;
}

}}
