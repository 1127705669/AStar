#ifndef _MAP_H
#define _MAP_H

#include <iostream>
#include <string>
#include "AStar.h"

using namespace ASTAR;

namespace Map{

    class Map{
        private:
            int edge_x_;
            int edge_y_;    

        public:

            int start_x;
            int start_y;
            int target_x;
            int target_y;
            ASTAR::Node **map_ = NULL;
            void Generator(int temp_edge_x = 30, int temp_edge_y = 30);
            void SetStartPoint(int StartPoint_x = 15, int StartPoint_y = 5);
            void SetEndPoint(int EndPoint_x = 22, int EndPoint_y = 25);
            void SetWall(int WallStartPoint_x = 15, int WallStartPoint_y = 5, int WallEndPoint_x = 15, int WallEndPoint_y = 25);
            void show();
            Map();
    };
}

#endif