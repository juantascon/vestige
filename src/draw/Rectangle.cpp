#include "Rectangle.hpp"

namespace far {
namespace draw {

Rectangle* Rectangle::instance() { return &boost::serialization::singleton<far::draw::Rectangle>::get_mutable_instance(); }

Rectangle::Rectangle()
{
}

osg::Geometry* Rectangle::create(osg::Vec3* A, osg::Vec3* B, osg::Vec3* C, osg::Vec3* D, osg::Vec4* color) {
	osg::Geometry* g = new osg::Geometry();
	
	osg::Vec3Array* vertices = new osg::Vec3Array();
	vertices->push_back( *A );
	vertices->push_back( *B );
	vertices->push_back( *C );
	vertices->push_back( *D );
	
	g->setVertexArray( vertices );
	g->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON, 0, 4));
	
	osg::Vec4Array* colors = new osg::Vec4Array();
	colors->push_back(*color);
	g->setColorArray(colors);
	g->setColorBinding(osg::Geometry::BIND_OVERALL);
	
	return g;
}

}}
