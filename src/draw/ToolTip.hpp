#ifndef __VESTIGE_DRAW_TOOLTIP_HPP
#define __VESTIGE_DRAW_TOOLTIP_HPP

#include "../lib/osg.hpp"

#include "Rectangle.hpp"
#include "Text.hpp"

namespace vestige {
namespace draw {

class ToolTip : public osg::Geode
{
    protected:
        
    public:
        ToolTip();
        
        void model_reset();
        
        void alert(std::string value, float size);
        void alert(std::string value);

};

}}

#endif
