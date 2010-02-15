/**
 * Rules:
 *
 * - (pop) move a block from a list (*from*) to the board
 * - (push) move a block from the board to a list (*into*)
 * - (pop-push) move a block from a list (*from*) to another (*into*)
 *
 * - (discard) discard an item
 *
 * ** Board is the base where all the items are on
 *
 **
 */

#ifndef __VESTIGE_RULE_RULE_HPP
#define __VESTIGE_RULE_RULE_HPP

#include "../action/Action.hpp"

namespace vestige {
namespace rule {

class Rule
{
	protected:
		std::string item;
		
	public:
		typedef std::vector <Rule*> Vector;
		
		Rule(std::string item);
		
		virtual int valid(action::Action* action);
		virtual std::string text() = 0;
};

}}

#endif
