#ifndef __VESTIGE_MARKER_NODESET_HPP
#define __VESTIGE_MARKER_NODESET_HPP

#include <limits>

#include "Node.hpp"
#include "../marker/Types.hpp"

namespace vestige {
namespace state {

class NodeSet : public Node::List
{
	protected:
		
	public:
		NodeSet();
		
		NodeSet* clone();
		
		void filter_by_type(int blocks, int lists);
		void filter_by_no_parent();
		state::Node* filter_single_by_size_range(int min, int max);
		
		std::string text();
};

}}

#endif
