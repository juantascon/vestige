#ifndef __VESTIGE_CORE_GLOBALSTORAGE_HPP
#define __VESTIGE_CORE_GLOBALSTORAGE_HPP

#include "../lib/osg.hpp"
#include "../lib/osgart.hpp"
#include "../lib/boost.hpp"

namespace vestige {
namespace core {

class GlobalStorage
{
    protected:
        GlobalStorage();
        
    public:
        static GlobalStorage* instance();
        
        // OSG General
        osgART::Tracker* tracker;
        osg::Camera* camera;
};

}}

#endif
