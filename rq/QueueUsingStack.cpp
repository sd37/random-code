#include<iostream>
#include<stack>
#include<string>

using namespace std;

class QueueUsingStack
{
    stack<string> s1;
    stack<string> s2;
public:
    bool isEmpty();
    void enqueue(string x);
    string dequeue();
};

bool QueueUsingStack::isEmpty() 
{
    if(s1.empty() && s2.empty())
        return true;
    else
        return false;
}

void QueueUsingStack::enqueue(string x)
{
    //just push the element to stack1

    s1.push(x);
}

string QueueUsingStack::dequeue()
{
    if(isEmpty())
    {
        cout << "Error: isEmpty() = true" << endl;
        return ""; //you cannot simply return NULL , this gives you a segmentation fault
    }
    
    if(s2.empty())
    {
        while(!s1.empty())
        {
            string t = s1.top();
            s1.pop();
            s2.push(t);
        }
    }

    string f = s2.top();
    s2.pop();
    return f;
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
