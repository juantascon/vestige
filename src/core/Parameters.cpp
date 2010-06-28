#include "Parameters.hpp"

namespace vestige {
namespace core {

Parameters* Parameters::instance() { return &boost::serialization::singleton<core::Parameters>::get_mutable_instance(); }

Parameters::Parameters()
{
}

// factor of alignment, used to calculate when an item belongs to a list
// bigger values could mean more items
float Parameters::ALIGN_FACTOR() { return 60.0; }

// blocks size when drawing
float Parameters::MARKER_SIZE() { return 90.0; }

// root directory
std::string Parameters::ROOT() { return "/home/jdi/dev/vestige/"; }

// problem to execute
std::string Parameters::PROBLEM() {
    // return "insertionsort";
    // return "compress";
    // return "removeall";
    // return "join";
    return "reverse";
    // return "pdebug";
}

// location of the video, if the file is not found then it will
// fallback to /dev/video0
std::string Parameters::VIDEOFILE() {
    // std::string file = "isuvr/insertionsort.mov";
    // std::string file = "isuvr/compress.mov";
    // std::string file = "isuvr/removeall.mov";
    // std::string file = "isuvr/join.mov";
    std::string file = "isuvr/reverse.mov";
    
    // std::string file = "actions.mov";
    
    return ROOT()+"/video/"+file;
    // return "";
}

int Parameters::PHASE() {
    return PHASE_VARIABLES;
}

}}
