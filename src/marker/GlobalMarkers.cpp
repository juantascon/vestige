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
    m_return = 0;
    m_switch = 0;
}

void GlobalMarkers::markers_add(marker::Marker *m) {
    _markers->push_back(m);
}

std::string GlobalMarkers::patt_format(std::string patt) {
    std::string dir = core::Parameters::instance()->ROOT()+"/data/patt/artk/";
    return "single;"+dir+patt+";100;0;0";
}

marker::MarkerSet* GlobalMarkers::markers_clone() {
    _markers->clone();
}

void GlobalMarkers::markers_initialize() {
    m_switch = new marker::Switch(patt_format("patt.kanji"));
    m_return = new marker::Return(patt_format("patt.hiro"));
    
    markers_add( new marker::List(patt_format("patt.sample1"), "ls1") );
    markers_add( new marker::List(patt_format("patt.sample2"), "ls2") );
    markers_add( new marker::List(patt_format("4x4_6.patt"), "l6") );
    
    markers_add( new marker::Item(patt_format("patt.a"), "a", "1") );
    markers_add( new marker::Item(patt_format("patt.b"), "b", "2") );
    markers_add( new marker::Item(patt_format("patt.c"), "c", "3") );
    markers_add( new marker::Item(patt_format("patt.d"), "d", "4") );
    markers_add( new marker::Item(patt_format("patt.f"), "f", "5") );
}

}}
