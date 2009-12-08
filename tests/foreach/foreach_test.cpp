#include <boost/foreach.hpp>
#include <iostream>
#include <vector>
#include <list>

class Int {
	public:
		int value;
		Int(int v) {
			value = v;
		}
};

typedef std::list <Int*> IntVector;

int main(int argc, char* argv[]) {
	
	IntVector *v = new IntVector();
	
	v->push_back(new Int(1));
	v->push_back(new Int(2));
	v->push_back(new Int(3));
	v->push_back(new Int(4));
	
	BOOST_FOREACH( Int* x, *v ) {
		if (x->value <= 2) {
			v->pop_back();
		}
		std::cout << "size:" << v->size() << " val:" << x->value << std::endl;
	}
}
