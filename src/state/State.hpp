#ifndef __ESTATE_H
#define __ESTATE_H

#include "EIncludes.hpp"

class EState : public ENodeList
{
	protected:
		
	public:
		EState();
		
		EState* previous;
		EState* next;
		
		virtual void print();
};

#endif
