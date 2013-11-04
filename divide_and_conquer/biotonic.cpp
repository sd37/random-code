//assume distinct integers in the array
#include<iostream>
#include<vector>

using namespace std;

int find_pivot(vector<int>& v,int low,int high)
{   
    while(low <= high)
    {
        //base cases

        if(low == high)
            return low;

        if(low == high + 1) 
        {    
            if(v[low] > v[high])
                return low;
            else
                return high;
        }

        int mid = (high - low) / 2 + low;
       
        if(v[mid - 1] < v[mid] && v[mid] > v[mid + 1])
            return mid;
        else if (v[mid - 1] < v[mid])
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
}

int find_max(vector<int>&v)
{
    int pivot = find_pivot(v,0,v.size() -1);
    
    return v[pivot];
}
int main()
{
    //vector<int> v({8,10,20,80,100,200,400,500,3,2,1});
    //vector<int> v({1,3,50,10,9,7,6});
    //vector<int> v({10,20,30,40,50});
    //vector<int> v({120,100,80,20,0});
    vector<int> v({1,30,40,50,60,70,23,20});
    int num = find_max(v);
    cout << num << endl;
    return 0;
}
