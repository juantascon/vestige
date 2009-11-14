#ifndef __EMARKERBLOCK_H
#define __EMARKERBLOCK_H 1

#include "EMarker.hpp"
#include "ELabel.hpp"

class EMarkerBlock : public EMarker
{
	private:
		static const std::string model_file;
		
	public:
		EMarkerBlock(std::string marker_args, std::string key);
		
		ELabel *label;
		
		virtual void update();
};

#endif
