#include<iostream>
#include<string>
#include<queue>

using namespace std;

class Stack
{
    queue<string> q1;
    queue<string> q2;
    public:
        bool isEmpty();
        string pop();
        void push(string x);
        
};

void Stack::push(string x)
{
    //keep pushing elements in q1
    q1.push(x);
}

string Stack::pop()
{
    if(q1.empty())
        return "";
    while(q1.size() != 1)
    {
        string tmp = q1.front();
        q1.pop();
        q2.push(tmp);
    }
    string ans = q1.front();
    q1.pop();
    swap(q1,q2);
    return ans;
}

int main()
{
    Stack s;
    s.push("1");
    s.push("2");
    s.push("3");
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}
