#ifndef __VESTIGE_MARKER_BLOCK_HPP
#define __VESTIGE_MARKER_BLOCK_HPP

#include "Marker.hpp"

#include "../draw/Rectangle.hpp"
#include "../draw/Text.hpp"
#include "../draw/ToolTip.hpp"

namespace vestige {
namespace marker {

class Block : public Marker
{
	protected:
		osg::Node* background(int valid);
		std::string key;
		
	public:
		Block(std::string marker_args, std::string id, std::string key);
		
		virtual void update();
		virtual void alert(std::string message);
};

}}

#endif
