#ifndef __VESTIGE_PROBLEM_REVERSE_HPP
#define __VESTIGE_PROBLEM_REVERSE_HPP

#include "Problem.hpp"

namespace vestige {
namespace problem {

class Reverse : public Problem
{
	protected:
		std::vector<std::string>* _return_items_ids;
		
	public:
		Reverse();
		
		virtual int initialize(state::State* s);
		virtual int validate_return(state::Node* ret);
};

}}

#endif
