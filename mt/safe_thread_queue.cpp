#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

//A queue will be implemented as a Doubly Linked List.
//Enqueue : O(1)
//Dequeue : O(1)

// Description:
// Only one thread at time can modify the queue
// If enqueue is done when the queue is full then it waits  for any one thread to dequeue()
// If dequeue is done when the queue is empty then it waits for any one thread to enqueue().
// In the main function
// for testing we have 
// t1 = enqueue Thread
// t2 = dequeue Thread
// t3 = dequeue Thread

//Running Program:
//type : g++ -o safe safe_thread_queue.cpp -pthread -std=c++11
//in the terminal to compile
//and then type ./safe in the terminal
//to run the program 

struct dlNode 
{
    int val;
    struct dlNode* prev;
    struct dlNode* next;
};

class ThreadSafeQueue
{
    mutex mut;
    condition_variable enq_cond;
    condition_variable dq_cond;
    int maxSize;
    int currentSize;
    struct dlNode* front;
    struct dlNode* rear;
public:
    ThreadSafeQueue(int maxSize);
    ~ThreadSafeQueue();
    void enqueue(int data);
    int dequeue();
    void print();
};

ThreadSafeQueue::ThreadSafeQueue(int maxSize)
{
    this->maxSize = maxSize;
    this->currentSize = 0;
    this->front = NULL;
    this->rear = NULL;
}

void ThreadSafeQueue::enqueue(int val)
{
    struct dlNode* new_node = new struct dlNode;
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = NULL;
    
    unique_lock<mutex> lk(mut); //lock the below code for synchronization

    if(currentSize != maxSize)
    {    
        if(front == NULL)
        {
            //first element is inserted
            
            front = rear = new_node;
        }
        else
        {
            //update rear
            
            new_node->prev = rear;
            rear->next = new_node;
            rear = rear->next;
        }
    }
    else
    {
        cout << "Thread ID: " << this_thread::get_id() << " > Queue is full : Error Inserting Element : " << val << "\n";
        cout << "Thread ID: " << this_thread::get_id() << " > Waiting for someone to dequeue\n";
        enq_cond.wait(lk,[this]{return currentSize != maxSize;});         
        
        if(front == NULL)
        {
            //first element is inserted
            
            front = rear = new_node;
        }
        else
        {
            //update rear
            
            new_node->prev = rear;
            rear->next = new_node;
            rear = rear->next;
        }
    }
    
    currentSize++;

    //print current queue after operation
    cout <<"Thread ID:" << this_thread::get_id() <<" > Current Queue after enqueue("<< val <<")\n";
    print();
    lk.unlock();
    
    //notify one of the many sleeping dequeue threads to continue
    dq_cond.notify_one();
}

int ThreadSafeQueue::dequeue()
{
    unique_lock<mutex> lk(mut); //lock the mutex immidiately
    
    if(currentSize == 0)
    {
        //this code is just for documentation
        cout <<"Thread ID:" << this_thread::get_id() << " > Empty Queue : Cannot perform dequeue\n";
        cout <<"Thread ID:" << this_thread::get_id() << " > Waiting for some thread to enqueue\n";
    }
    
    dq_cond.wait(lk,[this]{return currentSize != 0;});
    //at this point the lock on the mutex is acquired again
    
    //remove element from front

    struct dlNode* temp = front;
    int data  = front->val;

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
    cout << "Thread ID :" << this_thread::get_id() << " > Current Queue after dequeue()\n";
    print();
    lk.unlock(); //unlock the mutex immidiatley

    //notify one of the many sleeping enqueue threads to continue
    enq_cond.notify_one();
    
    return data;
}

ThreadSafeQueue::~ThreadSafeQueue()
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

void ThreadSafeQueue::print()
{
    struct dlNode* temp = front;
    while(temp)
    {
        cout << temp->val << "<->";
        temp = temp->next;
    }
cout << "NULL\n";
}

namespace Tasks
{
    void enqueue_tasks(ThreadSafeQueue& q)
    {
        q.enqueue(4);
        q.enqueue(45);
        q.enqueue(6);
        q.enqueue(7);
        q.enqueue(78);
        q.enqueue(77);
        q.enqueue(34);
	q.enqueue(44);
        q.enqueue(454);
        q.enqueue(64);
        q.enqueue(74);
        q.enqueue(784);
        q.enqueue(774);
        q.enqueue(344);
        return;
    }
    void dequeue_tasks(ThreadSafeQueue& q)
    {
        int val;
        val = q.dequeue();
        cout << "Dequeued element: "  << val <<"\n";
        val = q.dequeue();
        cout << "Dequeued element: "  << val << "\n";
        val = q.dequeue();
        cout << "Dequeued element: "  << val << "\n"; 
        val = q.dequeue();
        cout << "Dequeued element: "  << val << "\n";
        val = q.dequeue();
        cout << "Dequeued element: "  << val << "\n";
        val = q.dequeue();
        cout << "Dequeued element: "  << val << "\n";
        val = q.dequeue();
        cout << "Dequeued element: "  << val << "\n";
        return;
    }
}

int main()
{
    //driver program
    
    ThreadSafeQueue q(4);
    
    thread t1(Tasks::enqueue_tasks,std::ref(q));
    thread t2(Tasks::dequeue_tasks,std::ref(q));
    thread t3(Tasks::dequeue_tasks,std::ref(q));
    //wait for all the threads to finish
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
