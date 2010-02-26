#ifndef __VESTIGE_MARKER_NODESET_HPP
#define __VESTIGE_MARKER_NODESET_HPP

#include <limits>

#include "Types.hpp"

namespace vestige {
namespace state {

class NodeSet : public Node::List
{
    protected:
        
    public:
        NodeSet();
        
        NodeSet* clone();
        
        void filter_by_type_items();
        void filter_by_type_lists();
        void filter_by_no_parent();

        state::Item* remove_single_item();
        state::List* remove_single_list_by_size_range(int min, int max);
        
        std::string text();
};

}}

#endif
