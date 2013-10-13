#define SIZE(a) (sizeof(a) / sizeof(a[0]))
#include<iostream>
#include<stdio.h>

using namespace std;

void disp_arr(int arr[],int first,int last)
{   
    for (int i = first ; i <= last; i++)
        printf("%d ",arr[i]);
}
void swap(int arr[],int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partion(int arr[],int first , int last)
{
    int mid = (last - first) / 2 + first;
    swap(arr,first,mid);
    int pivot = arr[first];

    int i;
    int j = 1;

    int len = last - first + 1;
    for(i = 1; i < len; i++)
    {
        if(arr[i] < pivot)
        {
            swap(arr,i,j);
            j = j + 1;
        }
    
    }
    
    swap(arr,first,j - 1);
    return j - 1;
}

int quick_select(int arr[],int first,int last,int k)
{
    if (k > last - first + 1)
    {
        printf("error\n");
        return -1;
    }
    while(1)
    {
        int pivot_curr = partion(arr,first,last);

        int pivot_dist = pivot_curr - first;
        
        if (pivot_dist == k)
            return arr[pivot_curr];
    
        else if (k < pivot_dist)
        {
            last = pivot_curr;        
        }
        else
        {
            k = k - pivot_curr;
            first = pivot_curr + 1;
        }
    }
}

int main()
{
    int arr[] = {45,32,12,31,8,90,10};
    //int pivot = partion(arr,0,SIZE(arr) - 1);

    int k = 5;
    for (k = 0; k < SIZE(arr); k++)
    {    
        int ans = quick_select(arr,0,SIZE(arr) - 1,k);
        printf("(%d) %d\n",k , ans);
    }
    return 0;
}
