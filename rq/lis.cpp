#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

void longest_improvement(const vector<int> &grades) {
	
	int *lis = new int [grades.size()];
	for(int i = 0;i < grades.size();i++)
	{
		lis[i] = 1;
	}
	
	for(int i = 1;i<grades.size();i++)
	{
		if(grades[i-1] <= grades[i])
		{
			lis[i] = lis[i-1] + 1;	
		}	
	}    
   	
	int maxe = lis[0];
	for(int i = 1; i < grades.size();i++)
	{
		if(maxe < lis[i])
		{
			maxe = lis[i];
		}
	} 
	cout << maxe << "\n";
}

int main()
{
	int arr[] = {9,7,8,2,5,5,8,7};
	vector<int> grades(arr,arr + sizeof(arr) / sizeof(int) );
	longest_improvement(grades);		
return 0;
}
