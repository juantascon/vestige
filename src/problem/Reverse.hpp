#ifndef __FAR_PROBLEM_REVERSE_HPP
#define __FAR_PROBLEM_REVERSE_HPP

#include "Problem.hpp"

namespace far {
namespace problem {

class Reverse : public Problem
{
	protected:
		std::vector<std::string>* _final_output;
		
		state::List* find_input(state::State* s);
		state::List* find_output(state::State* s);
		
	public:
		Reverse();
		
		virtual int initialize(state::State* s);
		virtual int valid_final_state(state::State* s);
};

}}

#endif
