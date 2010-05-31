#include "GlobalMarkers.hpp"

#include "../lib/osgart.hpp"
#include "../lib/boost.hpp"

namespace vestige {
namespace marker {

GlobalMarkers* GlobalMarkers::instance() {
    return &boost::serialization::singleton<marker::GlobalMarkers>::get_mutable_instance();
}

GlobalMarkers::GlobalMarkers()
{
    _markers = new marker::MarkerSet();
    m_switch = 0;
    lists_count = 0;
    items_count = 0;
}

std::string GlobalMarkers::patt_format(std::string patt) {
    std::string dir = core::Parameters::instance()->ROOT()+"/data/patt/artk/";
    return "single;"+dir+patt+";100;0;0";
}

void GlobalMarkers::markers_add(marker::Marker *m) {
    _markers->push_back(m);
}

marker::MarkerSet* GlobalMarkers::markers_clone() {
    _markers->clone();
}

void GlobalMarkers::markers_initialize() {
    m_switch = new marker::Switch(patt_format("patt.hiro"));
    
    markers_add( new marker::List(patt_format("patt.sample1"), "ar_s1") );
    markers_add( new marker::List(patt_format("patt.sample2"), "ar_s2") );
    markers_add( new marker::List(patt_format("4x4_6.patt"), "ar_6") );
    
    markers_add( new marker::Item(patt_format("patt.a"), "ar_a", "1") );
    markers_add( new marker::Item(patt_format("patt.b"), "ar_b", "2") );
    markers_add( new marker::Item(patt_format("patt.c"), "ar_c", "3") );
    markers_add( new marker::Item(patt_format("patt.d"), "ar_d", "4") );
    markers_add( new marker::Item(patt_format("patt.f"), "ar_f", "5") );
    markers_add( new marker::Item(patt_format("patt.g"), "ar_g", "3") );
}

void GlobalMarkers::markers_reset() {
    BOOST_FOREACH(marker::Marker* m, *_markers) {
        m->set_active(1);
        m->set_id("");
    }
}

void GlobalMarkers::assign_empty_ids() {
    marker::MarkerSet* all = markers_clone();
    all->filter_by_visible(1);
    all->sort_by_x_axis();
    
    for (MarkerSet::iterator it = all->begin(); it != all->end(); ++it) {
        if ( (*it)->id().size() == 0) {
            std::stringstream ss;
            
            if (  dynamic_cast<marker::Item*>(*it) ) {
                ss << "I#" << items_count;
                items_count++;
            }
            else if ( dynamic_cast<marker::List*>(*it) ) {
                ss << "L#" << lists_count;
                lists_count++;
            }
            
            (*it)->set_id(ss.str());
        }
    }
}

}}
