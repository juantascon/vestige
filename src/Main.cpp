#include "EFactory.hpp"

int main(int argc, char* argv[]) {
	EFactory::instance()->initialize();
	return EFactory::instance()->execute();
}
