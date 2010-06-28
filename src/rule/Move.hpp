/**
 * Moves:
 *
 * - (discard) discard a node
 * - (create) create a node
 * - (pop) move an item *from* a list to the board
 * - (push) move an item from the board *into* a list
 * - (pop-push) move an item *from* a list *into* another
 *
 * ** Board is the base where all the nodes are on
 *
 **
 */

#ifndef __VESTIGE_RULE_MOVE_HPP
#define __VESTIGE_RULE_MOVE_HPP

#include "../action/Action.hpp"

namespace vestige {
namespace rule {

class Move
{
    protected:
        std::string _node;
        
    public:
        Move(std::string node);
        
        virtual int valid(action::Action* action);
        virtual std::string text() = 0;
};

}}

#endif
