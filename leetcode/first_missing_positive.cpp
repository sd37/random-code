#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
        
        int seg(int A[],int n)
        {
            int f = 0;
            int l = n - 1;

            while(f < l)
            {
                if(A[f] > 0)
                    f++;
                else if (A[l] <= 0)
                    l--;
                else
                {
                    int temp = A[f];
                    A[f] = A[l];
                    A[l] = temp;
                }
            }

            int i;
            for(i = 0; i < n; i++)
            {
                if(A[i] <= 0)
                    break;
            }
            return i;
        }
        
        int firstMissingPositive(int A[],int n)
        {
            if(n == 0)
                return 1;

            int neg_index = seg(A,n);
            
            if(neg_index == 0)
                return 1;

            for(int i = 0; i < neg_index; i++)
            {
                if( abs(A[i]) - 1 < n  && A[abs(A[i]) -1] > 0 )
                {
                    A[abs(A[i]) - 1] = -A[abs(A[i]) -1];
                }
            }

            for(int i = 0; i < neg_index; i++)
            {
                if(A[i] > 0)
                    return i + 1;
            }

            return neg_index + 1;
        }

};

int main()
{
    Solution s;
    int a[] = {0};
    cout <<  s.firstMissingPositive(a,1) << endl;
    
    return 0;
}
