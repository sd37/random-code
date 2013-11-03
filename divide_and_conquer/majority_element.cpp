//find if a given integer occurs more than n/2 times in a sorted array of n integers.

#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool LinearIsMajority(vector<int> &v,int x)
{
    int n = v.size();
    
    for(int i = 0; i < n; i++)
    {
        if(v[i] == x)
        {
            if(i + n/2 < n && v[i + n/2] == x)
                return true;
            else
                return false;
        }

    }

    return false;

}

int first_occur(vector<int> &v,int low,int high,int x)
{
    while(low <= high)
    {
        int mid = (high - low)/2 + low;

        if(v[mid] == x && (mid == 0 || v[mid-1] !=x))
            return mid;
        else if( x <= v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

bool BsIsMajority(vector<int> &v,int x)
{
    int n = v.size();
    int first = first_occur(v,0,n-1,x);
    if(first != -1 && first + n / 2 < n && v[first + n / 2] == x)
        return true;
    return false;
}

int main()
{
    //vector<int> v({1,2,3,3,3,3,10});
    vector<int> v({1,2,3,4,5,6,6,10});
    //cout << LinearIsMajority(v,6) << endl;
    cout << BsIsMajority(v,44) << endl;
    return 0;
}
