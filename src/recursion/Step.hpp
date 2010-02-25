#ifndef __VESTIGE_RECURSION_STEP_HPP
#define __VESTIGE_RECURSION_STEP_HPP

#include "../state/State.hpp"
#include "../action/ActionSet.hpp"
#include "../rule/RuleSet.hpp"
#include "../problem/Types.hpp"

#include "StatusMessage.hpp"

namespace vestige {
namespace recursion {

class Step
{
    protected:
        Step();
        
        problem::Problem* p;
        rule::RuleSet* r;
        
        state::State* previous_state;
        state::State* current_state;
        
    public:
        static Step* instance();
        
        StatusMessage* step();
};

}}

#endif
