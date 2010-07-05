#include "List.hpp"
#include "GlobalMarkers.hpp"

namespace vestige {
namespace marker {

List::List(std::string marker_args, std::string ar_id) : Marker(marker_args, ar_id) {
    this->_label = "";
    this->_items_size = 0;
    this->running = 0;
    
    this->update();
}

void List::update_items() {
    marker::MarkerSet* items = marker::GlobalMarkers::instance()->markers_clone();
    items->filter_by_visible(1);
    items->filter_by_type_items();
    items->filter_by_aligned_with_marker(this);
    items->filter_by_over_marker(this);
    items->sort_by_y_axis();
    
    _items_size = items->size();
    
    // Set all items as not on top
    BOOST_FOREACH(marker::Marker* m, *items) {
        dynamic_cast<marker::Item*>(m)->set_top(0);
    }
    

    if ( _items_size > 0 ) {
        // Set top item
        dynamic_cast<marker::Item*>(items->back())->set_top(1);
        
        // Hide the last item if it has no label
        if (dynamic_cast<marker::Item*>(items->back())->label().empty() &&
            core::Parameters::instance()->PHASE() == core::Parameters::PHASE_VARIABLES) {
            _items_size++;
        }
    }

    
}

void List::paint() {
    float size = core::Parameters::instance()->MARKER_SIZE();
    float z = -2.0;
    float align_factor = core::Parameters::instance()->ALIGN_FACTOR();
    float line_width = 20.0;
    float range = (size*2.0*(_items_size))+size;
    float cover = (size*2.0*(_items_size-1.0));
    
    if (cover < 0 || core::Parameters::instance()->PHASE() == core::Parameters::PHASE_CONCRETE) {
        cover = 0.0f;
    }
    
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
    
    this->add(geode);
    this->add((new draw::Text(this->label()))->wrap());
}

void List::update() {
    if (running) {return;}

    marker::GlobalMarkers::instance()->capture_info();
    
    if (! this->visible() ) { return; }
    
    running = 1;
    this->update_items();
    this->model_reset();
    this->paint();
    running = 0;
}

}}
