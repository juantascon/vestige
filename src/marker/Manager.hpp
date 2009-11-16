#ifndef __EMARKERCONTAINER_H
#define __EMARKERCONTAINER_H

#include "../Includes.hpp"

namespace far {
namespace marker {

//TODO: usar boost singleton

class Manager : public Vector
{
	private:
		static Manager* _instance;
		
	protected:
		Manager();
		
	public:
		static Manager* instance();
		
		osgART::Tracker* tracker;
		osg::Camera* camera;
		
		void add(marker::Marker *m);
};

}}

#endif
