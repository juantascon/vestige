#include "Parameters.hpp"

namespace vestige {
namespace core {

Parameters* Parameters::instance() { return &boost::serialization::singleton<core::Parameters>::get_mutable_instance(); }

Parameters::Parameters()
{
}

// factor of alignment, used to calculate when an item belongs to a list
// bigger values could mean more items
float Parameters::ALIGN_FACTOR() { return 40.0; }
// blocks size when drawing
float Parameters::MARKER_SIZE() { return 90.0; }
std::string Parameters::ROOT() { return "/home/jdi/dev/vestige/"; }

}}
