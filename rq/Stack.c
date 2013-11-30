//implement a generic stack.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

struct stack
{
    void *el;
    int el_size;
    int actual_length;
    int alloc_length;
};

void StackNew(struct stack *s,int el_size);
void StackDestroy(struct stack *s);
bool StackEmpty(const struct stack *s);
void StackPush(struct stack *s, const void* el);
void StackPop(struct stack *s, void *el_pop);



void StackNew(struct stack *s, int el_size)
{
    assert(el_size > 0);
    s->el_size = el_size;
    s->alloc_length = 4; //initial allocated length . this is completely arbitary.
    s->el = malloc(s->alloc_length * s->el_size);
    assert(s->el != NULL);
}

void StackDestroy(struct stack *s)
{
    free(s->el);
    //free(s); //do not as it will give double free as there is malloced data within the structure.
}

bool StackEmpty(const struct stack *s)
{
    return s->actual_length == 0;
}

void StackPush(struct stack *s , const void* el)
{
   if(s->actual_length == s->alloc_length)
   {
       //increase the allocated space by 2.
       s->alloc_length *= 2;
       s->el = realloc(s->el,s->alloc_length * s->el_size);
       assert(s->el != NULL);
   }

   void* dest_addr = (char*)s->el + s->el_size * s->actual_length;
   memcpy(dest_addr,el,s->el_size);
   s->actual_length++;
}

void StackPop(struct stack *s, void* el_pop)
{
    if(StackEmpty(s))
    {
        fprintf(stderr,"Stack is empty\n");
        return;
    }

    void* top_addr = (char*)s->el + (s->actual_length - 1) * s->el_size;
    memcpy(el_pop,top_addr,s->el_size);
    s->actual_length--;
}

int main()
{
    int val;
    struct stack intStack;

    StackNew(&intStack, sizeof(int));
    
    for(val = 0; val < 6; val++)
        StackPush(&intStack, &val);
    
    while(!StackEmpty(&intStack))
    {
        StackPop(&intStack, &val);
        printf("Popped %d \n",val);
    }
    
    StackDestroy(&intStack);

    return 0;
}

