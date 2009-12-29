#ifndef __FAR_STATE_NODE_HPP
#define __FAR_STATE_NODE_HPP

#include "../Includes.hpp"
#include "../marker/Marker.hpp"

namespace far{
namespace state{

class Node
{
	public:
		typedef std::vector <Node*> Vector;
		typedef std::list <Node*> List;
		
		Node(marker::Marker *m);
		
		Node* parent;
		marker::Marker* m;
		std::string id;
		int index;
		
		virtual void print();
		virtual Node::List* flat_view();
		
		std::string path();
};

}}

#endif
