#ifndef __ELIST_H
#define __ELIST_H 1

#include "EMarker.h"
#include "EBlock.h"

class EList : public EMarker
{
	private:
		static const std::string model_file;
		
	public:
		EList (osgART::Tracker* tracker, osg::NodeCallback* callback, std::string marker_args);
		int block_aligned(EBlock* b);
};

#endif

