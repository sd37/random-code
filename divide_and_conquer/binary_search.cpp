#include<iostream>
#include<string>

using namespace std;
int RecBinarySearch(int arr[],int low,int high,int num)
{
    if(low > high)
        return -1;

    int mid = (high - low)/2 + low;
    
    if(arr[mid] == num)
        return mid;
    else if(num < arr[mid])
        return RecBinarySearch(arr,low,mid-1,num);
    else
        return RecBinarySearch(arr,mid+1,high,num);
}

int ItBinarySeacrh(int arr[],int low,int high,int num)
{
    while(low <= high)
    {
        int mid = (high - low) / 2 + low;

        if(arr[mid] == num)
            return mid;
        else if(num < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    
    }

    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    cout << RecBinarySearch(arr,0,9,3) << endl;
    cout << RecBinarySearch(arr,0,9,7) << endl; 
    cout << RecBinarySearch(arr,0,9,44) << endl;

    cout << ItBinarySeacrh(arr,0,9,3) << endl;
    cout << ItBinarySeacrh(arr,0,9,7) << endl;
    cout << ItBinarySeacrh(arr,0,9,28) << endl;
    return 0;
}
