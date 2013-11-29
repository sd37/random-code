//http://oj.leetcode.com/problems/climbing-stairs/
#include<iostream>
#include<map>

using namespace std;

typedef int steps;
typedef int ans;
class Solution
{
    map<steps,ans> mp;

    public:

    int climbStairs(int n)
    { 
        if(n <= 1)
            return 1;
        if(mp.find(n) != mp.end())
            return mp[n];

        mp[n] = climbStairs(n-1) + climbStairs(n-2);
        return mp[n];
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(38) << endl;
    return 0;
}
