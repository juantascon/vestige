#ifndef __EMARKERBLOCK_H
#define __EMARKERBLOCK_H

#include "../Includes.hpp"

namespace far {
namespace marker {

class Block : public Marker
{
	private:
		static const std::string model_file;
		
	public:
		Block(std::string marker_args, std::string key);
		
		Var *label;
		
		virtual void update();
};

}}

#endif
