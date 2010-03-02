#ifndef __VESTIGE_PROBLEM_REMOVEALL_HPP
#define __VESTIGE_PROBLEM_REMOVEALL_HPP

#include "ListReturn.hpp"

namespace vestige {
namespace problem {

class RemoveAll : public ListReturn
{
    protected:
        state::List* TMP1;
        state::List* TMP2;
        state::List* L;
        state::Item* E;
        
    public:
        RemoveAll(state::State* s);
        
        virtual rule::RuleSet* create_rules();
};

}}

#endif
