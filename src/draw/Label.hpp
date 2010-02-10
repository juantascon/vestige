#ifndef __FAR_DRAW_LABEL_HPP
#define __FAR_DRAW_LABEL_HPP

#include "../lib/osg.hpp"

namespace far {
namespace draw {

class Label
{
	protected:
		std::string _value;
		
	public:
		Label(std::string value);
		
		std::string get_value();
		void set_value(std::string value);
		
		osg::Node* model();
};

}}

#endif
