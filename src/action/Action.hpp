/**
 * Actions:
 *
 * - (pop) move a item from a list to the board
 * - (push) move a item from the board to a list
 * - (pop-push) move a item from a list to another
 *
 * - (discard) discard a node
 * - (create) create a node
 * - (invalid) invalid movement
 *
 * ** Board is the base where all the nodes are on
 *
 **
 */

#ifndef __VESTIGE_ACTION_ACTION_HPP
#define __VESTIGE_ACTION_ACTION_HPP

#include "../state/Node.hpp"

namespace vestige {
namespace action {

class Action
{
    protected:
        state::Node* _node;
        
    public:
        typedef std::vector <Action*> Vector;
        
        Action(state::Node* node);
        
        state::Node* node();
        
        int valid_rules;
        
        void alert(std::string message);
        virtual std::string text() = 0;
};

}}

#endif
