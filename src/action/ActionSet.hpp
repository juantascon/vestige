#ifndef __VESTIGE_ACTION_ACTIONSET_HPP
#define __VESTIGE_ACTION_ACTIONSET_HPP

#include "Types.hpp"
#include "../state/State.hpp"

namespace vestige {
namespace action {

class ActionSet : public Action::Vector
{
	protected:
		
	public:
		ActionSet();
		
		void diff(state::State* past, state::State* present);
		Action* single();
		
		std::string text();
};

}}

#endif
