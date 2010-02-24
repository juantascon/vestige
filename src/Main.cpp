#include "core/Initializer.hpp"

int main(int argc, char* argv[]) {
	vestige::core::Initializer::instance()->initialize();
	return vestige::core::Initializer::instance()->execute();
}
