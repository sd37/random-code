//https://www.hackerrank.com/challenges/lonely-integer
/*
 *  status = AC
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int single_element(vector<int>& v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans ^= v[i];

    return ans;
}
int main() {
    vector<int> v;
    int n;
    cin >> n;
    
    while(n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << single_element(v);
    return 0;
}
