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
    
    /*
    markers_add( new marker::List(patt_format("patt.a"), "l.a") );
    markers_add( new marker::List(patt_format("patt.b"), "l.b") );
    markers_add( new marker::List(patt_format("patt.c"), "l.c") );
    markers_add( new marker::List(patt_format("patt.d"), "l.d") );
    markers_add( new marker::List(patt_format("patt.f"), "l.f") );
    markers_add( new marker::List(patt_format("patt.g"), "l.g") );
    
    //markers_add( new marker::Item(patt_format("4x4_1.patt"), "b.1", "1") );
    markers_add( new marker::Item(patt_format("4x4_2.patt"), "b.2", "2") );
    markers_add( new marker::Item(patt_format("4x4_3.patt"), "b.3", "3") );
    //markers_add( new marker::Item(patt_format("4x4_4.patt"), "b.4", "4") );
    //markers_add( new marker::Item(patt_format("4x4_5.patt"), "b.5", "5") );
    //markers_add( new marker::Item(patt_format("4x4_6.patt"), "b.6", "6") );
    markers_add( new marker::Item(patt_format("4x4_7.patt"), "b.7", "7") );
    //markers_add( new marker::Item(patt_format("4x4_8.patt"), "b.8", "8") );
    //markers_add( new marker::Item(patt_format("4x4_9.patt"), "b.9", "9") );
    //markers_add( new marker::Item(patt_format("4x4_10.patt"), "b.10", "10") );
    markers_add( new marker::Item(patt_format("4x4_11.patt"), "b.11", "11") );
    markers_add( new marker::Item(patt_format("4x4_12.patt"), "b.12", "12") );
    //markers_add( new marker::Item(patt_format("4x4_12.patt"), "b.13", "13") );
    //markers_add( new marker::Item(patt_format("4x4_12.patt"), "b.14", "14") );
    //markers_add( new marker::Item(patt_format("4x4_12.patt"), "b.15", "15") );
    //markers_add( new marker::Item(patt_format("4x4_12.patt"), "b.16", "16") );
    */
}

}}
