#include "GlobalStorage.hpp"

namespace far {
namespace core {

GlobalStorage* GlobalStorage::instance() { return &boost::serialization::singleton<far::core::GlobalStorage>::get_mutable_instance(); }

GlobalStorage::GlobalStorage()
{
}

}}
