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
        
    public:
        static GlobalMarkers* instance();
        
        void markers_add(marker::Marker *m);
        marker::MarkerSet* markers_clone();
        void markers_initialize();
        
        marker::Return* m_return;
        marker::Switch* m_switch;
};

}}

#endif
