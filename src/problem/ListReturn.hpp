#ifndef __VESTIGE_PROBLEM_LISTRETURN_HPP
#define __VESTIGE_PROBLEM_LISTRETURN_HPP

#include "Problem.hpp"

namespace vestige {
namespace problem {

class ListReturn : public Problem
{
    protected:
        ListReturn();
        std::list<std::string>* _ids;
        
    public:
        virtual rule::RuleSet* create_rules() = 0;
        virtual int validate_return(state::State* s);
};

}}

#endif
