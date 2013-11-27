#include<iostream>
#include<cstdio>
#include<limits.h>

using namespace std;

//Here the basic assumption is that x and y are within the limits. Note there is no way to detect
//whether an integer variable which is passed exceeds the limits.

bool addOvf1(int &result,int x,int y)
{
    int old_result = result;

    result = x + y;
    
    if(x > 0 && y > 0 && result < 0)
    {    
        result = old_result;
        return true;
    }
    
    if(x < 0 && y < 0 && result > 0)
    {    
        result = old_result;
        return true;
    }

    return false;
}

bool addOvf2(int &result,int x,int y)
{
    if(x > INT_MAX - y)
        return true;
    else
    {
        result = x + y;
        return false;
    }
}
int main()
{
    int result = -99;
    int x = 2147483640;
    int y = 10;

    cout << boolalpha << addOvf1(result,x,y) << endl;
    cout << result << endl;
    
    result = 0;
    
    x  = 10;
    y  = 10;
    
    cout << boolalpha << addOvf2(result,x,y) << endl;
    cout << result << endl;
    return 0;
}
