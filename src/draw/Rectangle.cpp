#include "Rectangle.hpp"

namespace vestige {
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
    
    this->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));
    //this->addPrimitiveSet(new osg::DrawArrays(GL_POLYGON, 0, 4));
    //this->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, 0, 4));
    
    osg::StateSet* stateset = this->getOrCreateStateSet();
    // Enable blending, select transparent bin
    stateset->setMode(GL_BLEND, osg::StateAttribute::ON);
    stateset->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
    // Enable depth test so that an opaque polygon will occlude a transparent one behind it
    stateset->setMode(GL_DEPTH_TEST, osg::StateAttribute::ON);
    // Conversely, disable writing to depth buffer so that
    // a transparent polygon will allow polygons behind it to shine thru
    // OSG renders transparent polygons after opaque ones
    //osg::Depth* depth = new osg::Depth;
    //depth->setWriteMask( false );
    //stateset->setAttributeAndModes( depth, osg::StateAttribute::ON );
    // Disable conflicting modes.
    stateset->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
}

}}
