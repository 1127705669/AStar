#ifndef _AStar_H
#define _AStar_H

#include <list>
using namespace std;

namespace ASTAR{

    enum State {NEW, CLOSE, OPEN, INFEASIBLE};

    struct Node
	{
		int SnodeX;            
		int SnodeY;            
		int SparentX;          
		int SparentY;          
		float Sgn;            
		float Shn;             
		float Sfn;
        State state = NEW;
        char display_state;
	};

    class CAStar
    {
    public:

        enum PathType {NOFINDPATHPOINT, FINDPATHPOINT};
        enum DistanceType {EUCLIDEAN, MANHANTTAN};
        
        PathType m_noPathFlag;

        void AstarCoreFunction(ASTAR::Node **temp_map, int start_x, int start_y, int target_x, int target_y);

    private:

        float EuclideanDistance(int _xNode, int _yNode, int _xTarget, int _yTarget);
        float ManhattanDistance(int _xNode, int _yNode, int _xTarget, int _yTarget);
        float FullDistance(int _xParentNode, int _yParentNode, int _xNode, int _yNode, int _xTarget, int _yTarget);
        bool InsertOpen(ASTAR::Node &node);
        bool InsertClose(ASTAR::Node &node);

    };
}

#endif