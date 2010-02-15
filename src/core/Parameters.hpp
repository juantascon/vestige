#ifndef __VESTIGE_CORE_PARAMETERS_HPP
#define __VESTIGE_CORE_PARAMETERS_HPP

#include "../lib/boost.hpp"

namespace vestige {
namespace core {

class Parameters
{
	protected:
		Parameters();
				
	public:
		static Parameters* instance();
		
		float ALIGN_FACTOR();
		float BLOCK_SIZE();

};

}}

#endif
