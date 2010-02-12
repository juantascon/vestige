#include "Rectangle.hpp"

namespace far {
namespace draw {

Rectangle::Rectangle(osg::Vec3 A, osg::Vec3 B, osg::Vec3 C, osg::Vec3 D, osg::Vec4 color)
: osg::Geometry()
{
	osg::Vec3Array* vertices = new osg::Vec3Array();
	vertices->push_back( A );
	vertices->push_back( B );
	vertices->push_back( C );
	vertices->push_back( D );
	this->setVertexArray( vertices );
	
	osg::Vec4Array* colors = new osg::Vec4Array();
	colors->push_back(color);
	this->setColorArray(colors);
	this->setColorBinding(osg::Geometry::BIND_OVERALL);
	
	//this->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));
	this->addPrimitiveSet(new osg::DrawArrays(GL_POLYGON, 0, 4));
	//this->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, 0, 4));
	
	//osg::StateSet* stateset = this->getOrCreateStateSet();
	//stateset->setMode(GL_BLEND,osg::StateAttribute::ON);
	//stateset->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
}

}}
