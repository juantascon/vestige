#ifndef __FAR_MARKER_SWITCH_HPP
#define __FAR_MARKER_SWITCH_HPP

#include "Marker.hpp"

namespace far {
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
