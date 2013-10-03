#include <Map.h>

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/multi_array.hpp>

namespace dngine{
	Map::Map(std::string name){
		filename = name;
		load();
	}

	void Map::load(){
		using boost::property_tree::ptree;
		ptree pt;

		read_json(filename, pt);

		map_name = pt.get<std::string>("name");
		tilesheet = pt.get<std::string>("tilesheet");
		width = pt.get<int>("width");
		height = pt.get<int>("height");
		map_layout.resize(boost::extents[height][width]);

		//Grabs map layout
		int x=0,y=0;
		BOOST_FOREACH(ptree::value_type &v, pt.get_child("map"))
		{
			BOOST_FOREACH(ptree::value_type &v2, v.second){
				BOOST_FOREACH(int i, v2.second.data()){
					//Makes the char character an int
					map_layout[x][y] = i-'0';
					y++;
				}
			}
			x++;
			y=0;
		}
	}
}
