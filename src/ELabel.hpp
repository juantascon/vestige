#ifndef __ELABEL_H
#define __ELABEL_H

#include "EIncludes.hpp"

class ELabel
{
	protected:
		std::string _key;
		std::string _value;
		
	public:
		ELabel(std::string key, std::string value);
		
		std::string get_key();
		std::string get_value(); 
		
		void set_key(std::string key);
		void set_value(std::string value);
		
		std::string text();
		osg::Node* model();
};

#endif
