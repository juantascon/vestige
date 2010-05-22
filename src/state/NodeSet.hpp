#ifndef __VESTIGE_MARKER_NODESET_HPP
#define __VESTIGE_MARKER_NODESET_HPP

#include <limits>

#include "Types.hpp"

namespace vestige {
namespace state {

class NodeSet : public Node::List
{
    protected:
        static bool compare_by_item_value(Node* n1, Node *n2);
        
    public:
        NodeSet();
        
        NodeSet* clone();
        
        void sort_by_item_value();
        void filter_by_type_items();
        void filter_by_type_lists();
        void filter_by_no_parent();
        
        state::Node* remove_by_id(std::string id);
        state::Item* remove_single_item();
        state::List* remove_single_list();
        state::List* remove_single_list_by_size_range(int min, int max);
        
        std::string text();
};

}}

#endif
