#include "VariableSet.hpp"

namespace vestige {
namespace recursion {

VariableSet::VariableSet() {
    list_index = 'P';
    item_index = 'E';
    head_index = 'I';
}

Variable* VariableSet::find_by_node_id(std::string id) {
    BOOST_FOREACH(Variable* var, *this) {
        if ( var->node()->id() == id ) {
            return var;
        }
    }
    
    return NULL;
}

void VariableSet::fill(state::State* s) {
    state::NodeSet* inputs = s->clone_nodes();
    inputs->filter_by_no_parent();
    inputs->sort_by_index_x();
    
    BOOST_FOREACH(state::Node* n, *inputs) {
        D(( "ADD NODE (%s)", n->id().c_str() ));
        Variable* var = new Variable(n);
        
        if (dynamic_cast<state::Item*>(n)) {
            var->in_main = item_index;
            var->out_main = item_index;
            item_index++;
        }
        else {
            var->in_main = list_index;
            var->out_main = list_index;
            list_index++;
        }
        
        this->push_back(var);
    }
}

void VariableSet::parse(action::ActionSet* as) {
    BOOST_FOREACH(action::Action *a, *as) {
        // TODO: this doesnt work for items
        if (dynamic_cast<action::Create*>(a)) {
            Variable* var = new Variable(a->node());
            var->out_main = "[]";
            this->push_back(var);
        }
        
        else if (dynamic_cast<action::Discard*>(a)) {
            Variable* var = find_by_node_id(a->node()->id());
            // if !var then var is on top of a list, we should find its parent
            if (!var) {
                var = find_by_node_id(a->node()->parent()->id());
                var->in_head = head_index;
                head_index++;
            }
            else {
                var->out_main = "";
            }
        }
        
        // TODO: not implemented
        else if (dynamic_cast<action::Pop*>(a)) {
        }
        
        // TODO: not implemented
        else if (dynamic_cast<action::Push*>(a)) {
        }
        
        else if (dynamic_cast<action::PopPush*>(a)) {
            action::PopPush* pp = dynamic_cast<action::PopPush*>(a);
            
            Variable* from = find_by_node_id(pp->from()->id());
            from->in_head = head_index;
            Variable* into = find_by_node_id(pp->into()->id());
            into->out_head = head_index;
            
            head_index++;
        }
    }
}

std::string VariableSet::erlang() {
    std::string ret = "f(";
    
    int first = 1;
    BOOST_FOREACH(Variable* v, *this) {
        if (v->in_main.size() == 0) { continue; }
        
        if (first) { first = 0; }
        else { ret += ", "; }
        
        ret += (v->in_head.size() == 0) ? v->in_main : "["+v->in_head+"|"+v->in_main+"]";
    }
    
    ret += ") ->\n f(";
    
    first = 1;
    BOOST_FOREACH(Variable* v, *this) {
        if (v->out_main.size() == 0) { continue; }
        
        if (first) { first = 0; }
        else { ret += ", "; }
        
        ret += v->out_head.size() == 0 ? v->out_main : "["+v->out_head+"|"+v->out_main+"]";
    }
    
    ret += ");";
    
    return ret;
}

}}
