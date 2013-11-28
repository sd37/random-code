//http://oj.leetcode.com/problems/powx-n/
#include<iostream>
#include<string>
#define ERROR -921
using namespace std;

//what if x = 0  and n = 0
int pow_slow(int x,int n)
{
    //complexity is linear because we are not saving intermediate answers
    if(n == 0)
        return 1;

    if(n % 2 == 0)
        return pow_slow(x,n/2) * pow_slow(x,n/2);
    else
        return x * pow_slow(x,n/2) * pow_slow(x,n/2);

}

int pow_log(int x,int n)
{
    if(n == 0)
        return 1;

    int temp = pow_log(x,n/2);

    if(n % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;

}

//for x is double
double pow(double x,int n)
{
    if(n == 0)
        return 1;

    double temp = pow(x,n/2);

    if(n % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

double gen_pow(double x, int n)
{
    //general checking
    if( n < 0)
    {
        if(x == 0)
        {
            cout << "0 error:" << "x == 0 " << endl;
            return ERROR;
        }

        return pow(1/x , n);
    }

    else
        return pow(x,n);
}

double pow_leetcode(double x, int n) {
        
	if(n == 0)
            return 1;
 
        double temp = pow(x,n/2);
        
        if(n % 2 == 0)
            return temp * temp;
        
        else
        {
            if( n < 0 )
            {
                if(x == 0.0)
                    throw "x == 0 exception";
                    
                return temp * temp * (1 / x);
            }
            else
                return temp * temp * x;
        }
}


int main()
{
    
    double x = 2.5;
    int n = -5;


    cout << gen_pow(x,n) << endl;
    return 0;
}
