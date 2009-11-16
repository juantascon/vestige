#ifndef __ENODE_H
#define __ENODE_H 1

class ENode
{
	public:
		ENode();
		
		ENode* parent;
		
		virtual void print();
};

typedef std::vector <ENode*> ENodeVector;

#endif
