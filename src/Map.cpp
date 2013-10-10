#include <Map.h>
#include <stdio.h>

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/multi_array.hpp>

namespace dngine{
	Map::Map(std::string name, SDL_Renderer *r){
		filename = name;
		renderer = r;
		load();
		load_spritesheet();
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

		//Loads tile properties
		BOOST_FOREACH(ptree::value_type &v, pt.get_child("tiles"))
		{
			properties p;
			int number =  atoi(v.first.data());
			BOOST_FOREACH(ptree::value_type &v2, v.second)
			{
				p.insert(std::pair<std::string,std::string>(v2.first.data(), v2.second.data()));
			}
			tile_info.insert(std::pair<int,properties>(number, p));
		}
	}

	void Map::load_spritesheet(){
		SDL_Rect clip_size;
		clip_size.x=clip_size.y=0;
		clip_size.w=clip_size.h=80;
		spritesheet = new SpriteSheet(renderer, tilesheet, &clip_size, 3, 0);
		spritesheet->set_clip(2,0);
		spritesheet->set_location(0,0,80,80);
	}

	void Map::render(){
		spritesheet->render();
	}
}
