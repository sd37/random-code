#define N 9
#define UNASSIGNED 0
#include<iostream>
#include<cstdio>

using namespace std;

void printGrid(int grid[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool findUnassignedLoc(int grid[N][N],int& row,int& col)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j] == UNASSIGNED)
            {
                row = i;
                col = j;
                return true;
            }
        }
    
    }

    row = -1;
    col = -1;
    return false;
}

bool isColSafe(int grid[N][N],int col,int num)
{
    for (int r  = 0; r < N; r++)
    {
        if(grid[r][col] == num)
            return false;
    }

    return true;
}

bool isRowSafe(int grid[N][N],int row,int num)
{
    for(int c = 0; c < N; c++)
    {
        if(grid[row][c] == num)
            return false;
    }

    return true;
}

bool isBlockSafe(int grid[N][N],int row,int col,int num)
{
    int start_row = row - row % 3;
    int start_col = col - col % 3;

    for(int i = start_row; i < start_row + 3; i++)
    {
        for(int j = start_col; j < start_col + 3; j++)
        {
            if(grid[i][j] == num)
                return false;
        }
    }

    return true;
}

bool isSafe(int grid[N][N],int row, int col,int k)
{
    return isColSafe(grid,col,k) && isRowSafe(grid,row,k) && isBlockSafe(grid,row,col,k);
}

bool solveSudokuUtil(int grid[N][N])
{
    int row,col;

    if(!findUnassignedLoc(grid,row,col))
        return true;

    for(int k = 1; k <= 9; k++)
    { 
        if(isSafe(grid,row,col,k))
        {
            grid[row][col] = k;
        
            if(solveSudokuUtil(grid) == true)
                return true;
            
            grid[row][col] = UNASSIGNED; //backtrack
        }
    }

    return false;
}

void SolveSudoku(int grid[N][N])
{
   if(solveSudokuUtil(grid) == true)
       printGrid(grid);
   else
       cout << "No Solution" << endl;
}

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    SolveSudoku(grid); 
    return 0;
}
