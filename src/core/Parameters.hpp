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
        typedef enum Phase {
            PHASE_CONCRETE,
            PHASE_INFORMATION_HIDDING,
            PHASE_VARIABLES
        } Phase;
        
        static Parameters* instance();
        float ALIGN_FACTOR();
        float MARKER_SIZE();
        std::string ROOT();
        std::string PROBLEM();
        std::string VIDEOFILE();
        int PHASE();
};

}}

#endif
