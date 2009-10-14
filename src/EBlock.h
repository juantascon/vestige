#ifndef __EBlOCK_H
#define __EBLOCK_H 1

#include "EMarker.h"

class BlockManager;

class EBlock : public EMarker
{
	private:
		static const std::string model_file;
	
	public:
		EBlock (osgART::Tracker* tracker, std::string marker_args);
		virtual void update();
};

#endif
