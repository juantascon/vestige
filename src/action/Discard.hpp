#ifndef __FAR_ACTION_DISCARD_HPP
#define __FAR_ACTION_DISCARD_HPP

#include "Action.hpp"

namespace far {
namespace action {

class Discard : public Action
{
	protected:
	public:
		Discard(state::Node* item);
		
		std::string text();
};

}}

#endif
