#ifndef __FAR_MARKER_SWITCH_HPP
#define __FAR_MARKER_SWITCH_HPP

#include "Marker.hpp"

namespace far {
namespace marker {

class Switch : public Marker
{
	protected:
		int captured;
		
	public:
		Switch (std::string marker_args);
		
		virtual void update();
};

}}

#endif
