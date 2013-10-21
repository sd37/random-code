#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void printList(struct node*head)
{
    struct node* temp = head;

    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void push(struct node** head,int data)
{
    struct node *pNode = (struct node*)malloc(sizeof (struct node));
    if(pNode == NULL)
    {
        return;
    }

    pNode->data = data;
    pNode->next = *head;

    *head = pNode;
}

void delAllInstance(struct node**head ,int data)
{
   struct node* temp = *head;
   struct node* prev = NULL;

   while(temp!=NULL)
   {
       if(temp->data == data)
       {
           if(temp == *head)
           {
               //at the head
               *head = temp->next;
               free(temp);
               temp = *head;
           }
           else if(temp->next == NULL)
           {
               //at the end of the list
               prev->next = NULL;
               free(temp);
               temp = NULL;
           }
           else
           {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
           }
       }
      
       else
       {
           prev = temp;
           temp = temp->next;
       }
    }
}

int delNode(struct node**head,int data)
{
    struct node* temp = *head;
    struct node* prev = NULL;
    
    while(temp!= NULL)
    {
        if(temp->data == data)
            break;
        prev = temp;
        temp = temp->next;
    }

    if(temp)
    {
        if(temp == *head)
        {
            //first element in ll
            *head = temp->next;
            free(temp);
        }
        else if(temp->next == NULL)
        {
            //at the last node
            prev->next = NULL;
            free(temp);
        }
        else
        {
            //at the middle
            prev->next = temp->next;
            free(temp);
        }
        
        return 0;
    }
    else
    {
        return -1;
    }
    
}

int main()
{
    struct node* head = NULL;
    push(&head,5);
    push(&head,2);
    push(&head,5);
    push(&head,5);
    push(&head,5);
    push(&head,6);
    push(&head,3);
    push(&head,10);
    push(&head,11);
    push(&head,5);
    push(&head,56);
    push(&head,5);

    printList(head);
    delAllInstance(&head,5);
    printList(head);
    /*
    int flag = delNode(&head,100);
    if (flag == -1)
    {
        printf("not found in list\n");
    }

    delNode(&head,2);
    printList(head);
    delNode(&head,3);
    printList(head);
    delNode(&head,10);
    printList(head);
    delNode(&head,6);
    printList(head);
    delNode(&head,5);
    printList(head);
    delNode(&head,6);
    */


    return 0;
}
