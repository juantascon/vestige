#ifndef __FAR_MARKER_RETURN_HPP
#define __FAR_MARKER_RETURN_HPP

#include "Marker.hpp"

#include "../draw/Rectangle.hpp"

namespace far {
namespace marker {

class Return : public Marker
{
	protected:
		Marker* _value;
		void update_value();
		
		osg::Node* background();
		
	public:
		Return (std::string marker_args);
		
		Marker* value();
		
		virtual void update();
};

}}

#endif
