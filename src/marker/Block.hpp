#ifndef __FAR_MARKER_BLOCK_HPP
#define __FAR_MARKER_BLOCK_HPP

#include "Marker.hpp"

#include "../draw/Rectangle.hpp"
#include "../draw/Label.hpp"

namespace far {
namespace marker {

class Block : public Marker
{
	protected:
		osg::Node* background(int valid);
		
	public:
		Block(std::string marker_args, std::string id, std::string key);
		
		draw::Label *label;
		
		virtual void update();
		virtual void alert(std::string message);
};

}}

#endif
