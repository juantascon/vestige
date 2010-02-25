#ifndef __VESTIGE_MARKER_RETURN_HPP
#define __VESTIGE_MARKER_RETURN_HPP

#include "Marker.hpp"

#include "../draw/Rectangle.hpp"

namespace vestige {
namespace marker {

class Return : public Marker
{
    protected:
        Marker* _value;
        void update_value();
        
    public:
        Return (std::string marker_args);
        
        Marker* value();
        
        virtual void update();
        virtual void paint();
};

}}

#endif
