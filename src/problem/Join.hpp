#ifndef __FAR_PROBLEM_JOIN_HPP
#define __FAR_PROBLEM_JOIN_HPP

#include "Problem.hpp"

namespace far {
namespace problem {

class Join : public Problem
{
	protected:
		std::vector<std::string>* _return_items_ids;
		
	public:
		Join();
		
		virtual int initialize(state::State* s);
		virtual int validate_return(state::Node* ret);
};

}}

#endif
