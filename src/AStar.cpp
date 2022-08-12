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

    InsertClose(temp_map[Node_x][Node_y]);

    while (CLOSE != temp_map[target_x][target_y].state)
    {
        InsertClose(temp_map[Node_x][Node_y]);

        temp_Sfn temp_Sfn_data;
        
        for (int i = (Node_x - 1); i < (Node_x + 2); i++)
        {
            for (int j = (Node_y - 1); j < (Node_y + 2); j++)
            {
                if((CLOSE != temp_map[i][j].state) && (INFEASIBLE != temp_map[i][j].state))
                {
                    //cout << temp_Sfn << endl;
                    // if(NEW == temp_map[i][j].state)
                    // {
                        temp_map[i][j].SparentX = Node_x;
                        temp_map[i][j].SparentY = Node_y;
                        temp_map[i][j].Sgn = temp_map[Node_x][Node_y].Sgn + EuclideanDistance(i, j, Node_x, Node_y);
                        temp_map[i][j].Shn = ManhattanDistance(i, j, target_x, target_y);
                        temp_map[i][j].Sfn = temp_map[i][j].Sgn + temp_map[i][j].Shn;
                        InsertOpen(temp_map[i][j]);
                    // }
                    // else if(OPEN == temp_map[i][j].state)
                    // {
                    //     temp_map[i][j].Sgn = EuclideanDistance(i, j, temp_map[Node_x][Node_y].SparentX, temp_map[Node_x][Node_y].SparentY);
                    //     float ParentToCurrentSgn = EuclideanDistance(i, j, Node_x, Node_y);

                    //     if ((ParentToCurrentSgn + temp_map[Node_x][Node_y].Sgn) > temp_map[i][j].Sgn)
                    //     {
                    //         temp_map[i][j].SparentX = temp_map[Node_x][Node_y].SparentX;
                    //         temp_map[i][j].SparentY = temp_map[Node_x][Node_y].SparentY;
                    //     }
                    //     else
                    //     {
                    //         temp_map[i][j].Sgn = (ParentToCurrentSgn + temp_map[Node_x][Node_y].Sgn);
                    //     }

                    //     temp_map[i][j].Shn = ManhattanDistance(i, j, target_x, target_y);
                    //     temp_map[i][j].Sfn = temp_map[i][j].Sgn + temp_map[i][j].Shn;
                    // }

                    if (true == temp_Sfn_data.FirstTime)
                    {
                        temp_Sfn_data.temp_Sfn_= temp_map[i][j].Sfn;
                        Node_x = i;
                        Node_y = j;
                        temp_Sfn_data.FirstTime = false;
                    }
                    else if (temp_map[i][j].Sfn < (temp_Sfn_data.temp_Sfn_))
                    {
                        Node_x = i;
                        Node_y = j;
                        temp_Sfn_data.temp_Sfn_ = temp_map[i][j].Sfn;
                    }
                }
            }
        }
 
        if((Node_x == target_x)&&(Node_y == target_y))
        {
            break;
        }
        else
        {
            temp_map[Node_x][Node_y].display_state = '*'; 
        }
    }
    //cout << temp_Sfn_data.temp_Sfn_ << endl;
}