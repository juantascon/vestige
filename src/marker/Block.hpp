#ifndef __VESTIGE_MARKER_BLOCK_HPP
#define __VESTIGE_MARKER_BLOCK_HPP

#include "Marker.hpp"

#include "../draw/Rectangle.hpp"
#include "../draw/Text.hpp"
#include "../draw/ToolTip.hpp"

namespace vestige {
namespace marker {

class Block : public Marker
{
    protected:
        int _top;
        std::string _value;
        
    public:
        Block(std::string marker_args, std::string id, std::string value);

        void set_top(int top);

        std::string value();
        
        virtual void update();
        virtual void paint();
        virtual void alert(std::string message);
};

}}

#endif
