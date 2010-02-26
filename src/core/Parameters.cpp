#include "Parameters.hpp"

namespace vestige {
namespace core {

Parameters* Parameters::instance() { return &boost::serialization::singleton<core::Parameters>::get_mutable_instance(); }

Parameters::Parameters()
{
}

float Parameters::ALIGN_FACTOR() { return 150.0; }
float Parameters::MARKER_SIZE() { return 110.0; }
std::string Parameters::ROOT() { return "/home/jdi/dev/vestige/"; }

}}
