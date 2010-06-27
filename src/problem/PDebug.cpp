#include "PDebug.hpp"

namespace vestige {
namespace problem {

PDebug::PDebug(state::State* s) : Problem()
{
    calls = 0;
}

rule::RuleSet* PDebug::create_rules() {
    rule::RuleSet* rs = new rule::RuleSet();
    rs->add(new rule::Pop("I#0", "L#0", "function([I|L]) -> function(L,I);"));
    rs->add(new rule::Push("I#0", "L#0", "function(L,I) -> function([I|L]);"));
    rs->add(new rule::Create("L#1", "function(L) -> function(L,M);"));
    rs->add(new rule::PopPush("I#0", "L#0", "L#1", "function([I|L], M) -> function(L,[I|M]);"));
    rs->add(new rule::Discard("I#1", "function([I|L], M) -> function(L,M);"));
    
    return rs;
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
