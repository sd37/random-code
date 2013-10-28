//Hashing with Separate Chaining
#include<iostream>
#include<list>
#include<utility>
#include<vector>
#include <functional>
using namespace std;

class HashMap
{
    int N;  //number of key values
    int M;  //number of slots
    vector<list<pair<string,int> > > st ; //array of lists
    int hashFn(string key);
    void resize(int newSize);
public:
    HashMap();
    ~HashMap();
    void put(string key, int val);
    int  get(string key);
    void del(string key);
};


HashMap::HashMap()
{
    N = 0;
    M = 31;
    for(int i = 0; i < M; i++)
        st.push_back(list<pair<string,int> >() );
}

int HashMap::hashFn(string key)
{
    std::hash<string> hash_fn;
    return (hash_fn(key) & 0x7fffffff) % M;
}

void HashMap::put(string key,int val)
{
    N++;
    st[hashFn(key)].push_front(make_pair(key,val));
}

int HashMap::get(string key)
{
    list<pair<string,int> >  *ll = &st[hashFn(key)];
    list<pair<string,int> >::iterator it;
    for(it = (*ll).begin(); it != (*ll).end(); it++)
    {
       if(it->first  == key )
       {
            return it->second;
       }
    }
    return -1; // just in case the element is not found
}

void HashMap::del(string key)
{
    list<pair<string,int> >*ll = &st[hashFn(key)];
    list<pair<string,int> >::iterator it;

    for(it = (*ll).begin(); it != (*ll).end(); it++)
    {
        if(it->first == key)
        {
            break;
        }
    }

    if(it != (*ll).end())
        (*ll).erase(it);
    else
    {
        cout << "Element not found \n";
        return;
    }

}

void HashMap::resize(int newSize)
{
    

}


HashMap::~HashMap()
{

}

int main()
{
    HashMap mp;
    
    mp.put("spandan",401219);
    mp.put("dutta",1234);
    mp.put("imini",7890);

    cout << mp.get("spandan") << endl;
    cout << mp.get("dutta") << endl;
    cout << mp.get("dam") << endl;
    
    cout << mp.get("imini") << endl;
    mp.del("imini");
    cout << mp.get("imini") << endl;
    mp.del("dam");
    return 0;
}
