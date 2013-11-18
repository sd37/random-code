#include<iostream>
#include<map>
#define present(c,x) ((c).find(x) != (c).end())
using namespace std;

struct dlNode
{
    int val;
    struct dlNode* prev;
    struct dlNode* next;
};

class DLL
{
    int size;
    int maxn;
    struct dlNode* front;
    struct dlNode* rear;
public:
    map<int,struct dlNode*> pg_map; 
    DLL(int size);   
    void push(int val);
    void mvfront(struct dlNode* pg);
    void print()
    {
        struct dlNode* temp = front;
        while(temp)
        {
            cout << temp->val << "<-";
            temp = temp->next;
        }
    cout << "NULL\n";
    }
};

DLL::DLL(int size)
{
    this->size = 0;
    this->maxn = size;
    this->front = NULL;
    this->rear = NULL;
}
void DLL::mvfront(struct dlNode* pg)
{
    if(front == pg)
        return;
    
    else if(rear == pg)
    {
        pg->prev->next = NULL;
        rear = pg->prev;
    }
    else
    {
        pg->prev->next = pg->next;
        pg->next->prev = pg->prev;
    }
    pg->next = front;
    front = pg;
}

void DLL::push(int val)
{
   struct dlNode* pgNode = new struct dlNode;
   pgNode->val = val;
   pgNode->prev = NULL;
   pgNode->next = NULL;

   if(size == maxn)
   {
        //apply LRU replacement policy
        
        //step 1 first remove the rear and update rear

        struct dlNode* temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        pg_map.erase(temp->val);
        delete temp;
           
        // now just add the new element in the front.
        
        pgNode->next = front;
        pgNode->next->prev = pgNode;
        front  = pgNode;
   }
   else
   {
       if(front == NULL)
       {
            front = rear  = pgNode;
       }
       else
       {
            //add element to the front
            pgNode->next = front;
            pgNode->next->prev = pgNode;
            front = pgNode;
             
       }
    size++;
   }
    //finally add that page into the map

   pg_map[pgNode->val] = pgNode; 
}

class LruCache
{
    DLL* lruCache;
public:
    LruCache(int n);
    void referencePage(int pageNumber);    
    void print()
    {
        lruCache->print();
    }
};

LruCache::LruCache(int n)
{
    this->lruCache = new DLL(n);
}

void LruCache::referencePage(int pageNumber)
{
    if(!present(lruCache->pg_map,pageNumber))
    {
        lruCache->push(pageNumber);
    }
    else
    {
        //move that page to the front of the queue
        struct dlNode* pg = lruCache->pg_map[pageNumber];
        lruCache->mvfront(pg); 
    }

}

int main()
{
    LruCache lru(4);
 
    lru.referencePage(1);
    lru.referencePage(2);
    lru.referencePage(3);
    lru.referencePage(1);
    lru.referencePage(4);
    lru.referencePage(5);
 
    // Let us print cache frames after the above referenced pages
    lru.print();
    return 0;
}
