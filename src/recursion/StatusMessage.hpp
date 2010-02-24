#ifndef __VESTIGE_RECURSION_STATUSMESSAGE_HPP
#define __VESTIGE_RECURSION_STATUSMESSAGE_HPP

#include <string>
#include <sstream>

namespace vestige {
namespace recursion {

class StatusMessage
{
	protected:
		int _stop;
		std::string _message;
		
	public:
		StatusMessage(int stop, std::string message);
		int stop();
		std::string message();
		
		std::string text();
};

}}

#endif
