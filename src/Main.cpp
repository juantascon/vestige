#include "Includes.hpp"

int main(int argc, char* argv[]) {
	far::Initializer::instance()->initialize();
	return far::Initializer::instance()->execute();
}
