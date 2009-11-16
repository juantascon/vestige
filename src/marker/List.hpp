#ifndef __EMARKERLIST_H
#define __EMARKERLIST_H

#include "../Includes.hpp"

namespace far {
namespace marker {

class List : public Marker
{
	private:
		static const std::string model_file;
		
	protected:
		
	public:
		List (std::string marker_args);
		
		virtual void update();
};

}}

#endif
