#include "GlobalStorage.hpp"

namespace vestige {
namespace core {

GlobalStorage* GlobalStorage::instance() { return &boost::serialization::singleton<core::GlobalStorage>::get_mutable_instance(); }

GlobalStorage::GlobalStorage()
{
}

}}
