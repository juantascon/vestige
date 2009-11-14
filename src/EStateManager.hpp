#ifndef __ESTATEMANAGER_H
#define __ESTATEMANAGER_H

#include "EIncludes.hpp"

class EStateManager
{
	private:
		static EStateManager* _instance;
		
	protected:
		EStateManager();
		
		ENode* do_block(EMarkerBlock* b);
		ENode* do_list(EMarkerList* l);
		
	public:
		static EStateManager* instance();
		
		EState* current;
		
		EState* capture();
		
};

#endif
