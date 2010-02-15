#ifndef __VESTIGE_STATE_NODE_HPP
#define __VESTIGE_STATE_NODE_HPP

#include "../marker/Marker.hpp"

namespace vestige {
namespace state {

class Node
{
	private:
		void _initialize(std::string id, marker::Marker* m, Node* parent, int index);
		
	public:
		typedef std::vector <Node*> Vector;
		typedef std::list <Node*> List;
		
		Node(marker::Marker *m);
		Node(std::string id);
		
		std::string id;
		marker::Marker* m;
		Node* parent;
		int index;
		
		virtual std::string text() = 0;
		virtual Node::List* flat_view();
		
		std::string path();
};

}}

#endif
