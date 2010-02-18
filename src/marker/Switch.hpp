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
		
	public:
		Switch (std::string marker_args);
		
		virtual void set_valid(int valid);
		virtual void alert(std::string message);
		virtual void paint();
		virtual void update();
};

}}

#endif
