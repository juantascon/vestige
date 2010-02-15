#ifndef __VESTIGE_DRAW_TEXT_HPP
#define __VESTIGE_DRAW_TEXT_HPP

#include "../lib/osg.hpp"

namespace vestige {
namespace draw {

class Text : public osgText::Text
{
	protected:
		void initialize(std::string value);
		
	public:
		Text(std::string value);
		osg::Geode* wrap();
};

}}

#endif
