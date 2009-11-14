#ifndef __EMARKERLIST_H
#define __EMARKERLIST_H 1

#include "EMarker.hpp"
#include "EVectorTypes.hpp"

class EMarkerList : public EMarker
{
	private:
		static const std::string model_file;
		
	protected:
		
	public:
		EMarkerList (std::string marker_args);
		
		virtual void update();
};

#endif
