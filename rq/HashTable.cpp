//Hashing with Separate Chaining
#include<iostream>
#include<list>
#include<utility>
#include<vector>
#include <functional>
using namespace std;

template<class K,class V>
class HashMap
{
    int N;  //number of key values
    int M;  //number of slots
    vector<list<pair<K,V> > > st ; //array of lists
    int hashFn(K key);
public:
    HashMap();
    ~HashMap();
    void put(K key, V val);
    V get(K key);
};



template<class K,class V> 
HashMap<K,V>::HashMap()
{
    M = 997;
    for(int i = 0; i < M; i++)
        st.push_back(list<pair<K,V> >() );
}

template<class K,class V> 
int HashMap<K,V>::hashFn(K key)
{
    std::hash<K> hash_fn;
    return (hash_fn(key) & 0x7fffffff) % M;
}

template<class K,class V> 
void HashMap<K,V>::put(K key,V val)
{
    st[hashFn(key)];
}

template<class K,class V>
V HashMap<K,V>::get(K key)
{

}

template<class K,class V>
HashMap<K,V>::~HashMap()
{

}

int main()
{
    HashMap<string,int> mp;
    return 0;
}
