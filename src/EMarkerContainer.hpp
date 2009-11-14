#ifndef __EMARKERCONTAINER_H
#define __EMARKERCONTAINER_H

#include "EIncludes.hpp"

//TODO: usar boost singleton
class EMarkerContainer : public EMarkerVector
{
	private:
		static EMarkerContainer* _instance;
		
	protected:
		EMarkerContainer();
		
	public:
		static EMarkerContainer* instance();
		
		osgART::Tracker* tracker;
		osg::Camera* camera;
		
		void add(EMarker *m);
};

#endif
