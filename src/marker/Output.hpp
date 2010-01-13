#ifndef __FAR_MARKER_OUTPUT_HPP
#define __FAR_MARKER_OUTPUT_HPP

#include "Marker.hpp"

namespace far {
namespace marker {

class Output : public Marker
{
	protected:
		Marker* value;
		
	public:
		Output (std::string marker_args, std::string id);
		
		virtual void update();
};

}}

#endif
