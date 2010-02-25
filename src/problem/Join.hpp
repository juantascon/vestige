#ifndef __VESTIGE_PROBLEM_JOIN_HPP
#define __VESTIGE_PROBLEM_JOIN_HPP

#include "ListReturn.hpp"

namespace vestige {
namespace problem {

class Join : public ListReturn
{
    protected:
        state::List* TMP;
        state::List* L;
        state::List* R;
        
    public:
        Join(state::State* s);
        
        virtual rule::RuleSet* create_rules();
};

}}

#endif
