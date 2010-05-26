#include "PDebug.hpp"

namespace vestige {
namespace problem {

PDebug::PDebug(state::State* s) : Problem()
{
    calls = 0;
}

rule::RuleSet* PDebug::create_rules() {
    return (new rule::RuleSet());
}

int PDebug::validate_return(state::State* ret) {
    D(("calls: %i", calls));
    if (calls >= 5) {
        return 1;
    }
    else {
        calls++;
        return 0;
    }
}

}}
