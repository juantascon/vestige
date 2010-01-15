#ifndef __FAR_MARKER_BLOCK_HPP
#define __FAR_MARKER_BLOCK_HPP

#include "Marker.hpp"
#include "Var.hpp"
#include "../core/DrawHelper.hpp"

namespace far {
namespace marker {

class Block : public Marker
{
	protected:
		osg::Node* background(int valid);
		
	public:
		Block(std::string marker_args, std::string id, std::string key);
		
		Var *label;
		
		virtual void update();
		virtual void alert(std::string message);
};

}}

#endif
