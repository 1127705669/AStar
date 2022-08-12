#include <iostream>
#include "Map.h"
#include "AStar.h"

using namespace std;
using namespace Map;
using namespace ASTAR;

Map::Map::Map(){


}

void Map::Map::Generator(int temp_edge_x, int temp_edge_y){

    edge_x_ = temp_edge_x;
    edge_y_ = temp_edge_y;

    map_ = new ASTAR::Node*[edge_x_];

    for (int i = 0; i < edge_x_; i++){

        map_[i] = new ASTAR::Node[edge_y_];

        for (int j = 0; j < edge_y_; j++){

            map_[i][j].display_state = '.';
        }
    }
}

void Map::Map::show(){
    for (int i = 0; i < edge_x_; i++){

        for (int j = 0; j < edge_y_; j++){

            cout << map_[i][j].display_state << " ";
        }
        cout << endl;
    }
}

void Map::Map::SetStartPoint(int StartPoint_x, int StartPoint_y){
    map_[StartPoint_x][StartPoint_y].display_state = 'S';
    start_x = StartPoint_x;
    start_y = StartPoint_y;
}

void Map::Map::SetEndPoint(int EndPoint_x, int EndPoint_y){
    map_[EndPoint_x][EndPoint_y].display_state = 'E';
    target_x = EndPoint_x;
    target_y = EndPoint_y;
}

void Map::Map::SetWall(int WallStartPoint_x, int WallStartPoint_y, int WallEndPoint_x, int WallEndPoint_y){

    for (int i = WallStartPoint_x; i < WallEndPoint_y; i++)
    {
        map_[i][15].display_state = '#';
        map_[i][15].state = INFEASIBLE;
    }
}