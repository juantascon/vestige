#ifndef __VESTIGE_RECURSION_STEP_HPP
#define __VESTIGE_RECURSION_STEP_HPP

#include "../state/State.hpp"
#include "../action/ActionSet.hpp"
#include "../action/Logic.hpp"
#include "../rule/RuleSet.hpp"
#include "../problem/Types.hpp"

#include "StatusMessage.hpp"
#include "VariableSet.hpp"

namespace vestige {
namespace recursion {

class Step
{
    protected:
        Step();
        
        problem::Problem* p;
        rule::RuleSet* rs;
        
        state::State* previous_state;
        state::State* current_state;
        
        StatusMessage* initial();
        StatusMessage* recursive();
        
    public:
        static Step* instance();
        
        StatusMessage* step();
        void reset();
};

}}

#endif
