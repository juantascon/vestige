#include "../Includes.hpp"

namespace far {
namespace marker {

Manager* Manager::instance() { return &boost::serialization::singleton<far::marker::Manager>::get_mutable_instance(); }

Manager::Manager() : Vector()
{
}

void Manager::add(Marker *m) {
	this->push_back(m);
}

}}
