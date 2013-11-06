#include<iostream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
void print(set<pair <int,pair<int,int>> >&s)
{
    cout << "actual print" << endl;
    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout << it->first << "," << it->second.first <<"," << it->second.second << endl; 
    
    }

}
void ThreesumNaive(vector<int>& v,int t)
{
    set<pair<int,pair<int,int> > > ans;
    int n = v.size();
    for(int i = 0; i < n - 2; i++ )
    {
        for(int j = i + 1; j < n - 1; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(v[i] + v[j] + v[k] == t) 
                {
                    cout << v[i] << "," << v[j] << "," << v[k] << endl;             
                    vector<int> vv({v[i],v[j],v[k]});
                    std::sort(vv.begin(),vv.end());
                    ans.insert(make_pair(vv[0],make_pair(vv[1],vv[2])));
                }
            }
        }
    
    }
print(ans);
}

void Threesum(vector<int> &v,int t)
{
    int n = v.size();
    std::sort(v.begin(),v.end());
    set<pair<int,pair<int,int> > > ans;
    for(int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int h = n - 1;
        while(l < h)
        {
            if(v[i] + v[l] + v[h] == t)
            {
                cout << v[i] << "," << v[l] << "," << v[h] << endl;
		vector<int> vv({v[i],v[l],v[h]});
                std::sort(vv.begin(),vv.end());                
		ans.insert(make_pair(vv[0],make_pair(vv[1],vv[2])));
                h--;
            }
            else if (v[i] + v[l] + v[h] < t)
                l++;
            else
                h--;
            
        }
    }
print(ans);
}

int main()
{
    //vector<int>v({1,4,45,6,10,8,12,2,2,1,3});
    vector<int>v({1,4,45,6,10,8});
    ThreesumNaive(v,15);
    cout << endl;
    Threesum(v,15);
    return 0;
}
