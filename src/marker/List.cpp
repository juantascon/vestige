#include "List.hpp"
#include "GlobalMarkers.hpp"

namespace vestige {
namespace marker {

List::List(std::string marker_args, std::string ar_id) : Marker(marker_args, ar_id) {
    //this->add(osgDB::readNodeFile("data/model/list.osg"));
    this->paint();
}

void List::paint() {
    if (! this->visible() ) {
        return;
    }
    
    marker::MarkerSet* items = marker::GlobalMarkers::instance()->markers_clone();
    items->filter_by_visible(1);
    items->filter_by_type_items();
    items->filter_by_aligned_with_marker(this);
    items->filter_by_over_marker(this);
    items->sort_by_y_axis();

    // TODO: reactivar esto para information hidding:
    //BOOST_FOREACH(marker::Marker* m, *items) {
    //    dynamic_cast<marker::Item*>(m)->set_top(0);
    //}
    if ( items->size() > 0 ) {
        dynamic_cast<marker::Item*>(items->back())->set_top(1);
    }
    
    float size = core::Parameters::instance()->MARKER_SIZE();
    float align_factor = core::Parameters::instance()->ALIGN_FACTOR();
    float range = (size*2.0*(items->size()))+size;
    float cover = (size*2.0*(items->size()-1.0));
    // TODO: quitar esto para information hidding:
    cover = 0.0f;
    if (cover < 0) { cover = 0; }
    float line_width = 20.0;
    float z = 2.0;
    
    osg::Vec4* color = new osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f);
    if (!_active) { color =  new osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f); }
    
    // RECTANGLE
    draw::Rectangle* rectangle = new draw::Rectangle(
        osg::Vec3(size+(align_factor/2.0), size+cover, z),
        osg::Vec3(size+(align_factor/2.0), -size, z),
        osg::Vec3(-size-(align_factor/2.0), -size, z),
        osg::Vec3(-size-(align_factor/2.0), size+cover, z),
        *color
    );
    
    // LEFT LINE
    draw::Rectangle* line1 = new draw::Rectangle(
        osg::Vec3(-size-(align_factor/2.0), size+range, z),
        osg::Vec3(-size-(align_factor/2.0), -size, z),
        osg::Vec3(-size-line_width-(align_factor/2.0), -size, z),
        osg::Vec3(-size-line_width-(align_factor/2.0), size+range, z),
        *color
    );
    
    // RIGHT LINE
    draw::Rectangle* line2 = new draw::Rectangle(
        osg::Vec3(size+(align_factor/2.0), size+range, z),
        osg::Vec3(size+(align_factor/2.0), -size, z),
        osg::Vec3(size+line_width+(align_factor/2.0), -size, z),
        osg::Vec3(size+line_width+(align_factor/2.0), size+range, z),
        *color
    );
    
    // Container
    osg::Geode* geode = new osg::Geode();
    geode->addDrawable(rectangle);
    geode->addDrawable(line1);
    geode->addDrawable(line2);
    
    this->reset();
    this->add(geode);
}

void List::update() {
    this->paint();
}

}}
