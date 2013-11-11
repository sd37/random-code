#include<iostream>
#include<string>

/*
Assert.that(isNumber("123"), true);
Assert.that(isNumber("abc"), false);
Assert.that(isNumber(""), false);
Assert.that(isNumber("1.23"), true);
Assert.that(isNumber("-1.23",true));
Assert.that(isNumber("-1",true));
Assert.that(isNumber("1.23."),false);
Assert.that(isNumber("+123"), false);
*/

using namespace std;

bool isNumber(string s)
{
    int len = s.length();

    bool dot_seen = false;

    if(len == 0)
        return false;

    for(int i = 0; i < len; i++)
    {
        if(!dot_seen && s[i] == '.')
            dot_seen = true;
        
        else if(dot_seen && s[i] == '.')
            return false;
       
        else if(i == 0 && (s[i] == '+' || s[i] == '-'))
            continue;

        else if(!isdigit(s[i]))
            return false;
    
    }

    return true;
}

int main()
{
    cout << isNumber("+123")<< endl;
    cout << isNumber("1.23.")<< endl;
    cout << isNumber("1.234") << endl;
    cout << isNumber("-14") << endl;
    cout << isNumber("") << endl;
    cout << isNumber("abc") << endl;
    return 0;
}
