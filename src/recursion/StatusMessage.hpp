#ifndef __VESTIGE_RECURSION_STATUSMESSAGE_HPP
#define __VESTIGE_RECURSION_STATUSMESSAGE_HPP

#include <string>
#include <sstream>

namespace vestige {
namespace recursion {

class StatusMessage
{
    public:
        enum MessageType {
            CONTINUE,
            STOP,
            STANDBY
        };
        
        StatusMessage(MessageType type, std::string message);
        std::string message();
        MessageType type();
        
        std::string text();
        
    protected:
        MessageType _type;
        std::string _message;
        
};

}}

#endif
