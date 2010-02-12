#ifndef __FAR_DRAW_RECTANGLE_HPP
#define __FAR_DRAW_RECTANGLE_HPP

#include "../lib/osg.hpp"
#include "../lib/osgart.hpp"
#include "../lib/boost.hpp"

namespace far {
namespace draw {

class Rectangle : public osg::Geometry
{
	protected:
	
	public:
		 Rectangle(osg::Vec3 A, osg::Vec3 B, osg::Vec3 C, osg::Vec3 D, osg::Vec4 color);
};

}}

#endif