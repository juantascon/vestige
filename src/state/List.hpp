#ifndef __ENODELIST_H
#define __ENODELIST_H

#include "EIncludes.hpp"

class ENodeList : public ENode
{
	private:
		
	protected:
		ENodeVector _items;
		
	public:
		ENodeList();
		
		void push(ENode* n);
		ENode* pop();
		virtual void print();
};

#endif
