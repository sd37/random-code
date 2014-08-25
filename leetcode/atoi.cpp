//http://oj.leetcode.com/problems/string-to-integer-atoi/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<locale>
#include<limits.h>

using namespace std;

int simple_atoi(char* str)
{
    if(str == NULL)
        return 0;
    int res = 0;

    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        res = 10*res + (str[i] - '0');
    }

    return res;
}

bool addOvf(int x,int y)
{
    if(x > 0 && y > INT_MAX - x)
        return true;

    if(x < 0 && y < INT_MIN - x)
        return true;

    return false;
}

bool mulOvf(int x,int y)
{
    if(x == 0 || y == 0)
        return false;
    if(x > 0 && y > 0 && y > INT_MAX / x)
        return true;
    else if(x < 0 && y < 0 && abs(y) > INT_MAX / abs(x))
        return true;
    else if(y < INT_MIN / abs(x))
        return true;
    else
        return false;
}

bool OverFlow(int res,int num)
{

    if(mulOvf(10,res))
        return true;
    else
    {
        return addOvf(10*res,num);
    }
}

int my_atoi(const char* str)
{
    if(str == NULL)
        return 0;
    
    int res = 0;
    int sign = 1; // to take care of signed numbers
    int len = strlen(str);
    int i;
    
    for(i = 0; i < len; i++)
    {
        if(isspace(str[i]))
            continue;
        else
            break;
    }
    
    if(str[i] == '+')
    {
        sign = 1;
        i++;
    }

    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }

    /*check rest of the string */

    for(; i < len; i++)
    {
        if(!isdigit(str[i]))
               break;
        else
        {
            //check for integer overflow
            if(sign > 0 && OverFlow(res,sign*(str[i] - '0')))
                return INT_MAX;
            if(sign < 0 && OverFlow(res,sign*(str[i] - '0')))
                return INT_MIN;
            
            res = 10 * res + sign*(str[i] - '0');      
        }
    }

    return res;
}

int main()
{
    cout << my_atoi("123") << endl;
    cout << my_atoi("12.455") << endl;
    cout << my_atoi("a123") << endl;
    cout << my_atoi("-123254adsdfd") << endl;
    cout << my_atoi("1234568940428285249245") << endl;
    cout << my_atoi("-1343843984398459849894") << endl;
    cout << my_atoi("2147483648") << endl;
    cout << my_atoi("-2147483648") << endl;
    cout << my_atoi("    10522545459") << endl;;
    return 0;
}
