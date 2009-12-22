#ifndef __FAR_MARKER_SWITCH_HPP
#define __FAR_MARKER_SWITCH_HPP

#include "Marker.hpp"

namespace far {
namespace marker {

class Switch : public Marker
{
	private:
		static const std::string model_file;
		
	protected:
		static int captured;
		
	public:
		Switch (std::string marker_args, std::string id);
		
		virtual void update();
};

}}

#endif
