#ifndef __FAR_PROBLEM_VARIABLES_HPP
#define __FAR_PROBLEM_VARIABLES_HPP

#include <limits>

#include "../state/Types.hpp"

namespace far {
namespace problem {

class Variables
{
	protected:
		state::State* s;
		state::Node::Vector* _assigned_items;
		
	public:
		Variables(state::State* s);
		
		int valid_size(int size);
		state::List* next_list_by_size_range(int min, int max);
};

}}

#endif