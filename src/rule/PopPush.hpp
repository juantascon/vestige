#ifndef __VESTIGE_RULE_POPPUSH_HPP
#define __VESTIGE_RULE_POPPUSH_HPP

#include "Rule.hpp"
#include "../action/PopPush.hpp"

namespace vestige {
namespace rule {

class PopPush : public Rule
{
	protected:
		std::string from;
		std::string into;
		
	public:
		PopPush(std::string item, std::string from, std::string into);
		
		virtual int valid(action::Action* action);
		virtual std::string text();
};

}}

#endif
