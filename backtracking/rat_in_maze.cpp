#define R 4
#define C 5
#include<iostream>

using namespace std;

void printPath(int mat[R][C])
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cout << mat[i][j] << " ";
        }
        
        cout << endl;
    }
}

bool isSafe(int maze[R][C],int x,int y)
{
    if(x >=0 && x < R && y >= 0 && y < C && maze[x][y])
        return true;
    return false;
}

bool solveMazeUtil(int maze[R][C],int soln[R][C],int moveX[],int moveY[],int x,int y)
{
    if(soln[R-1][C-1] == 1)
        return true;
    
    for(int k = 0; k < 2; k++)
    {
        int next_x = x + moveX[k];
        int next_y = y + moveY[k];

        if(isSafe(maze,next_x,next_y))
        {
            soln[next_x][next_y] = 1;
            if(solveMazeUtil(maze,soln,moveX,moveY,next_x,next_y))
                return true;
            soln[next_x][next_y] = 0; //backtrack
        }
    }

    return false;
}

void solveMaze(int maze[R][C])
{
    int soln[R][C] ={{0}};
    
    int moveX[] = {1, 0};
    int moveY[] = {0, 1};

    //since start position is (0,0)

    soln[0][0] = 1;
    if(solveMazeUtil(maze,soln,moveX,moveY,0,0) == true)
        printPath(soln);
    else
        cout << "No Path Found" << endl;
}

int main()
{
    int maze[R][C]  =  
    { 
        {1, 0, 0, 0,0},
        {1, 1, 0, 1,0},
        {0, 1, 0, 0,0},
        {1, 1, 1, 1,1}
    };
     
    solveMaze(maze);
    return 0;
}
