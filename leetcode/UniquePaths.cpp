http://oj.leetcode.com/problems/unique-paths
#include<iostream>
#include<map>
#include<utility>

using namespace std;

typedef pair<int,int> mn;
typedef int ans;

class Solution
{
    map<mn, ans> mp;
    public:
        /*
        int uniquePaths(int m, int n)
        {
            if(m == 1 || n == 1)
                return 1;
            return uniquePaths(m,n-1) + uniquePaths(m-1,n);
        }
        */

        int uniquePaths(int m,int n)
        {
            if(m == 1 || n == 1)
                return 1;
            pair<int,int> temp = make_pair(m,n);
            
            if(mp.find(temp) != mp.end())
                return mp[temp];

            mp[temp] = uniquePaths(m,n-1) + uniquePaths(m-1,n);
            return mp[temp];
        }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(3,7) << endl;
    return 0;
}
