//Given an array find if a element exists for which a[i] == i
#include<iostream>
#include<vector>
using namespace std;
//works only when the array has distinct elements
//when mid > v[mid] we HOPE to find the element on the right hand side.
int findFP(vector<int>& v,int low,int high)
{
    while(low <= high)
    {
        int mid = (high - low)/2 + low;
        if(v[mid] == mid)
            return mid;
        else if(mid > v[mid])
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> v({-10,0,1,2,3,5});
    int fixpt = findFP(v,0,v.size()-1);
    cout << fixpt << endl;
    return 0;
}
