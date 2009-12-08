#include <boost/foreach.hpp>
#include <iostream>
#include <vector>
#include <list>

class Int {
	public:
		typedef std::list <Int*> List;
		
		int value;
		Int(int v) {
			value = v;
		}
};



int main(int argc, char* argv[]) {
	
	Int::List *v = new Int::List();
	
	v->push_back(new Int(1));
	v->push_back(new Int(3));
	v->push_back(new Int(10));
	v->push_back(new Int(13));

	/*Int *x = new Int(5);
	for (Int::List::iterator it = v->begin(); it != v->end(); it++) {
		//std::cout << ((*it)->value) << std::endl;
		if ( (*it)->value > x->value ) {
			v->insert( it, x );
			break;
		}
	}*/
	
	Int *x = new Int(13);
	for (Int::List::iterator it = v->begin(); it != v->end(); ++it) {
		std::cout << ((*it)->value) << std::endl;
		if ( (*it)->value == x->value ) {
			v->erase( it );
			it--;
		}
	}
	
	/*Int *x = new Int(10);
	BOOST_FOREACH(Int* ix, *v) {
		std::cout << (ix->value) << std::endl;
		if ( ix->value == x->value ) {
			v->remove( ix );
		}
	}*/

	
	std::cout << ":: values: " << std::endl;
	for (Int::List::iterator it = v->begin(); it != v->end(); it++) {
		std::cout << ((*it)->value) << std::endl;
	}
}
