#include<iostream>
#include<cstdio>
#include<limits.h>
#include<cstdlib>

using namespace std;

bool addOvf(int &result,int x,int y)
{
    if(x > 0 && y > INT_MAX - x)
        return true;
    if(x < 0 && y < INT_MIN - x)
        return true;
    result = x + y;
    return false;
}

bool mulOvf(int &result,int x,int y)
{
    if(x == 0 || y == 0)
    {
        result = 0;
        return false;
    }

    if(x > 0 && y > 0 && y > INT_MAX / x)
        return true;
    else if(x < 0 && y < 0 && abs(y) > INT_MAX / abs(x))
        return true;
    else if( y < INT_MIN / x)
        return true;

    result = x * y;
    return false;
}

int main()
{
    int x,y,result;

    /*
    int result = -99;
    x = 2147483640;
    y = -10;

    cout << boolalpha << addOvf(result,x,y) << endl;
    cout << result << endl;
    
    result = 0;
    
    x  = 10;
    y  = 10;
    
    cout << boolalpha << addOvf(result,x,y) << endl;
    cout << result << endl;
    */
    x = 10;
    y = -2147483641;
    result = -99;

    cout << boolalpha << mulOvf(result,x,y) << endl;
    cout << result << endl;
    return 0;
}
