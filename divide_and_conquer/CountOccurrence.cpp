#include<iostream>
#include<vector>

using namespace std;
int first_occur(vector<int>& v,int low,int high,int x)
{
    while(low <= high)
    {
        int mid = (high - low) / 2 + low;

        if(v[mid] == x &&(mid == 0 || v[mid - 1] != x))
            return mid;
        else if (x <= v[mid])
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

int last_occur(vector<int>& v,int low,int high,int x)
{
    while(low <= high)
    {
        int mid = (high - low) / 2 + low;
        
        if(v[mid] == x &&( mid == v.size() - 1 || v[mid+1] !=x))
            return mid;
        else if (x >= v[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    
    }

    return -1;
}

int count_occur(vector<int>& v,int x)
{
    int n = v.size();
    int f = first_occur(v,0,n-1,x);
    if(f == -1)
        return 0;
    //instead of starting from 0 start from f. 
    int l = last_occur(v,f,n-1,x);
    return l - f + 1;
}

int main()
{
    vector<int> v({1,1,2,2,2,2,2,2,2,2,3,3,3,4,4,5});
    cout << count_occur(v,2) << endl;
    cout << count_occur(v,3) << endl;
    cout << count_occur(v,4) << endl;
    cout << count_occur(v,45) << endl;
    return 0;
}
