#ifndef __VESTIGE_PROBLEM_REMOVEFIRST_HPP
#define __VESTIGE_PROBLEM_REMOVEFIRST_HPP

#include "ListProblem.hpp"

namespace vestige {
namespace problem {

class RemoveFirst : public ListProblem
{
    protected:
        state::Node* TMP1;
        state::Node* TMP2;
        state::Node* L;
        state::Node* E;
        
    public:
        RemoveFirst(state::State* s);
        
        virtual rule::RuleSet* create_rules();
};

}}

#endif
