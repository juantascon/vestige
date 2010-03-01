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
    
    markers_add( new marker::List(patt_format("patt.sample1"), "l.s1") );
    markers_add( new marker::List(patt_format("patt.sample2"), "l.s2") );
    markers_add( new marker::List(patt_format("4x4_6.patt"), "l.6") );
    
    markers_add( new marker::Item(patt_format("patt.a"), "b.a", "a") );
    markers_add( new marker::Item(patt_format("patt.b"), "b.b", "b") );
    markers_add( new marker::Item(patt_format("patt.c"), "b.c", "x") );
    markers_add( new marker::Item(patt_format("patt.d"), "b.d", "x") );
    markers_add( new marker::Item(patt_format("patt.f"), "b.f", "f") );
    markers_add( new marker::Item(patt_format("patt.g"), "b.g", "x") );
}

}}
