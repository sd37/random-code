#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int  minJumps(vector<int>& v,int l,int h)
{
    //this function is the min number of steps to reach
    //the end
    //the simple recursive defination will be.
    // minJumps(start,end) = 1 + min(minjumps(k,end)) forall k reachable from start

    if(v[l] == 0)
        return INT_MAX;

    if(l == h)
        return 0;

    int min = INT_MAX;

    for(int k = l + 1 ; k <= h && k <= l + v[l]; k++)
    {
        int intm_ans = minJumps(v,k,h);

        if(intm_ans != INT_MAX && intm_ans + 1 < min) //intm_ans != INT_MAX handle overflow
            min = intm_ans + 1;
    }

    return min;
}

int minJumpsDP(vector<int>& v)
{
    //TC = O(N^2)
    // we have jumps array. jumps[i] = min jumps to reach the end from ith element.
    int n = v.size();
    vector<int> jumps(n); 
    
    //will contain v.size() zeros. v[0] is the final answer
    int min;

    jumps[n-1] = 0;

    for(int i = n - 2; i >= 0; i--)
    {
        if(v[i] == 0)
            jumps[i] = INT_MAX;
    
        else if(v[i] >= (n - 1) - i) // because you can directly reach the end
            jumps[i] = 1;
        else
        {
            min = INT_MAX;

            for(int j = i + 1; j < n && j <= i + v[i]; j++)
            {   
                if(jumps[j] < min)
                    min = jumps[j];
            }
            
            //this is done to avoid integer overflow.
            if(min == INT_MAX)  
                jumps[i] = INT_MAX;
            else
                jumps[i] = 1 + min;
        }
    }

    return jumps[0];
}


int main()
{
    //vector<int> v({1,3,5,8,9,2,6,7,6,8,9});
    vector<int> v({2,0,1,1});
    cout << "MinJumps: " << minJumps(v,0,v.size() - 1) << endl;
    cout << "MinJumpsDP: " << minJumpsDP(v) << endl;
    return 0;
}
