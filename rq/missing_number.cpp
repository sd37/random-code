#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find_missing1(vector<int>& v)
{
    //here we always have to assume that there will be a missing element.
    //otherwise this function will fail.

    int n = v.size();
    
    int actual_sum = ((n + 1)*(n + 2))/2;

    for(int i = 0; i < v.size(); i++)
    {
        actual_sum -= v[i];
    }
    
    return actual_sum;
}

int find_missing2(vector<int>& v)
{
    //this approach is better as there is no risk of integer overflow here.
    
    int x1 = 0;
    int x2 = 0;

    int n  = v.size() + 1;

    for(int i = 0; i < v.size(); i++)
    {
        x1 ^= v[i];
    }
    
    //assuming every integer is between 1 .. n
    for(int i = 1; i <= n; i++)
    {
        x2 ^= i;
    }
    return x1 ^ x2;
}

//slight change in the original question.
//now assume you know the range of integers.
//so we know the first and last element in the range.
//find the one missing element in the range.

int find_missing3(vector<int>& v)
{
    int x1 = 0;
    int x2 = 0;
    
    int first = *std::min_element(v.begin(),v.end());
    int last  = *std::max_element(v.begin(),v.end()); 

    int n = v.size() + 1;

    for(int i = 0; i < v.size(); i++)
    {
        x1 ^= v[i];
    }
    
    for(int i = first; i <= last; i++)
    {
        x2 ^= i;
    }

    return x1 ^ x2; 
}

int main()
{
    
    vector<int> v({1,2,4,6,5});
    vector<int> v1({11,12,14,16,15});
    cout << (find_missing1(v) == 0 ? "no missing element ":to_string(find_missing1(v))) << endl;
    cout << find_missing2(v) << endl;
    cout << find_missing3(v1);
    return 0;
}
