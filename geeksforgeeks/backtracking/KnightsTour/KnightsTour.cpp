#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

class KnightTourSoln
{
    int N;
    vector< vector<int> > soln; //The main soln matrix
    bool isSafe(int x,int y);
    void printSolutions();
    bool solveKTUtil(int x,int y,int movei,int xMove[],int yMove[]);
public:
    KnightTourSoln(int N);
    void solveKT();
};

KnightTourSoln::KnightTourSoln(int N)
{
    this->N = N;
    soln.resize(this->N); 
    for(int i = 0; i < this->N; i++)
    {
        soln[i].resize(N);
    }

    for(int i = 0; i < this->N; i++)
    {
        for(int j = 0; j < this->N; j++)
        {
            soln[i][j] = -1;
        }
    }
}

void KnightTourSoln::printSolutions()
{
    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
                cout << soln[i][j] << " ";
        cout << endl;
    }

}

bool KnightTourSoln::isSafe(int x,int y)
{
    if(x >=0 && x < N && y >= 0 && y < N && soln[x][y] == -1)
        return true;
    else
        return false;
}

bool KnightTourSoln::solveKTUtil(int x, int y,int movei, int xMove[],int yMove[])
{
    if(movei == N*N)
        return true;
    
    for(int k = 0; k < 8; k++)
    {
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];

        if(isSafe(next_x,next_y))
        {
            soln[next_x][next_y] = movei;

            if(solveKTUtil(next_x,next_y,movei + 1,xMove,yMove))
                return true;
            
            soln[next_x][next_y] = -1; //backtrack 
        }
    }

    return false;
}

void KnightTourSoln::solveKT()
{
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    //Assuming Knight is initially at first block
    
    soln[0][0] = 0;

    if(solveKTUtil(0,0,1,xMove,yMove) == false)
        cout << "No solution" << endl;
    else
        printSolutions();
}

int main()
{
    KnightTourSoln kt(8);
    kt.solveKT();
    return 0;
}
