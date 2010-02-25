#include "MarkerSet.hpp"

#include "../lib/boost.hpp"

namespace vestige {
namespace marker {

MarkerSet::MarkerSet() : Marker::List()
{
}

MarkerSet* MarkerSet::clone(){
    MarkerSet* ret = new MarkerSet();
    
    BOOST_FOREACH( marker::Marker* m, *this ) {
        ret->push_back( m );
    }
    
    return ret;
}

bool MarkerSet::compare_by_y_axis(Marker* m1, Marker *m2) {
    return ( m1->position().y() < m2->position().y() );
}

void MarkerSet::sort_by_y_axis() {
    this->sort(MarkerSet::compare_by_y_axis);
}

void MarkerSet::filter_by_type_items() {
    for (MarkerSet::iterator it = this->begin(); it != this->end(); ++it) {
        if (  dynamic_cast<marker::Item*>( (*it) ) ) { continue; }
        
        this->erase(it);
        it--;
    }
}

void MarkerSet::filter_by_type_lists() {
    for (MarkerSet::iterator it = this->begin(); it != this->end(); ++it) {
        if (  dynamic_cast<marker::List*>( (*it) ) ) { continue; }
        
        this->erase(it);
        it--;
    }
}

void MarkerSet::filter_by_visible(int visible) {
    for (MarkerSet::iterator it = this->begin(); it != this->end(); ++it) {
        if ((*it)->visible() == visible) {
            continue;
        }
        
        this->erase(it);
        it--;
    }
}

void MarkerSet::filter_by_aligned_with_marker(marker::Marker* m) {
    for (iterator it = this->begin(); it != this->end(); ++it) {
        if ( (*it)->aligned(m) ) {
            continue;
        }

        this->erase(it);
        it--;
    }
}

void MarkerSet::filter_by_under_marker(marker::Marker* m) {
    for (MarkerSet::iterator it = this->begin(); it != this->end(); ++it) {
        if ( (*it)->under(m) ) {
            continue;
        }
        
        this->erase(it);
        it--;
    }
}

void MarkerSet::filter_by_over_marker(marker::Marker* m) {
    for (MarkerSet::iterator it = this->begin(); it != this->end(); ++it) {
        if ( (*it)->over(m) ) {
            continue;
        }
        
        this->erase(it);
        it--;
    }
}

std::string MarkerSet::text() {
    std::string ret = "MARKERS: [[ ";
    
    BOOST_FOREACH(Marker* m, *this) {
        ret += m->id() + " ";
    }
    ret += "]]";
    
    return ret;
}

}}
