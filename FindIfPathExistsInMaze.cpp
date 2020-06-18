/*

PROBLEM STATEMEMT : 

We are having a 3*3 Maze , filled with 0's and 1's . The 1's in the Maze Indicate that , 
we can further Travel to this Position , and 0 Indicates that these are Blocked Cells

Following RLTB (Right Left Top Bottom)

==>We Also Must Remember That From Which Path we are Coming

Additionally , We will also create a 2D Matrix Named "Path" , which will like 
keep Track Of All the Visited Nodes
*/

#include <iostream>
using namespace std;

bool findPathHelper(int maze[][20], int n, int x, int y, int path[][20])
{
    //(x,y) tuple represents the current location in the maze where I am at right now

    //Step 1 : Checking that whether we are within bound or not :
    if (x < 0 || x >= n || y < 0 || y >= n)
    {
        return false; //If this is the Case , it signifies that we are out of bounds
    }

    if (x == n - 1 && y == n - 1)
    {
        path[x][y] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    //This Signifies that we have reached the dead end
    if (maze[x][y] == 0 || path[x][y] == 1)
    {
        return false;
    }

    path[x][y] = 1;
    //Right
    if (findPathHelper(maze, n, x, y + 1, path))
    {
        path[x][y] = 0;
        return true;
    }
    //Left
    if (findPathHelper(maze, n, x, y - 1, path))
    {
        path[x][y] = 0;
        return true;
    }
    //Top
    if (findPathHelper(maze, n, x - 1, y, path))
    {
        path[x][y] = 0;
        return true;
    }

    //Bottom
    if (findPathHelper(maze, n, x + 1, y, path))
    {
        path[x][y] = 0;
        return true;
    }

    path[x][y] = 0;
    return false;
}

bool findPath(int maze[][20], int n)
{
    int path[20][20] = {0};

    return findPathHelper(maze, n, 0, 0, path);

    //Continuing with the Backtracking Algorithm
}

int main()
{
    int n = 3;
    //Creating Out 3*3 Maze :
    int maze[20][20] = {{1, 1, 0}, {1, 1, 0}, {0, 1, 1}};

    if (findPath(maze, n))
    {
        cout << "A Path to Reach the Destination Cell Exists" << endl;
    }
    else
    {
        cout << "A Path to Reach to the Destination Node Doesnt Exists" << endl;
    }
}
