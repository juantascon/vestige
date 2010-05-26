#ifndef __VESTIGE_RECURSION_VARIABLESET_HPP
#define __VESTIGE_RECURSION_VARIABLESET_HPP

#include "../state/State.hpp"
#include "../state/Types.hpp"
#include "../action/ActionSet.hpp"
#include "../action/Types.hpp"

#include "StatusMessage.hpp"
#include "Variable.hpp"

namespace vestige {
namespace recursion {

class VariableSet : public Variable::List
{
    protected:
        char list_index;
        char item_index;
        char head_index;
        
    public:
        VariableSet();
        
        Variable* find_by_node_id(std::string id);
        
        void fill(state::State* s);
        void parse(action::ActionSet* as);
        
        std::string erlang();
};

}}

#endif
