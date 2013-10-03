#ifndef _MAP_H_
#define _MAP_H_

#include <string>
#include <boost/multi_array.hpp>

namespace dngine{
	class Map{
		private:
			typedef boost::multi_array<int, 2> map_array;
			typedef map_array::index map_index;

			std::string filename;

			std::string map_name;
			std::string tilesheet;
			map_array map_layout;
			int width;
			int height;
			void load();
		public:
			Map(std::string name);
	};
}

#endif
