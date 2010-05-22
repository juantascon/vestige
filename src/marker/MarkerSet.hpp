#ifndef __VESTIGE_MARKER_MARKERSET_HPP
#define __VESTIGE_MARKER_MARKERSET_HPP

#include "Types.hpp"

namespace vestige {
namespace marker {

class MarkerSet : public Marker::List
{
    protected:
        static bool compare_by_y_axis(Marker* m1, Marker *m2);
        static bool compare_by_x_axis(Marker* m1, Marker *m2);
        
    public:
        MarkerSet();
        
        MarkerSet* clone();
        void sort_by_y_axis();
        void sort_by_x_axis();
        
        void filter_by_type_items();
        void filter_by_type_lists();
        void filter_by_visible(int visible);
        void filter_by_aligned_with_marker(marker::Marker* m);
        void filter_by_under_marker(marker::Marker* m);
        void filter_by_over_marker(marker::Marker* m);
        
        std::string text();
};

}}

#endif
