/**
 * Rules:
 *
 * - (pop) move a item from a list (*from*) to the board
 * - (push) move a item from the board to a list (*into*)
 * - (pop-push) move a item from a list (*from*) to another (*into*)
 *
 * - (discard) discard a node
 *
 * ** Board is the base where all the nodes are on
 *
 **
 */

#ifndef __VESTIGE_RULE_RULE_HPP
#define __VESTIGE_RULE_RULE_HPP

#include "../action/Action.hpp"

namespace vestige {
namespace rule {

class Rule
{
    protected:
        std::string node;
        
    public:
        typedef std::vector <Rule*> Vector;
        typedef std::list <Rule*> List;
        
        Rule(std::string node);
        
        virtual int valid(action::Action* action);
        virtual std::string text() = 0;
};

}}

#endif
