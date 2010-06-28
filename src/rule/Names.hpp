#ifndef __VESTIGE_RULE_NAMES_HPP
#define __VESTIGE_RULE_NAMES_HPP

#include "../state/State.hpp"
#include "../state/Types.hpp"

namespace vestige {
namespace rule {

class Names : public std::map<std::string, std::string>
{
    protected:
        
    public:
        Names();
        Names* clone();
        
        void set_labels(state::State* s);

        std::string text();
};

}}

#endif
