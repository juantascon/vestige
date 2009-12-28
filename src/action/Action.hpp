/**
 * Actions:
 *
 * - (pop) move a block from a list to the board
 * - (push) move a block from the board to a list
 * - (pop-push) move a block from a list to another
 *
 * - (discard) discard an item
 * - (invalid) invalid movement
 *
 * ** Board is the base where all the items are on
 *
 **
 */

#ifndef __FAR_ACTION_ACTION_HPP
#define __FAR_ACTION_ACTION_HPP

#include "../state/Node.hpp"

namespace far {
namespace action {

class Action
{
	protected:
		state::Node* item;
		
	public:
		typedef std::vector <Action*> Vector;
		
		Action(state::Node* item);
		
		std::string item_id();
		
		void alert();
		virtual void print();
};

}}

#endif
