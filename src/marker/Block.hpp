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
        std::string _key;
        int _top;
        
    public:
        Block(std::string marker_args, std::string id, std::string key);

        void set_top(int top);
        
        virtual void update();
        virtual void paint();
        virtual void alert(std::string message);
};

}}

#endif
