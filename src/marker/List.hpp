#ifndef __VESTIGE_MARKER_LIST_HPP
#define __VESTIGE_MARKER_LIST_HPP

#include "Marker.hpp"

#include "../draw/Rectangle.hpp"

namespace vestige {
namespace marker {

class List : public Marker
{
    protected:
        
    public:
        List (std::string marker_args, std::string id);
        
        virtual void update();
        virtual void paint();
};

}}

#endif
