#ifndef __FAR_CORE_SUPERVISOR_HPP
#define __FAR_CORE_SUPERVISOR_HPP

#include "../marker/GlobalMarkers.hpp"
#include "../problem/Types.hpp"

#include "../state/Capture.hpp"
#include "../action/Detect.hpp"
#include "../rule/RuleSet.hpp"

namespace far {
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
