#include "maze.h"

//solve maze runner problem
int findPath (Maze& theMaze, const Coord& start, const Coord& end, Coord path[])
{
    int pthLen = 0;

    if (start == end)                   //maze end reached
    {
        theMaze.mark(end);
        path[pthLen] = end;
        ++pthLen;
    }
    else if (theMaze.isEmpty(start))   //empty maze square
    {
        theMaze.mark(start);
        pthLen = 0;

        int x = start.x;
        int y = start.y;

        for (int dir = 1; (pthLen == 0) && dir <= 4; ++dir)
            switch (dir)
            {
            case 1:     //NORTH
                pthLen = findPath(theMaze, Coord(x, y-1), end, path);
                break;

            case 2:     //EAST
                pthLen = findPath(theMaze, Coord(x+1, y), end, path);
                break;

            case 3:     //SOUTH
                pthLen = findPath(theMaze, Coord(x, y+1), end, path);
                break;

            case 4:     //WESTH
                pthLen = findPath(theMaze, Coord(x-1, y), end, path);
                break;
            }

        if (pthLen == 0)            //no sol. path found from 'start'
            theMaze.unMark(start);  //unmark step
        else                        //sol. path found from start
        {
            //store sol. path step
            for (int i = pthLen; i > 0; --i)
                path[i] = path[i - 1];
            path[0] = start;
            ++pthLen;
        }
    }

    return pthLen;
}
