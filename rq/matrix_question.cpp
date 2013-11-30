//Give an matrix of m *n with all the elements=1, 
//Also given is a list of (x,y) points. The question is to zero out all the elements of xth row and yth column. 
#include<iostream>
#include<vector>

using namespace std;

void mat_manip(vector< vector<int> > &v,vector<int>&x,vector<int>&y)
{
    int row = v.size();
    int col = v[0].size();
    
    int n = x.size();

    for(int i = 0; i < n; i++)
    {
        int curr_x = x[i];
        int curr_y = y[i];

        //make row zero

        for(int c = 0; c < col; c++)
            v[curr_x][c] = 0;
        
        //make col zero

        for(int r = 0; r < row; r++)
            v[r][curr_y] = 0; 
    }
}

int main()
{
    vector<int> x({0,2});
    vector<int> y({1,2});

    vector< vector<int> > v(3,vector<int>(3,1));
    mat_manip(v,x,y);
    return 0;
}
