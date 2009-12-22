#ifndef __FAR_MARKER_BLOCK_HPP
#define __FAR_MARKER_BLOCK_HPP

#include "Marker.hpp"
#include "../Var.hpp"

namespace far {
namespace marker {

class Block : public Marker
{
	private:
		static const std::string model_file;
		
	public:
		Block(std::string marker_args, std::string id, std::string key);
		
		Var *label;
		
		virtual void update();
};

}}

#endif
