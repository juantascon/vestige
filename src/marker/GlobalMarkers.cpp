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
	_items = new marker::MarkerSet();
	m_return = 0;
	m_switch = 0;
}

void GlobalMarkers::items_add(marker::Marker *m) {
	_items->push_back(m);
}

std::string GlobalMarkers::patt_format(std::string patt) {
	std::string dir = core::Parameters::instance()->ROOT()+"/data/patt/artk/";
	return "single;"+dir+patt+";100;0;0";
}

marker::MarkerSet* GlobalMarkers::items_clone() {
	_items->clone();
}

void GlobalMarkers::items_initialize() {
	m_switch = new marker::Switch(patt_format("patt.kanji"));
	m_return = new marker::Return(patt_format("patt.hiro"));
	
	items_add( new marker::List(patt_format("patt.sample1"), "l.s1") );
	items_add( new marker::List(patt_format("patt.sample2"), "l.s2") );
	items_add( new marker::List(patt_format("4x4_6.patt"), "l.6") );
	
	items_add( new marker::Block(patt_format("patt.a"), "b.a", "a") );
	items_add( new marker::Block(patt_format("patt.b"), "b.b", "b") );
	items_add( new marker::Block(patt_format("patt.c"), "b.c", "c") );
	items_add( new marker::Block(patt_format("patt.d"), "b.d", "d") );
	items_add( new marker::Block(patt_format("patt.f"), "b.f", "f") );
	items_add( new marker::Block(patt_format("patt.g"), "b.g", "g") );
	
	
	/*
	items_add( new marker::List(patt_format("patt.a"), "l.a") );
	items_add( new marker::List(patt_format("patt.b"), "l.b") );
	items_add( new marker::List(patt_format("patt.c"), "l.c") );
	items_add( new marker::List(patt_format("patt.d"), "l.d") );
	items_add( new marker::List(patt_format("patt.f"), "l.f") );
	items_add( new marker::List(patt_format("patt.g"), "l.g") );
	
	//items_add( new marker::Block(patt_format("4x4_1.patt"), "b.1", "1") );
	items_add( new marker::Block(patt_format("4x4_2.patt"), "b.2", "2") );
	items_add( new marker::Block(patt_format("4x4_3.patt"), "b.3", "3") );
	//items_add( new marker::Block(patt_format("4x4_4.patt"), "b.4", "4") );
	//items_add( new marker::Block(patt_format("4x4_5.patt"), "b.5", "5") );
	//items_add( new marker::Block(patt_format("4x4_6.patt"), "b.6", "6") );
	items_add( new marker::Block(patt_format("4x4_7.patt"), "b.7", "7") );
	//items_add( new marker::Block(patt_format("4x4_8.patt"), "b.8", "8") );
	//items_add( new marker::Block(patt_format("4x4_9.patt"), "b.9", "9") );
	//items_add( new marker::Block(patt_format("4x4_10.patt"), "b.10", "10") );
	items_add( new marker::Block(patt_format("4x4_11.patt"), "b.11", "11") );
	items_add( new marker::Block(patt_format("4x4_12.patt"), "b.12", "12") );
	//items_add( new marker::Block(patt_format("4x4_12.patt"), "b.13", "13") );
	//items_add( new marker::Block(patt_format("4x4_12.patt"), "b.14", "14") );
	//items_add( new marker::Block(patt_format("4x4_12.patt"), "b.15", "15") );
	//items_add( new marker::Block(patt_format("4x4_12.patt"), "b.16", "16") );
	*/
}

}}
