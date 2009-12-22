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
	
	Int::List *l1 = new Int::List();
	
	l1->push_back(new Int(12));
	l1->push_back(new Int(3));
	l1->push_back(new Int(4));
	l1->push_back(new Int(1));


	Int::List *l2 = new Int::List();
	l2->push_back(new Int(2));
	l2->push_back(new Int(2));
	l2->push_back(new Int(98));
	l2->push_back(new Int(7));
	
	l1->splice(l1->end(), *l2);

	std::cout << ":: values: " << std::endl;
	for (Int::List::iterator it = l1->begin(); it != l1->end(); it++) {
		std::cout << ((*it)->value) << std::endl;
	}
}
