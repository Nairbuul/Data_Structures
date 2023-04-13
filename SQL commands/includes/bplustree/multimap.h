#ifndef MULTIMAP_H
#define MULTIMAP_H

#include "bplustree.h"
#include "../stl_utils/vector_utilities.h"
#include "multipair.h"

template <typename K, typename V>
class MMap
{
public:
    typedef BPlusTree<MPair<K, V> > map_base;
    class Iterator{
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it = NULL): _it(it){}
        Iterator operator ++(int unused){
            return _it++;
        }
        Iterator operator ++(){
            return ++_it;
        }
        MPair<K, V> operator *(){
            return *_it;
        }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs){
            return lhs._it == rhs._it;
        }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs){
            return lhs._it != rhs._it;
        }

    private:
        typename map_base::Iterator _it;
    };

    MMap();

//  Iterators
    Iterator begin();
    Iterator end();

//  Capacity
    int size() const;
    bool empty() const;

//  Element Access
    const vector<V>& operator[](const K& key) const;
    vector<V>& operator[](const K& key);
    vector<V>& at(const K& key);
    const vector<V>& at(const K& key) const;

//  Modifiers
    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();

//  Operations:
    bool contains(const K& key) const ;
    vector<V> &get(const K& key);

    Iterator find(const K& key);
    int count(const K& key);
    // I have not writtent hese yet, but we will need them:
    Iterator lower_bound(const K& key);
    Iterator upper_bound(const K& key);
    Iterator equal_range(const K& key);

    bool is_valid();
    
    void print_lookup();
    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me){
        outs<<print_me.mmap<<endl;
        return outs;
    }

private:
    BPlusTree<MPair<K, V> > mmap;
};
//Definitions
template <typename K, typename V>
MMap<K,V>::MMap():mmap(map_base()){
    //leave empty.
}
//  Iterators
template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::begin(){
    return mmap.begin();
}
template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::end(){
    return mmap.end();
}
//  Capacity
template <typename K, typename V>
int MMap<K,V>::size() const{
    return mmap.size();
}
template <typename K, typename V>
bool  MMap<K,V>::empty() const{
    return mmap.empty();
}

//  Element Access
template <typename K, typename V>
const vector<V>&  MMap<K,V>::operator[](const K& key) const{
    return (mmap.get(key)).value_list;
}
template <typename K, typename V>
vector<V>&  MMap<K,V>::operator[](const K& key){
    return (mmap.get(key)).value_list;
}
template <typename K, typename V>
vector<V>& MMap<K,V>::at(const K& key){
    return (mmap.get(key)).value_list;
}
template <typename K, typename V>
const vector<V>& MMap<K,V>::at(const K& key) const{
    return (mmap.get(key)).value_list;
}
//  Modifiers
template <typename K, typename V>
void MMap<K,V>::insert(const K& k, const V& v){
    mmap.insert(MPair<K,V>(k,v));
}
template <typename K, typename V>
void MMap<K,V>::erase(const K& key){
    mmap.remove(key);
}
template <typename K, typename V>
void MMap<K,V>::clear(){
    mmap.clear_tree();
}

//  Operations:
template <typename K, typename V>
bool MMap<K,V>::contains(const K& key) const{
    return mmap.contains(key);
}

template <typename K, typename V>
vector<V> &MMap<K,V>::get(const K& key){
    return mmap.get(key);
}

template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::find(const K& key){
    return mmap.find(key);
}

template <typename K, typename V>
int MMap<K,V>::count(const K& key){
    return 0;
}
template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::lower_bound(const K& key){
    return mmap.lower_bound(key);
}
template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::upper_bound(const K& key){
    return mmap.upper_bound(key);
}
template <typename K, typename V>
typename MMap<K,V>::Iterator MMap<K,V>::equal_range(const K& key){
    return mmap.equal_range(key);
}

template <typename K, typename V>
bool MMap<K,V>::is_valid(){
    return mmap.is_valid();
}

template<typename K, typename V>
void MMap<K,V>::print_lookup(){
    assert(!empty());
    MMap<string ,string>::Iterator walker = begin();
    while(walker != end()){
        cout << setw(8) << (*walker).key << ':' <<setw(13) << (*walker).value_list << endl;
        walker++;
    }
}
#endif