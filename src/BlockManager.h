#ifndef __BLOCKMANAGER_H
#define __BLOCKMANAGER_H 1

#include <vector>

#include "EList.h"

class BlockManager : public osg::NodeCallback
{
	private:
		
	protected:
		std::vector <EBlock*> blocks;
		std::vector <EList*> lists;
		osgART::Tracker* tracker;
		
	public:
		void addBlock(std::string marker_args);
		void addList(std::string marker_args);
		void addModelsToCam(osg::Camera* cam);
		
		BlockManager (osgART::Tracker* tracker);
		virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
};

#endif

