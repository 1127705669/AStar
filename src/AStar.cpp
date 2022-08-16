#include <iostream>
#include <cmath>
#include "Map.h"
#include "AStar.h"

bool ASTAR::CAStar::InsertOpen(ASTAR::Node &node){

    node.state = OPEN;
}

bool ASTAR::CAStar::InsertClose(ASTAR::Node &node){

    node.state = CLOSE;
}

float ASTAR::CAStar::EuclideanDistance(int _xNode, int _yNode, int _xTarget, int _yTarget){

	float d = sqrt(pow(_xNode - _xTarget, 2) + pow(_yNode - _yTarget, 2));
	return d;
}

float ASTAR::CAStar::ManhattanDistance(int _xNode, int _yNode, int _xTarget, int _yTarget){

	float d = std::abs(_xNode - _xTarget) + std::abs(_yNode - _yTarget);
	return d;
}

float ASTAR::CAStar::FullDistance(int _xParentNode, int _yParentNode, int _xNode, int _yNode, int _xTarget, int _yTarget){

    float d = EuclideanDistance(_xNode, _yNode, _xParentNode, _yParentNode) + ManhattanDistance(_xNode, _yNode, _xTarget, _yTarget);
    return d;
}

void ASTAR::CAStar::AstarCoreFunction(ASTAR::Node **temp_map, int start_x, int start_y, int target_x, int target_y){

    int Node_x = start_x;
    int Node_y = start_y;

    struct temp_Sfn
    {
        bool FirstTime = true;
        float temp_Sfn_ = 0.0;
    };

    while (CLOSE != temp_map[target_x][target_y].state)
    {
        temp_map[Node_x][Node_y].state = CLOSE;

        temp_Sfn temp_Sfn_data;

        int temp_index_x;
        int temp_index_y;

        for (int i = (Node_x - 1); i < (Node_x + 2); i++)
        {
            for (int j = (Node_y - 1); j < (Node_y + 2); j++)
            {
                if (NEW == temp_map[i][j].state)
                {   
                    temp_map[i][j].SparentX = Node_x;
                    temp_map[i][j].SparentY = Node_y;
                    temp_map[i][j].Shn = ManhattanDistance(i, j, target_x, target_y);
                    temp_map[i][j].Sgn = temp_map[Node_x][Node_y].Sgn + EuclideanDistance(i, j, Node_x, Node_y);
                    temp_map[i][j].Sfn = temp_map[i][j].Sgn + temp_map[i][j].Shn;

                    temp_map[i][j].state = OPEN;
                }
                else if (OPEN == temp_map[i][j].state)
                {
                    float ParentToCurrent = EuclideanDistance(i, j, Node_x, Node_y);

                    if ((ParentToCurrent + temp_map[Node_x][Node_y].Sgn) >= temp_map[i][j].Sgn)
                    {
                        
                    }
                    else
                    {
                        temp_map[i][j].SparentX = Node_x;
                        temp_map[i][j].SparentY = Node_y;
                        temp_map[i][j].Sgn = (ParentToCurrent + temp_map[Node_x][Node_y].Sgn);
                        temp_map[i][j].Shn = ManhattanDistance(i, j, target_x, target_y);
                        temp_map[i][j].Sfn = temp_map[i][j].Sgn + temp_map[i][j].Shn;
                    }
                }
                else
                {
                    continue;
                }
                
                if(true == temp_Sfn_data.FirstTime)
                {
                    temp_Sfn_data.temp_Sfn_ = temp_map[i][j].Sfn;
                    temp_index_x = i;
                    temp_index_y = j;
                    temp_Sfn_data.FirstTime = false;
                }
                else if(temp_map[i][j].Sfn < temp_Sfn_data.temp_Sfn_)
                {
                    temp_Sfn_data.temp_Sfn_ = temp_map[i][j].Sfn;
                    temp_index_x = i;
                    temp_index_y = j;
                }
            }
        }

        Node_x = temp_index_x;
        Node_y = temp_index_y;

        cout << Node_x << ", " << Node_y << endl;
        
        if ((target_x == Node_x) && (target_y == Node_y))
        {
            break;
        }
    }
    
    int temp_Node_x = target_x;
    int temp_Node_y = target_y;

    while (!((temp_Node_x == start_x) && (temp_Node_y == start_y)))
    {
        
        int x;
        int y;

        //temp_map[temp_Node_x][temp_Node_y].display_state = '*';

        cout << temp_Node_x << "," << temp_Node_y << " -> ";
        cout << temp_map[temp_Node_x][temp_Node_y].SparentX << "," << temp_map[temp_Node_x][temp_Node_y].SparentY << endl;

        x = temp_map[temp_Node_x][temp_Node_y].SparentX;
        y = temp_map[temp_Node_x][temp_Node_y].SparentY;

        temp_Node_x = x;
        temp_Node_y = y;

        if((temp_Node_x == start_x) && (temp_Node_y == start_y))
        {
            break;
        }

        temp_map[temp_Node_x][temp_Node_y].display_state = '*';

        if((temp_Node_x == 28) && (temp_Node_y == 15))
        {
            cout << temp_Node_x << "," << temp_Node_y << "----------------" << endl;
        }
        else
        {
            cout << temp_Node_x << "," << temp_Node_y << "!!!" << endl;
        }
    }
}