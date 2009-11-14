#ifndef __ESTATEMANAGER_H
#define __ESTATEMANAGER_H

#include "EIncludes.hpp"

class EStateManager
{
	private:
		static EStateManager* _instance;
		
	protected:
		EStateManager();
		
	public:
		static EStateManager* instance();
		
		EState* current;
		
		EState* capture();
		
};

#endif
