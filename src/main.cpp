#include <iostream>
#include "Map.h"
#include "AStar.h"

using namespace std;
using namespace Map;
using namespace ASTAR;

int main(int argc, char **argv) {

	Map::Map map;
	map.Generator();
	map.SetStartPoint();
	map.SetEndPoint();
	map.SetWall();
	map.SetWall(16, 20, 25, 27);

	ASTAR::CAStar astar;
	astar.AstarCoreFunction(map.map_, map.start_x, map.start_y, map.target_x, map.target_y);
	map.show();
	return 0;
}