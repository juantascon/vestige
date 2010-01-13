#include "Output.hpp"
#include "../core/GlobalStorage.hpp"

namespace far {
namespace marker {

Output::Output(std::string marker_args, std::string id) : Marker(marker_args, id) {
	value = 0;
}

void Output::update() {
}

}}
