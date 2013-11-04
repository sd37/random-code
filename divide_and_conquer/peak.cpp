//find any peak is the goal
#include<iostream>
#include<vector>
using namespace std;

int find_peak(vector<int>& v,int low,int high)
{
    while(low <= high)
    {
        int mid = (high - low) / 2 + low;

        if((mid == 0 || v[mid-1] <= v[mid]) && (mid == v.size() -1 || v[mid] >= v[mid + 1] ))
        {
            return mid;
        }
        else if(v[mid-1] > v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

}

int main()
{

    //vector<int> v({1,2,6,5,3,7,4});
    //vector<int> v({1,2,3,4,5,6,7,8});
    vector<int> v({8,7,6,5,4,3,2,1});
    int index = find_peak(v,0,v.size() - 1);
    cout << index << ":" << v[index]<< endl;
    return 0;
}
