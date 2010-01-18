#ifndef __FAR_MARKER_VAR_HPP
#define __FAR_MARKER_VAR_HPP

#include "../lib/osg.hpp"

namespace far {
namespace marker {

class Var
{
	protected:
		std::string _key;
		std::string _value;
		
	public:
		Var(std::string key, std::string value);
		
		std::string get_key();
		std::string get_value(); 
		
		void set_key(std::string key);
		void set_value(std::string value);
		
		std::string text();
		osg::Node* model();
};

}}

#endif