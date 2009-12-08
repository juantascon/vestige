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
}
