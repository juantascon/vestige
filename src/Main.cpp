#include "Includes.hpp"
#include "core/Initializer.hpp"

int main(int argc, char* argv[]) {
	far::core::Initializer::instance()->initialize();
	return far::core::Initializer::instance()->execute();
}
