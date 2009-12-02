#ifndef __FAR_STATE_STATE_HPP
#define __FAR_STATE_STATE_HPP

#include "List.hpp"

namespace far{
namespace state{

class State : public List
{
	protected:
		
	public:
		State();
		
		State* previous;
		State* next;
		
		virtual void print();
};

}}

#endif
