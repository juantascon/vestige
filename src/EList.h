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
		std::vector <EBlock*> _blocks;
		
	public:
		EList (std::string marker_args);
		
		void add(EBlock *b);
		void del(EBlock *b);
		void clear();
		
		void print();
		
		void reset();
		virtual void update();
};

#endif
