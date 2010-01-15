#ifndef __FAR_MARKER_OUTPUT_HPP
#define __FAR_MARKER_OUTPUT_HPP

#include "Marker.hpp"

namespace far {
namespace marker {

class Output : public Marker
{
	protected:
		Marker* value;
		void update_value();
		
		osg::Node* background();
		
	public:
		Output (std::string marker_args);
		
		virtual void update();
};

}}

#endif
