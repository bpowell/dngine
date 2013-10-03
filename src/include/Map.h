#ifndef _MAP_H_
#define _MAP_H_

#include <string>

namespace dngine{
	class Map{
		private:
			std::string map_name;
			std::string tilesheet;
			int width;
			int height;
			void load();
		public:
			Map(std::string name);
	};
}

#endif
