#ifndef __ECONTAINER_H
#define __ECONTAINER_H 1

#include <vector>

#include "EIncludes.hpp"
#include "EVectorTypes.hpp"

class EContainer
{
	private:
		static EContainer* _instance;
		
	protected:
		EBlockVector _blocks;
		EListVector _lists;
		
		osgART::Tracker* _tracker;
		
		EContainer();
		
	public:
		static EContainer* instance();
		void initialize();
		
		void addBlock(EBlock *b);
		EBlockVector* blocks();
		
		void addList(EList *b);
		EListVector* lists();
		
		void setTracker(osgART::Tracker* tracker);
		osgART::Tracker* tracker();
};

#endif
