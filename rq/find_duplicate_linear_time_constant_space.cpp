#include<iostream>
#include<vector>
#include<set>

//all elements in the range 1 to n - 1

using namespace std;

void printRepeatingElements(vector<int> &v)
{
    int len  = v.size();

    for(int i = 0; i < len; i++)
    {
        
        if(v[abs(v[i])] < 0)
        {
            cout << abs(v[i]) << " ";
        }

        else
        {
            if(v[abs(v[i])] == 0)
                v[abs(v[i])] = -1;
            else
                v[abs(v[i])] = -v[abs(v[i])];
        }
    }
}

int main()
{   
    vector<int> v({0,1,2,3,1,3,6,6,0});
    printRepeatingElements(v);
    return 0;
}
