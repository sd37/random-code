#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

void disp_arr(int arr[],int first,int last)
{   
    for (int i = first ; i <= last; i++)
        printf("%d ",arr[i]);
}

void swap(vector<int> &arr,int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partion(vector<int> &arr,int first , int last)
{
    int mid = (last - first) / 2 + first;
    swap(arr,first,mid);
    int pivot = arr[first];

    int i;
    int j = first + 1;

    for(i = first + 1; i <= last; i++)
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

int quick_select(vector<int> &arr,int first,int last,int k)
{
    while(1)
    {
        if(first == last)
        {
            return arr[first];
        }

        int pivot_curr = partion(arr,first,last);

        int pivot_dist = pivot_curr - first;
        
        if (pivot_dist == k)
            return arr[pivot_curr];
    
        else if (k < pivot_dist)
        {
            last = pivot_curr - 1;        
        }
        else
        {
            k = k - pivot_dist - 1; 
            first = pivot_curr + 1;  
        }
    }
}

int main()
{
    vector<int> arr;
    int len;
    
    /*int arr[] = {45,32,12,31,8,90,10,100,87,97,67,11};
    //int arr[] = {0,1,2,4,6,5,3};
    //int pivot = partion(arr,0,SIZE(arr) - 1);

    for (int k = 0; k < SIZE(arr); k++)
    {    
        int ans = quick_select(arr,0,SIZE(arr) - 1,k);
        printf("(%d) %d\n",k , ans);
    }
    */
    cin >> len;
    int save_len = len;
    while(save_len--)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    int median;
    
    if(len % 2 == 0)
    {
        int x1 = quick_select(arr,0,len - 1 , len / 2);
        int x2 = quick_select(arr,0,len - 1 , len / 2  + 1 );
        median = (x1 + x2) / 2;
    }   
    else
        median = quick_select(arr,0,len - 1, len / 2);

    cout << median << endl;
    return 0;
}
