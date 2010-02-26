#ifndef __VESTIGE_PROBLEM_REMOVEFIRST_HPP
#define __VESTIGE_PROBLEM_REMOVEFIRST_HPP

#include "ListReturn.hpp"

namespace vestige {
namespace problem {

class RemoveFirst : public ListReturn
{
    protected:
        state::List* TMP1;
        state::List* TMP2;
        state::List* L;
        state::Item* E;
        
    public:
        RemoveFirst(state::State* s);
        
        virtual rule::RuleSet* create_rules();
};

}}

#endif
