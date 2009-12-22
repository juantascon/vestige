/**
 * Movements per state:
 *
 * - (pop-push) move a block from a list to another
 *
 * - (pop) move a block from a list to the board
 * - (push) move a block from the board to a list
 *
 * - (discard-block) discard a block
 * - (discard-list) discard a list
 *
 * - (invalid) invalid movement
 *
 * ** Board is the base where all the items are on
 *
 **
 */

#ifndef __FAR_STATE_SUPERVISOR_HPP
#define __FAR_STATE_SUPERVISOR_HPP

#include "State.hpp"
#include "../action/Action.hpp"

namespace far{
namespace state{

class Supervisor
{
	protected:
		Supervisor();
		
	public:
		static Supervisor* instance();
		
		action::Action* detect_action(State* past, State* present);
};

}}

#endif
