#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>
#include<cstdlib>

using namespace std;
/*
"Recent Max" Problem Statement 

Write a program that takes in as command-line arguments an integer n and the name of a potentially very large file containing a series of floating point numbers, one to a line. The program should output (to stdout) a series of floating point numbers, each of which is a max of a subsequence of the data in the file of length 0-n. Essentially, the ith number output is the max of the numbers in the original series starting at index i and looking backwards n elements or to the beginning of the series, whichever is nearer. For instance, if the input were:
1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1
And n=3, the output would be:
1, 2, 3, 4, 5, 6, 6, 6, 5, 4, 3
*/

//compile the code using = g++ -o rmx -std=c++11 RecentMax.cpp
//and then run the code using = ./rmx 3 inp.txt
//Questions asked in the mail
//Time Complexity = O(n*k)  because at each index we are computing the max in vector of k elements.
//Space Complexit = O(k)

void RecentMax(vector<float>&v,int k)
{
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
