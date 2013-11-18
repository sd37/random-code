//assume all elements are distinct
#include<iostream>
#include<vector>

using namespace std;

int find_min(vector<int>& v,int low,int high)
{
    while(low <= high)
    {
        int mid = (high - low) / 2 + low;
        
        if(mid > 0 && v[mid-1] > v[mid])
            return mid;
        
        else if(mid > 0 && v[mid] < v[0]) 
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return 0;
}

int main()
{
    //vector<int> v({5,6,7,8,9,10,11,1,2,3,4});
    //vector<int> v({1,2,3,4,5,6});
    //vector<int> v({3,4,5,6,2});
    vector<int> v{1,2};
    //vector<int> v{2,1};
    //vector<int> v({4,5,6,7,1,2,3});
    int min_index = find_min(v,0,v.size()-1);
    cout << min_index << ": value = " << v[min_index]<< endl;
    return 0;
}
