#ifndef __FAR_RULE_POP_HPP
#define __FAR_RULE_POP_HPP

#include "Rule.hpp"
#include "../action/Pop.hpp"

namespace far {
namespace rule {

class Pop : public Rule
{
	protected:
		std::string from;
		
	public:
		Pop(std::string item, std::string from);
		
		virtual int valid(action::Action* action);
		virtual void print();
};

}}

#endif
