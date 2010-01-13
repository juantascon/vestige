#include "DrawHelper.hpp"

namespace far {
namespace core {

DrawHelper* DrawHelper::instance() { return &boost::serialization::singleton<far::core::DrawHelper>::get_mutable_instance(); }

DrawHelper::DrawHelper()
{
}

osg::Geometry* DrawHelper::rectangle(osg::Vec3* A, osg::Vec3* B, osg::Vec3* C, osg::Vec3* D, osg::Vec4* color) {
	osg::Geometry* rectangle = new osg::Geometry();
	
	osg::Vec3Array* vertices = new osg::Vec3Array();
	vertices->push_back( *A );
	vertices->push_back( *B );
	vertices->push_back( *C );
	vertices->push_back( *D );
	
	rectangle->setVertexArray( vertices );
	rectangle->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON, 0, 4));
	
	osg::Vec4Array* colors = new osg::Vec4Array();
	colors->push_back(*color);
	rectangle->setColorArray(colors);
	rectangle->setColorBinding(osg::Geometry::BIND_OVERALL);
	
	return rectangle;
}

}}
