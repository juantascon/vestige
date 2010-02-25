#ifndef __VESTIGE_PROBLEM_LISTPROBLEM_HPP
#define __VESTIGE_PROBLEM_LISTPROBLEM_HPP

#include "Problem.hpp"

namespace vestige {
namespace problem {

class ListProblem : public Problem
{
    protected:
        ListProblem();
        std::vector<std::string>* _ids;
        
    public:
        virtual rule::RuleSet* create_rules() = 0;
        virtual int validate_return(state::Node* ret);
};

}}

#endif
