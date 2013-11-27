#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>
#include<cstdlib>

using namespace std;
//compile the code using = g++ -o rmx -std=c++11 RecentMax.cpp
//and then run the code using = ./rmx 3 inp.txt
//Questions asked in the mail
//Time Complexity = O(n*k)  because at each index we are computing the max in vector of k elements.
//Space Complexit = O(k)

void RecentMax(vector<float>&v,int k)
{
    int len = v.size();
    int save_k = k;

    vector<float> temp;

    if(k == 0) 
        return; //return empty seq. i.e print nothing.

    for(int i = 0; i < v.size();i++)
    {
        int j = i;
        k = save_k;
        while(j >= 0 && k > 0)
        {
           temp.push_back(v[j]);
           j--;
           k--;       
        }
        
        if(i != v.size() - 1)  //this is done to get the output format as mentioned in the mail
            cout << *max_element(temp.begin(),temp.end()) << ",";
        else
            cout << *max_element(temp.begin(),temp.end());
        temp.clear();
    }
}

//Driver code to test the function.
int main(int argc,char *argv[])
{
    vector<float> v;
    string l;
    int n = atoi(argv[1]);
    
    ifstream inpt(argv[2]);

    if(inpt.is_open())
    {
        while(getline(inpt,l))
        {
            float num = atof(l.c_str());
            v.push_back(num);
        }
    }

    RecentMax(v,n);    
    cout << endl;
    return 0;
}
