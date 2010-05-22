#ifndef __VESTIGE_PROBLEM_PROBLEM_HPP
#define __VESTIGE_PROBLEM_PROBLEM_HPP

#include "../state/State.hpp"
#include "../rule/RuleSet.hpp"
#include "../rule/Types.hpp"

#include <stdexcept>
#include <algorithm>

namespace vestige {
namespace problem {

class Problem
{
    protected:
        Problem();
        
    public:
        virtual rule::RuleSet* create_rules() = 0;
        virtual int validate_return(state::State* state) = 0;
};

}}

#endif
