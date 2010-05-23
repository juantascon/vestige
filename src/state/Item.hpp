#ifndef __VESTIGE_STATE_ITEM_HPP
#define __VESTIGE_STATE_ITEM_HPP

#include "Node.hpp"
#include "../marker/Item.hpp"

namespace vestige {
namespace state {

class Item : public Node
{
    protected:
        std::string _value;
        
    public:
        Item(marker::Item* marker);
        
        std::string value();
        int ivalue();
};

}}

#endif
