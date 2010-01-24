#ifndef __FAR_PROBLEM_REVERSE_HPP
#define __FAR_PROBLEM_REVERSE_HPP

#include "Problem.hpp"


namespace far {
namespace problem {

class Reverse : public Problem
{
	protected:
		std::vector<std::string>* _final_state;
		
		state::List* get_input(state::State *s);
		state::List* get_output(state::State *s);
		
	public:
		Reverse();
		
		virtual int valid_init_state(state::State* s);
		virtual int valid_final_state(state::State* s);
		
		virtual void prepare_final_state();
		virtual void prepare_rules();
};

}}

#endif
