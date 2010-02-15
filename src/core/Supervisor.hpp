#ifndef __VESTIGE_CORE_SUPERVISOR_HPP
#define __VESTIGE_CORE_SUPERVISOR_HPP

#include "../marker/GlobalMarkers.hpp"
#include "../problem/Types.hpp"

#include "../state/Capture.hpp"
#include "../action/Detect.hpp"
#include "../rule/RuleSet.hpp"

namespace vestige {
namespace core {

class Supervisor
{
	protected:
		Supervisor();
		
		problem::Problem* p;
		
		state::State* previous_state;
		state::State* current_state;
		
	public:
		static Supervisor* instance();
		
		void step();
};

}}

#endif
