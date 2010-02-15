#include "Parameters.hpp"

namespace vestige {
namespace core {

Parameters* Parameters::instance() { return &boost::serialization::singleton<core::Parameters>::get_mutable_instance(); }

Parameters::Parameters()
{
}

float Parameters::ALIGN_FACTOR() { return 110.0; }
float Parameters::BLOCK_SIZE() { return 110.0; }

}}
