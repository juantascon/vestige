#ifndef __ECONTAINER_H
#define __ECONTAINER_H 1

#include "EIncludes.h"
#include <vector>

class EList;
class EBlock;

typedef std::vector <EBlock*> EBlockVector;
typedef std::vector <EList*> EListVector;

class EContainer
{
	private:
		static EContainer* _instance;
	protected:
		EBlockVector _blocks;
		EListVector _lists;
		
		EContainer();
		
	public:
		static EContainer* instance();
		void initialize(osgART::Tracker* tracker);
		
		void addBlock(EBlock *b);
		void addList(EList *b);
		
		EListVector* lists();
		EBlockVector* blocks();
};

#endif
