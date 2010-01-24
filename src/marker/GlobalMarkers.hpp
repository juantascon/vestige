#ifndef __FAR_MARKER_GLOBALMARKERS_HPP
#define __FAR_MARKER_GLOBALMARKERS_HPP

#include "Types.hpp"

namespace far {
namespace marker {

class GlobalMarkers
{
	protected:
		GlobalMarkers();
		
		marker::Marker::Vector _items;
		
	public:
		static GlobalMarkers* instance();
		
		void add(marker::Marker *m);
		marker::Marker::List* sort_y_axis();
		
		marker::Output* m_output;
		marker::Switch* m_switch;
		
};

}}

#endif
#ifndef __FAR_CORE_GLOBALSTORAGE_HPP
#define __FAR_CORE_GLOBALSTORAGE_HPP

#include "../lib/osg.hpp"
#include "../lib/osgart.hpp"
#include "../lib/boost.hpp"

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
		
};

}}

#endif
