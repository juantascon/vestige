#ifndef __FAR_RULE_DISCARD_HPP
#define __FAR_RULE_DISCARD_HPP

#include "Rule.hpp"
#include "../action/Discard.hpp"

namespace far {
namespace rule {

class Discard : public Rule
{
	protected:
	public:
		Discard(std::string item);
		
		virtual int valid(action::Action* action);
		virtual std::string text();
};

}}

#endif
