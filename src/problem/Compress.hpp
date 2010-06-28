#ifndef __VESTIGE_PROBLEM_COMPRESS_HPP
#define __VESTIGE_PROBLEM_COMPRESS_HPP

#include "ListReturn.hpp"

namespace vestige {
namespace problem {

class Compress : public ListReturn
{
    protected:
        state::List* L;
        
    public:
        Compress(state::State* s);
        
        virtual rule::RuleSet* create_rules();
};

}}

#endif
