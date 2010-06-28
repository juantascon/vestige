#ifndef __VESTIGE_RULE_RULE_HPP
#define __VESTIGE_RULE_RULE_HPP

#include "Move.hpp"

namespace vestige {
namespace rule {

class Rule
{
    protected:
        Move* _move;
        std::string _clause;
        
    public:
        typedef std::vector <Rule*> Vector;
        typedef std::list <Rule*> List;
        
        Rule(Move* move, std::string clause);
        
        std::string clause();
        Move* move();
        
        std::string text();
};

}}

#endif
