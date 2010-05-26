#ifndef __VESTIGE_PROBLEM_PDEBUG_HPP
#define __VESTIGE_PROBLEM_PDEBUG_HPP

#include "ListReturn.hpp"

namespace vestige {
namespace problem {

class PDebug : public Problem
{
    protected:
        int calls;
    public:
        PDebug(state::State* s);
        
        virtual rule::RuleSet* create_rules();
        virtual int validate_return(state::State* ret);
};

}}

#endif
