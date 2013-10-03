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

		read_json(map_name, pt);

		map_name = pt.get<std::string>("name");
		width = pt.get<int>("width");
		height = pt.get<int>("height");
	}
}
