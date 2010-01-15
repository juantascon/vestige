#ifndef __FAR_CORE_GLOBALSTORAGE_HPP
#define __FAR_CORE_GLOBALSTORAGE_HPP

#include "../lib/osgart.hpp"

#include "../marker/Marker.hpp"
#include "../state/State.hpp"
#include "../problem/Problem.hpp"

namespace far {
namespace core {

class GlobalStorage
{
	protected:
		GlobalStorage();
		
	public:
		static GlobalStorage* instance();
		
		// OSG General
		osgART::Tracker* tracker;
		osg::Camera* camera;
		
		// Markers
		marker::Marker::Vector markers;
		void add_marker(marker::Marker *m);
		marker::Marker::List* sorted_markers_y_axis();
		
		// States
		state::State* current_state;
		state::State* previous_state;
		state::State* first_state;
		
		// Problem
		problem::Problem* current_problem;
		
		// Rules
		rule::RuleSet* rules;
		
};

}}

#endif
