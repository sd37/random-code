#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

#define present(c,x) (c).find(x) != (c).end()

typedef int index;
typedef int val;

using namespace std;
void print(set<pair<int,int> >&);
void two_sum1(vector<int>& v,int t)
{
    set<pair<index,index> > ans;
    std::sort(v.begin(),v.end());

    int l = 0;
    int h = v.size() - 1;

    while(l < h)
    {
        if(v[l] + v[h] == t)
        {
            ans.insert(make_pair(v[l],v[h]));
            h--;
        }
        else if(v[l] + v[h] < t)
            l++;
        else
            h--;
    }
cout << "final answers " << endl;
print(ans);
}



void two_sum2(vector<int>& v,int t)
{
    //assume the vector contains distinct elements
    map<val,index> m;

    for(int i = 0; i < v.size(); i++)
    {
        pair<int,int> res;
        if(present(m,v[i]))
        {
            res.first = i + 1;
            res.second = m[v[i]] + 1;

            if(res.first > res.second)
            {
                swap(res.first,res.second);
            }
            
            cout << res.first << ", " << res.second << endl;
        }

        else
        {
            m.insert(make_pair(t - v[i] , i));    
        }
    
    }
}

void print(set<pair<int,int> >&s)
{
    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout << it->first << "," << it->second << endl;
    }

}
void two_sum3(vector<int>& v, int t)
{
    //assume the vector can contain duplicate elements.
    //this is the most general solution.
    set<pair<index,index> > answers; 
    unordered_map<val,unordered_set<index> > m;
    
    for(int i = 0; i < v.size(); i++)
    {
        if( !(present(m,v[i])) )
        {
            m[v[i]] = unordered_set<index>();
            m[v[i]].insert(i);
        }
        else
        {
            m[v[i]].insert(i);
        }
    }

    for(int i = 0; i < v.size(); i++)
    {
        if( present(m,t - v[i]))
        {
            pair<int,int> res;

            for(auto it = m[t-v[i]].begin(); it != m[t-v[i]].end(); it++)
            {
               res.first = i;
               res.second = *it;
               
               if(res.first > res.second)
                   swap(res.first,res.second);
               if(res.first != res.second)
               {
                   cout << res.first << "," << res.second << endl;
                   answers.insert(res);
               }
            }
        }
    
    }
cout << "final answers" << endl;    
print(answers);
}

int main()
{
    vector<int> v({2,1,2,3,4,3,5});
    //vector<int> v({6,5,4,1,2,3});
    //two_sum2(v,6);
    two_sum3(v,6);
    two_sum1(v,6);
}
