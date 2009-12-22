#ifndef __FAR_ACTION_ACTION_HPP
#define __FAR_ACTION_ACTION_HPP

#include "../state/Node.hpp"

namespace far {
namespace action {

class Action
{
	protected:
		state::Node* item;
		int type;
		
	public:
		typedef std::vector <Action*> Vector;
		enum Type { PopPush, Pop, Push, DiscardBlock, DiscardList, Invalid, None };
		static std::string type_to_string(int type);
		
		Action(state::Node* item, int type);
		
		void alert();
		void print();
};

}}

#endif
