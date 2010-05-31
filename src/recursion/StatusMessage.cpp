#include "StatusMessage.hpp"

namespace vestige {
namespace recursion {

StatusMessage::StatusMessage(MessageType type, std::string message) {
    _type = type;
    _message = message;
}

StatusMessage::MessageType StatusMessage::type() { return this->_type; }
std::string StatusMessage::message() { return this->_message; }

std::string StatusMessage::text() {
    std::stringstream ss;
    ss << "type: " << _type << " message: " << _message;
    return ss.str();
}

}}
