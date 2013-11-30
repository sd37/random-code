#include<vector>
#include<iostream>

using namespace std;

#define OBSTACLE 1
#define FREE 0

class Solution
{
    public:
        
        
        int uniquePathsWithObstacles(vector<vector<int> > &obs)
        {
            vector<vector<int> > soln(obs.size(),vector<int>(obs[0].size(),0));
           
            int row = obs.size();
            int col = obs[0].size();

            if(obs[0][0] == OBSTACLE || obs[row-1][col - 1] == OBSTACLE)
                return 0;

            soln[row-1][col-1] = 1;

            for(int i = row - 2; i >=0; i--)
            {    
                if(obs[i][col - 1] == FREE)
                    soln[i][col - 1] = soln[i+1][col-1];
                else
                    soln[i][col-1] = 0;
            }

            for(int j = col - 2; j >= 0; j--)
            {
                if(obs[row-1][j] == FREE)
                    soln[row -1][j] = soln[row - 1][j + 1];
                else
                    soln[row - 1][j] = 0;
            }   

            for(int i = row - 2; i >=0 ; i--)
            {
                for(int j = col - 2; j >= 0; j--)
                {
                    if(obs[i][j] == FREE)
                        soln[i][j] = soln[i + 1][j] + soln[i][j + 1];
                    else
                        soln[i][j] = 0;
                }
            }

        return soln[0][0]; 
        }
};

int main()
{
    Solution s;
    int N = 3;
    int M = 3;
    vector<vector<int> > obs(N,vector<int>(M,0));
    
    obs[1][1] = 1;

    cout << s.uniquePathsWithObstacles(obs) << endl;
    return 0;
}
