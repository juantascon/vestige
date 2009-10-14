#ifndef __ELIST_H
#define __ELIST_H 1

#include <vector>

#include "EMarker.h"
#include "EBlock.h"

class EList : public EMarker
{
	private:
		static const std::string model_file;
		
	protected:
		std::vector <EBlock*> blocks;
		
	public:
		EList (osgART::Tracker* tracker, std::string marker_args);
		
		void add(EBlock *b);
		void del(EBlock *b);
		void clear();
		
		void print();
		
		int block_aligned(EBlock* b);
		virtual void update();
};

#endif
