#ifndef __FAR_CORE_DRAWHELPER_HPP
#define __FAR_CORE_DRAWHELPER_HPP

#include "../lib/osg.hpp"
#include "../lib/osgart.hpp"
#include "../lib/boost.hpp"

namespace far {
namespace core {

class DrawHelper
{
	protected:
		DrawHelper();
		
	public:
		static DrawHelper* instance();
		
		osg::Geometry* rectangle(osg::Vec3* A, osg::Vec3* B, osg::Vec3* C, osg::Vec3* D, osg::Vec4* color);
};

}}

#endif
