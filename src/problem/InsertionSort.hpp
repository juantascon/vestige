#ifndef __VESTIGE_PROBLEM_INSERTIONSORT_HPP
#define __VESTIGE_PROBLEM_INSERTIONSORT_HPP

#include "ListReturn.hpp"

namespace vestige {
namespace problem {

class InsertionSort : public ListReturn
{
    protected:
        state::List* L;
        
    public:
        InsertionSort(state::State* s);
        
        virtual rule::RuleSet* create_rules();
};

}}

#endif
