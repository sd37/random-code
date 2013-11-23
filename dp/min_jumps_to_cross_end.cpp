#include<iostream>
#include<vector>
#include<limits.h>

//#define NDEBUG
#include<assert.h>

using namespace std;

int minJumpsToCross(vector<int>& v)
{
    //TC = O(N^2)
    // we have jumps array. jumps[i] = min jumps to reach the end from ith element.
    int n = v.size();

    if(n == 0)
        return 0;

    vector<int> jumps(n); 
    
    int min;

    if(v[n-1] == 0)
        jumps[n-1] = INT_MAX;
    else
        jumps[n-1] = 1;

    for(int i = n - 2; i >= 0; i--)
    {
        if(v[i] == 0)
            jumps[i] = INT_MAX;
    
        else if(v[i] > (n - 1) - i)
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

void Test()
{
    //Test Cases
    vector<int> v1({1,3,5,8,9,2,6,7,6,8,9});   
    assert(minJumpsToCross(v1) == 3);

    vector<int> v2({1,3,6,1,0,9});
    assert(minJumpsToCross(v2) == 3);

    vector<int> v3({2,2,0,1});
    assert(minJumpsToCross(v3) == 3);

    vector<int> v4({2,0,0,1});
    assert(minJumpsToCross(v4) == INT_MAX);
    
    vector<int> v5;
    assert(minJumpsToCross(v5) == 0);

    vector<int> v6({0});
    assert(minJumpsToCross(v6) == INT_MAX);

    vector<int> v7({1});
    assert(minJumpsToCross(v7) == 1);

    vector<int> v8({4});
    assert(minJumpsToCross(v8) == 1);

    vector<int> v9({0,1});
    assert(minJumpsToCross(v9) == INT_MAX);
   
    vector<int> v10({2,1});
    assert(minJumpsToCross(v10) == 1);

    vector<int> v11({1,1});
    assert(minJumpsToCross(v11) == 2);

    vector<int> v12({2,0,3});
    assert(minJumpsToCross(v12) == 2);

    vector<int> v13({1,2,3});
    assert(minJumpsToCross(v13) == 2);

    vector<int> v14({1,2,3,4,5,6,7});
    assert(minJumpsToCross(v14) == 3);

    cout << "ALL TEST CASES PASSED!!" <<endl; 
}

int main()
{
    Test();
    return 0;
}
