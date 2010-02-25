#ifndef __VESTIGE_PROBLEM_REVERSE_HPP
#define __VESTIGE_PROBLEM_REVERSE_HPP

#include "ListReturn.hpp"

namespace vestige {
namespace problem {

class Reverse : public ListReturn
{
    protected:
        state::List* L;
        state::List* R;
        
    public:
        Reverse(state::State* s);
        
        virtual rule::RuleSet* create_rules();
};

}}

#endif
