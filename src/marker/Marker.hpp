#ifndef __VESTIGE_MARKER_MARKER_HPP
#define __VESTIGE_MARKER_MARKER_HPP

#include "../lib/osg.hpp"
#include "../lib/osgart.hpp"

#include "../core/Parameters.hpp"
#include "../core/Debug.hpp"

namespace vestige {
namespace marker {

class Marker : public osg::NodeCallback
{
    protected:
        osgART::Marker* _marker;
        osg::MatrixTransform* _model;
        
        int _active;
        std::string _id;
        std::string _ar_id;
        std::string _label;
        
        osg::Vec3 _position;
        int _visible;
        
    public:
        typedef std::vector <Marker*> Vector;
        typedef std::list <Marker*> List;
        typedef std::map <std::string, Marker*> Map;
        
        Marker(std::string marker_args, std::string ar_id);
        
        osgART::Marker* marker();
        osg::MatrixTransform* model();
        std::string id();
        void set_id(std::string id);
        std::string ar_id();
        std::string label();
        void set_label(std::string label);
        
        osg::Vec3 position();
        int visible();
        void capture_info();
        
        int aligned(Marker* m);
        int under(Marker* m);
        int over(Marker* m);

        void add(osg::Node* child);
        
        void operator()(osg::Node* node, osg::NodeVisitor* nv);
        
        virtual void paint() = 0;
        virtual void update() = 0;
        virtual void model_reset();
        virtual void alert(std::string message);
        virtual void set_active(int active);
};

}}

#endif
