#ifndef __VESTIGE_MARKER_SWITCH_HPP
#define __VESTIGE_MARKER_SWITCH_HPP

#include "Marker.hpp"
#include "../draw/ToolTip.hpp"

namespace vestige {
namespace marker {

class Switch : public Marker
{
    protected:
        int captured;
        int reset_next;
        draw::ToolTip* tooltip;
        
    public:
        Switch (std::string marker_args);
        
        void capture();
        
        virtual void set_active(int active);
        virtual void alert(std::string message);
        virtual void paint();
        virtual void update();
        virtual void model_reset();
};

}}

#endif
