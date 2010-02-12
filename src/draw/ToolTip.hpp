#ifndef __FAR_DRAW_TOOLTIP_HPP
#define __FAR_DRAW_TOOLTIP_HPP

#include "../lib/osg.hpp"

#include "Rectangle.hpp"
#include "Text.hpp"

namespace far {
namespace draw {

class ToolTip : public osg::Geode
{
	protected:
		void initialize(std::string value, float size);
		
	public:
		ToolTip(std::string value, float size);
		ToolTip(std::string value);
};

}}

#endif
