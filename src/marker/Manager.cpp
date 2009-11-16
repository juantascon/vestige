#include "../Includes.hpp"

namespace far {
namespace marker {

Manager* Manager::_instance = 0;

Manager::Manager() : Vector()
{
}

Manager* Manager::instance() {
	if (!_instance) {
		_instance = new Manager();
	}
	return _instance;
}

void Manager::add(Marker *m) {
	this->push_back(m);
}

}}
