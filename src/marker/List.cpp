#include "List.hpp"
#include "GlobalMarkers.hpp"

namespace vestige {
namespace marker {

List::List(std::string marker_args, std::string id) : Marker(marker_args, id) {
	//this->add(osgDB::readNodeFile("data/model/list.osg"));
	this->paint();
}

void List::paint() {
	marker::MarkerSet* blocks = marker::GlobalMarkers::instance()->items_clone();
	blocks->filter_by_visible(1);
	blocks->filter_by_type(1, 0);
	blocks->filter_by_aligned_with_marker(this);
	blocks->filter_by_over_marker(this);
	blocks->sort_by_y_axis();
	
	BOOST_FOREACH(marker::Marker* m, *blocks) {
		dynamic_cast<marker::Block*>(m)->set_top(0);
	}
	if ( blocks->size() > 0 ) {
		dynamic_cast<marker::Block*>(blocks->back())->set_top(1);
	}
	
	float size = core::Parameters::instance()->BLOCK_SIZE();
	float align_factor = core::Parameters::instance()->ALIGN_FACTOR();
	float range = (size*2.0*(blocks->size()))+size;
	float cover = (size*2.0*(blocks->size()-1.0));
	if (cover < 0) { cover = 0; }
	float line_width = 20.0;
	float z = 2.0;
	
	osg::Vec4* color = new osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f);
	if (!_valid) { color =  new osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f); }
	
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
