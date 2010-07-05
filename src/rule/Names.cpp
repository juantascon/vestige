#include "Names.hpp"

namespace vestige {
namespace rule {

Names::Names() : std::map<std::string, std::string>() {
}

Names* Names::clone() {
    Names* ret = new Names();
    
    for(Names::iterator iter = this->begin(); iter != this->end(); iter++) {
        (*ret)[iter->first] = iter->second;
    }
    
    return ret;
}

void Names::set_labels(state::State* s) {
    if (core::Parameters::instance()->PHASE() != core::Parameters::PHASE_VARIABLES) {
        return;
    }
    
    state::NodeSet* ns = s->clone_nodes();
    
    D(( this->text().c_str() ));
    
    for(Names::iterator iter = this->begin(); iter != this->end(); iter++) {
        state::Node* n = ns->remove_by_id(iter->first);
        if (!n) { continue; }
        
        n->marker()->set_label(iter->second);
        n->marker()->update();
    }
}

std::string Names::text() {
    std::string ret = "NAMES: [[ ";

    for(Names::iterator iter = this->begin(); iter != this->end(); iter++) {
        ret += iter->first + ":" + iter->second + " ";
    }
    
    ret += "]]";
    
    return ret;
}

}}
