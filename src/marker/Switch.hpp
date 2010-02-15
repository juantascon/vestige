#ifndef __VESTIGE_MARKER_SWITCH_HPP
#define __VESTIGE_MARKER_SWITCH_HPP

#include "Marker.hpp"
#include "../draw/ToolTip.hpp"

namespace vestige {
namespace marker {

class Switch : public Marker
{
	protected:
		int captured;
		int active;
		
	public:
		Switch (std::string marker_args);
		
		void deactivate();
		
		virtual void update();
};

}}

#endif
