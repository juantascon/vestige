#ifndef __VESTIGE_ACTION_LOGIC_HPP
#define __VESTIGE_ACTION_LOGIC_HPP

#include "Types.hpp"
#include "ActionSet.hpp"

namespace vestige {
namespace action {

class Logic
{
    protected:
        Logic();
        
        void set_all_valid(ActionSet* as, int valid);
        
    public:
        static Logic* instance();
        
        void verify(ActionSet* as);
};

}}

#endif
