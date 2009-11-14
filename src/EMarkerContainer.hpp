#ifndef __EMARKERCONTAINER_H
#define __EMARKERCONTAINER_H 1

#include "EIncludes.hpp"
#include "EVectorTypes.hpp"

class EMarker;

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
