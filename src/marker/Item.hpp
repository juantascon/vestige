#ifndef __VESTIGE_MARKER_ITEM_HPP
#define __VESTIGE_MARKER_ITEM_HPP

#include "Marker.hpp"

#include "../draw/Rectangle.hpp"
#include "../draw/Text.hpp"
#include "../draw/ToolTip.hpp"

namespace vestige {
namespace marker {

class Item : public Marker
{
    protected:
        int _top;
        std::string _value;
        std::string _label;
        
    public:
        Item(std::string marker_args, std::string ar_id, std::string value);
        
        void set_top(int top);
        
        std::string value();
        std::string label();
        
        virtual void update();
        virtual void paint();
        virtual void alert(std::string message);
};

}}

#endif
