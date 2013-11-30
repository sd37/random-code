#include<iostream>
#include<vector>

using namespace std;

void printRepeatingElements1(vector<int> &v)
{
    int len  = v.size();
    
    for(int i = 0 ; i < len; i++)
    {
        if(v[abs(v[i]) - 1] < 0)
            cout << abs(v[i]) << " "; 
        else
            v[abs(v[i]) - 1] = -v[abs(v[i]) - 1];
    }
}

int main()
{   
    vector<int> v({3,1,2,4,5,1,2});
    printRepeatingElements1(v);
    return 0;
}
