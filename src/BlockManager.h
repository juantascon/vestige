#ifndef __BLOCKMANAGER_H
#define __BLOCKMANAGER_H 1

#include <vector>
#include "EList.h"

class EList;
class EBlock;

class BlockManager
{
	private:
		static BlockManager* _instance;
	protected:
		std::vector <EBlock*> blocks;
		std::vector <EList*> lists;
		osgART::Tracker* tracker;
		BlockManager();
		
	public:
		static BlockManager* instance();
		void initialize(osgART::Tracker* tracker);
		
		void addBlock(std::string marker_args);
		void addList(std::string marker_args);
		void addModelsToCam(osg::Camera* cam);
		
		void blockUpdated(EBlock *b);
		void listUpdated(EList *l);
};

#endif

