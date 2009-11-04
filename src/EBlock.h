#ifndef __EBLOCK_H
#define __EBLOCK_H 1

#include "EMarker.h"
#include "ELabel.h"
#include "EList.h"

class EList;

class EBlock : public EMarker
{
	private:
		static const std::string model_file;
		
	public:
		ELabel *label;
		EList *list;
		
		EBlock (std::string marker_args, std::string key);
		
		void print();
		void reset();
		
		virtual void update();
};

#endif
