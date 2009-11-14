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

EState* EStateManager::capture() {
	std::cout << "capture()" << std::endl; 
}