#include "EIncludes.hpp"

EMarkerContainer* EMarkerContainer::_instance = 0;

EMarkerContainer::EMarkerContainer() : EMarkerVector()
{
}

EMarkerContainer* EMarkerContainer::instance() {
	if (!_instance) {
		_instance = new EMarkerContainer();
	}
	return _instance;
}

void EMarkerContainer::add(EMarker *m) {
	this->push_back(m);
}
