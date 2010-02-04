#ifndef __FAR_ACTION_INVALID_HPP
#define __FAR_ACTION_INVALID_HPP

#include "Action.hpp"

namespace far {
namespace action {

class Invalid : public Action
{
	protected:
	public:
		Invalid(state::Node* item);
		
		virtual std::string text();
};

}}

#endif
