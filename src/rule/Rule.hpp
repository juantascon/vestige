#ifndef __VESTIGE_RULE_RULE_HPP
#define __VESTIGE_RULE_RULE_HPP

#include "Move.hpp"
#include "Names.hpp"

namespace vestige {
namespace rule {

class Rule
{
    protected:
        Move* _move;
        Names* _names;
        std::string _clause;
        
    public:
        typedef std::vector <Rule*> Vector;
        typedef std::list <Rule*> List;
        
        Rule(Move* move, std::string clause);
        Rule(Move* move, Names* names, std::string clause);
        
        std::string clause();
        Move* move();
        Names* names();
        
        std::string text();
};

}}

#endif
