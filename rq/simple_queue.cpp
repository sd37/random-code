#include<iostream>
#include<map>
#define present(c,x) ((c).find(x) != (c).end())
using namespace std;

//A queue will be implemented as a Doubly Linked List

struct dlNode 
{
    int val;
    struct dlNode* prev;
    struct dlNode* next;
};

class Queue
{
    int maxSize;
    int currentSize;
    struct dlNode* front;
    struct dlNode* rear;
public:
    Queue(int maxSize);
    ~Queue();
    void enqueue(int data);
    void dequeue();
    void print();
};

Queue::Queue(int maxSize)
{
    this->maxSize = maxSize;
    this->currentSize = 0;
    this->front = NULL;
    this->rear = NULL;
}

void Queue::enqueue(int val)
{
    struct dlNode* new_node = new struct dlNode;
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(currentSize != maxSize)
    {    
        if(front == NULL)
        {
            //first element is inserted
            
            front = rear = new_node;
        }
        else
        {
            //update front

            new_node->next = front;
            new_node->next->prev = new_node;
            front = new_node;
        }
        currentSize++;
    }
    else
    {
        cout << "Queue is full : Error Inserting Element\n";
    }
    //print current queue after operation
    cout << "Current Queue after enqueue("<< val <<")\n";
    print();
}
void Queue::dequeue()
{
    if(currentSize == 0)
    {
        cout << "Empty Queue : Cannot perform dequeue\n";
        return;
    }

    //remove element from front

    struct dlNode* temp = front;
    if(front->next == NULL)
    {
        //the queue has only one element and it has to be deleted
        front = rear = NULL;
        delete temp;
    }
    else
    {    
        front = front->next;             
        front->prev = NULL;
        delete temp;
    }
    
    currentSize--;
    cout << "Current Queue after dequeue()\n";
    print();
}

Queue::~Queue()
{
    cout << "Program ended free Queue\n";
    struct dlNode* temp = front;
    struct dlNode* prev = NULL;
    while(temp)
    {
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    front = rear = NULL;
}

void Queue::print()
{
    struct dlNode* temp = front;
    while(temp)
    {
        cout << temp->val << "<->";
        temp = temp->next;
    }
cout << "NULL\n";
}

int main()
{
    //driver program
    
    Queue q(4);

    q.dequeue();
    q.enqueue(4);
    q.enqueue(45);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(78);
    q.enqueue(34);
    q.dequeue();
    q.enqueue(44);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(33);
    q.enqueue(23);
    return 0;
}
