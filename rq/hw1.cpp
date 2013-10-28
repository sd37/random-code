// Convert this program to C++
// change to C++ io
// change to one line comments
// change defines of constants to const
// change array to vector
// inline any short function

#include<iostream>
#include<vector>

int const N = 40;

using namespace std;

template <class T> //T is a generic type

void sum(T &s,int n,vector<T>& d)
{
    s = 0;
    for (int i = 0; i < d.size(); i++)
        s = s + d[i];

}

int main()
{

    int accum = 0;
    vector<int> data; //a vector for storing data
    
    for(int i = 0; i < N; i++)
        data.push_back(i);

    sum(accum, N,data);

    cout << "sum is " << accum << endl;
    return 0;
}

