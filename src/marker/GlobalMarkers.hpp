#ifndef __VESTIGE_MARKER_GLOBALMARKERS_HPP
#define __VESTIGE_MARKER_GLOBALMARKERS_HPP

#include "Types.hpp"
#include "MarkerSet.hpp"

namespace vestige {
namespace marker {

class GlobalMarkers
{
    protected:
        GlobalMarkers();
        
        std::string patt_format(std::string patt);
        
        marker::MarkerSet* _markers;
        int lists_count;
        int items_count;
        
    public:
        static GlobalMarkers* instance();
        
        void markers_initialize();
        void markers_reset();
        void markers_add(marker::Marker *m);
        marker::MarkerSet* markers_clone();
        
        void assign_empty_ids();
        
        marker::Switch* m_switch;
};

}}

#endif
