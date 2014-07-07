#include<iostream>
#include<string>

using namespace std;

class Solution
{

        void reverseString(string &s, int lo, int hi)
        {
            char temp;

            while(lo < hi)
            {
                temp = s[lo];
                s[lo] = s[hi];
                s[hi] = temp;
                lo++;
                hi--;
            }
        }
    
    public:
    
        void reverseWords(string &s)
        {

            // reverse entire string
            
            reverseString(s, 0 , s.length() - 1);        
             
            // reverse individual words 
            
            for(int i = 0; i < (int)s.length(); i++)
            {
               if( isspace(s[i]) )
                   continue;
               
               else
               {
                    int lo = i;
                    int hi = lo;

                    for(; hi < (int)s.length(); hi++)
                    {
                        if( !isspace(s[hi]) )
                            continue;
                        else
                        {   
                            break;
                        }
                    }
                    
                    i = hi; // update i

                    reverseString(s, lo, hi - 1);
               }
            }
        }
    

};


int main()
{
    string s("the sky is blue");

    Solution soln;

    soln.reverseWords(s);

    cout << s << endl;
    return 0;
}
