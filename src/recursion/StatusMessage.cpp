#include "StatusMessage.hpp"

namespace vestige {
namespace recursion {

StatusMessage::StatusMessage(int stop, std::string message) {
	_stop = stop;
	_message = message;
}

int StatusMessage::stop() { return this->_stop; }
std::string StatusMessage::message() { return this->_message; }

std::string StatusMessage::text() {
	std::stringstream ss;
	ss << "stop: " << _stop << " message: " << _message;
	return ss.str();
}

}}
