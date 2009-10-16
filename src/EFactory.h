#ifndef __EFACTORY_H
#define __EFACTORY_H 1

#include "EIncludes.h"
#include "EBlock.h"
#include "EList.h"

#include <vector>

class EFactory
{
	private:
		static EFactory* _instance;
		
	protected:
		osgART::Tracker* tracker;
		
		EFactory();
		
	public:
		static EFactory* instance();
		
		void initialize(osgART::Tracker* tracker);
		void addModelsToCam(osg::Camera* cam);
};

#endif
