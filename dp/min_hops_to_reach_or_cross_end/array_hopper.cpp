//author = spandan
#include<iostream>
#include<fstream>
#include<vector>
#include<limits.h>
#include<string>
#include<map>

//#define NDEBUG
#include<assert.h>

using namespace std;


string minJumpsToCross(vector<int>& v)
{
    //TC = O(N^2)
    // we have jumps array. jumps[i] = min jumps to reach the end from ith element.
    // we have a map next_hop which keeps track of the next hop for v[i]. This data-structure is finally used to get the path to move out of the array. 
    // to run the program.
    // first compile using the following command = g++ -std=c++11 -o ah array_hopper.cpp
    // then run using the following command = ./ah input.txt
    
    int n = v.size();
    map<int,string> next_hop;

    if(n == 0)
        return "";

    vector<int> jumps(n); 
    
    int min;
    int min_index;

    if(v[n-1] == 0)
    {
        jumps[n-1] = INT_MAX;
        next_hop[n-1] = ""; 
    }
    else
    {
        jumps[n-1] = 1;
        next_hop[n-1] = "out";
    }

    for(int i = n - 2; i >= 0; i--)
    {
        if(v[i] == 0)
        {
            jumps[i] = INT_MAX;
            next_hop[i] = "";
        }

        else if(v[i] > (n - 1) - i)
        {
            jumps[i] = 1;
            next_hop[i] = "out";
        }
        else
        {
            min = INT_MAX;
            min_index = -1;
            for(int j = i + 1; j < n && j <= i + v[i]; j++)
            {   
                if(jumps[j] < min)
                {
                    min = jumps[j];
                    min_index = j;
            
                }
            }            
            
            //this is done to avoid integer overflow.
            if(min == INT_MAX)  
            {    
                jumps[i] = INT_MAX;
                next_hop[i] = "";
            }
            else
            {
                jumps[i] = 1 + min;
                next_hop[i] = to_string(min_index);            
            }
        }
    }

    if(jumps[0] == INT_MAX)
        return "failure";

    string ans_path("0");
    string temp = next_hop[0];
    while(true)
    {
        if(temp == "out")
        {
            ans_path = ans_path + ", out";
            break;
        }
        ans_path = ans_path + ", "+ temp;
        temp = next_hop[atoi(temp.c_str())]; 
    }

    return ans_path;
}

void Test()
{
    //Test Cases
    vector<int> v1({1,3,5,8,9,2,6,7,6,8,9});   
    assert(minJumpsToCross(v1) == "0, 1, 3, out");

    vector<int> v2({1,3,6,1,0,9});
    assert(minJumpsToCross(v2) == "0, 1, 2, out");

    vector<int> v3({2,2,0,1});
    assert(minJumpsToCross(v3) == "0, 1, 3, out");

    vector<int> v4({2,0,0,1});
    assert(minJumpsToCross(v4) == "failure");
    
    vector<int> v5;
    assert(minJumpsToCross(v5) == "");

    vector<int> v6({0});
    assert(minJumpsToCross(v6) == "failure");

    vector<int> v7({1});
    assert(minJumpsToCross(v7) == "0, out");

    vector<int> v8({4});
    assert(minJumpsToCross(v8) == "0, out");

    vector<int> v9({0,1});
    assert(minJumpsToCross(v9) == "failure");
   
    vector<int> v10({2,1});
    assert(minJumpsToCross(v10) == "0, out");

    vector<int> v11({1,1});
    assert(minJumpsToCross(v11) == "0, 1, out");

    vector<int> v12({2,0,3});
    assert(minJumpsToCross(v12) == "0, 2, out");

    vector<int> v13({1,2,3});
    assert(minJumpsToCross(v13) == "0, 1, out");

    vector<int> v14({1,2,3,4,5,6,7});
    assert(minJumpsToCross(v14) == "0, 1, 3, out");

    cout << "ALL TEST CASES PASSED!!" <<endl; 
}

int main(int argc,char *argv[])
{
    //Test();
    string l;
    ifstream inpt(argv[1]);
    vector<int> v;

    if(inpt.is_open())
    {
        while(getline(inpt,l) )
        {
            v.push_back(atoi(l.c_str()));        
        }
    }

    else 
    {
        cout << "Unable to open the file" << endl;
        return 0;
    }
    cout << minJumpsToCross(v) << endl;
    return 0;
}
