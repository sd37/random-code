//http://www.talentbuddy.co/challenge/51ce446a4af0110af3826346
//backtracking

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void print(int arr[],int size)
{
	for(int i = 0; i < size;i++)
		printf("%d ",arr[i]);
	cout << endl;
}

int solveQ(int config[],int start,int end,int val,int a,int b,int c,int n)
{
	int count = 0;
	int save_n1 = n,save_n2,save_n3;
	int save_a = a;
	int save_b = b;
	int save_c = c;
	if(n == 0)
	{
		return count;
	}		
	
		int i; 

		while(a >= 0)
		{
			i = 0;
			n = save_n1; //1st level
			b = save_b;
			c = save_c;
			config[i] = a;
			n = n - a;
			while(b >= 0 && n >= 0)
			{
				if(n == 0)
				{	
					config[i+1] = 0;
					config[i+2] = 0;
					print(config,3);
					count++;
					break;	
				}
				else if(n<=b)
				{
					
					b = n;
					config[i+1] = n;
					save_n2 = n; //2nd level
					n = n - config[i+1];
				}
				else if(n > b && b != 0) 
				{
					config[i+1] = b;
					save_n2 = n;
					n = n - config[i+1];
				}
				else if(b == 0)
				{
					config[i+1] = b;
				}
				while( c >= 0 && n >= 0)
				{
					if(n == 0)
					{
						config[i+2] = 0;
						print(config,3);
						count++;
						n = save_n2;
						break;
					}
					else if(n<=c)
					{
						config[i+2] = n;
						n = n - config[i+2];
						if(n == 0)
						{
							print(config,3);
							count++;
							n = save_n2;
							break;
						}
					}
					else
					{
						break;
																
					}
				
				}
				b = config[i+1];	  		
				b--;
			}
			a--;
		}			

return count;
}

void count_configurations(int a,int b, int c,int n)
{
	int config[3] = {0,0,0};
	int count = solveQ(config,0,2,0,a,b,c,n);
	printf("%d\n",count);
}
int main()
{
	int a,b,c,n;
	a = 4, b = 4 , c =6  , n = 3;
	
	count_configurations(a,b,c,n);
	
	return 0;	
}
