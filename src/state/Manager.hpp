#ifndef __ESTATEMANAGER_H
#define __ESTATEMANAGER_H

#include "../Includes.hpp"

namespace far{
namespace state{

//TODO: usar boost singleton
class Manager
{
	private:
		static Manager* _instance;
		
	protected:
	Manager();
		
		Node* do_block(marker::Block* b);
		Node* do_list(marker::List* l);
		
	public:
		static Manager* instance();
		
		State* current;
		State* capture();
		
};

}}

#endif
