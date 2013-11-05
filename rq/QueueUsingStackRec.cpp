#include<iostream>
#include<stack>
#include<string>

using namespace std;

class QueueUsingStack
{
    stack<string> s;
public:
    void enqueue(string x);
    string dequeue();
};

void QueueUsingStack::enqueue(string x)
{
    s.push(x);
}

string QueueUsingStack::dequeue()
{
    static string pop_ans;

    if(s.empty())
    {
        return "";
    }

    string res = s.top();
    s.pop();
    string ires = dequeue();
    
    if(ires != "")
        s.push(res);
    else
    {
        pop_ans = res;
    }
    return pop_ans;
}

int main()
{
    QueueUsingStack q;
    q.enqueue("1");
    q.enqueue("2");
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.dequeue();
    q.enqueue("3");
    q.enqueue("4");
    q.enqueue("5");
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue("6");
    q.enqueue("7");
    return 0;
}
