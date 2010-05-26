#ifndef __VESTIGE_RECURSION_VARIABLE_HPP
#define __VESTIGE_RECURSION_VARIABLE_HPP

#include "../state/Types.hpp"

namespace vestige {
namespace recursion {

class Variable
{
    protected:
        state::Node* _node;
        
    public:
        typedef std::vector <Variable*> Vector;
        typedef std::list <Variable*> List;
        
        state::Node* node();
        
        std::string in_main;
        std::string in_head;
        std::string out_main;
        std::string out_head;
        
        Variable(state::Node* node);
        
        Variable* clone();
        
        std::string text();
};

}}

#endif
