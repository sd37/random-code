#include<iostream>
#include<string>

using namespace std;

void permute(string &s,int i ,int n)
{
    if(i == n)
    {
        cout << s << endl;
        return;
    }
    else
    {
        for(int j = i; j <= n; j++)
        {
            swap(s[i],s[j]);
            permute(s,i+1,n);
            swap(s[i],s[j]); //backtrack
        }
    }
}

int main()
{
    string s("ABC");
    //s[0] = 's';
    //s[1] = 'p';
    permute(s,0,s.length() - 1);
    return 0;
}
