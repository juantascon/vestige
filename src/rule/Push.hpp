#ifndef __FAR_RULE_PUSH_HPP
#define __FAR_RULE_PUSH_HPP

#include "Rule.hpp"
#include "../action/Push.hpp"

namespace far {
namespace rule {

class Push : public Rule
{
	protected:
		std::string into;
		
	public:
		Push(std::string item, std::string into);
		
		virtual int valid(action::Action* action);
		virtual void print();
};

}}

#endif
