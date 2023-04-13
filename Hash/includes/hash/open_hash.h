#ifndef OPEN_HASH_H
#define OPEN_HASH_H

#include "constants.h"

template<typename T>
class OpenHash
{
public:
    static const int CAPACITY = TABLE_SIZE;
    // static const int CAPACITY = 19;

    OpenHash( ); 

    bool insert(const T& entry);
    bool remove(int key);

    bool is_present(int key) const;
    bool find(int key, T& result) const;
    
    int size( ) const {return _used;}
    long collisions() const {return _collisions;}
    long capacity() const {return CAPACITY;} 

    template<typename TT>
    friend ostream& operator << (ostream& outs, const OpenHash<TT>& h){
        for(int i = 0; i < CAPACITY; i++){
            if(h._data[i] < 0){
                outs << "[" << i << "]" << endl;
            }
            else if(h.hash(h._data[i]._key) == i){
                outs << "[" << i << "]" << " " << h._data[i] <<"(" << h.hash(h._data[i]._key)
                << ")" << endl;
            }
            else{
                outs << "[" << i << "]" << " " << h._data[i] <<"(" << h.hash(h._data[i]._key)
                << ")" "* hash2: " << h.next_index(h._data[i]._key, h._data[i]._key) << endl;
            }
        }
        return outs;
    }

private: 
    static const int NEVER_USED = -1;
    static const int PREVIOUSLY_USED = -2;

    vector<T> _data;
    int _used;
    long _collisions; 
    
    int hash(int key) const;
    int hashkey(const string& s);
    
    int next_index(int index, int key) const;
    bool find_index(int key, int& index) const;
    bool never_used(int index) const;
    bool is_vacant(int index) const;
};
// =================================Definitions =================================
template<typename T>
OpenHash<T>::OpenHash( ){
    _data.resize(CAPACITY, NEVER_USED);
    _used = 0;
    _collisions = 0;
}
template<typename T>
bool OpenHash<T>::insert(const T& entry){
    assert(entry._key >= 0);
    assert(size() < CAPACITY);
    size_t index = hash(entry._key);
    size_t count = 0;

    if(is_present(entry._key)){
        return false;
    }

    if(is_vacant(index)){
        _used++;
        _data[index] = entry;
        return true;
    }

    while(!is_vacant(index)){
        index = next_index(index, entry._key);
        if(count >= CAPACITY){
            return false;
        }
    }
    _collisions++;
    _used++;
    _data[index] = entry;
    
    return true;
}
template<typename T>
bool OpenHash<T>::remove(int key){
    assert(key >= 0);
    int index = -1;

    if(find_index(key, index)){
        _data[index]._key = PREVIOUSLY_USED;
        _used--;
        return true;
    }

    return false;
}
template<typename T>
bool OpenHash<T>::is_present(int key) const{
    if(_data[hash(key)] < 0){
        return false;
    }

    for(int i = 0; i < CAPACITY; i++){
        if(_data[i]._key == key){
            return true;
        }
    }

    return false;
}
template<typename T>
bool OpenHash<T>::find(int key, T& result) const{
    assert(key >= 0);

    size_t count = 0;
    size_t index = hash(key);

    while(count < CAPACITY && !is_vacant(index) && _data[index]._key != key){
        count++;
        index = next_index(index, key);
    }
    if(_data[index]._key == key){
        result = _data[index];
        return true;
    }

    return false;
}
//========================Helper Functions =================================
template<typename T>
int OpenHash<T>::hash(int key) const{
    return (key % CAPACITY);
}
template<typename T>
int OpenHash<T>::hashkey(const string& s){
    int result = 0;
    for(int i = 0; i < s.length(); i++){
        result = result + static_cast<int>(s[i]);
    }
    return hash(result);
}
template<typename T>
int OpenHash<T>::next_index(int index, int key) const{
    if(index >= CAPACITY){
        return CAPACITY - ((index + 1) % CAPACITY);
    }
    return ((index + 1) % CAPACITY);
}
template<typename T>
bool OpenHash<T>::find_index(int key, int& index) const{
    assert(key >= 0);
    
    size_t count = 0;
    size_t i = hash(key);    

    while(count < CAPACITY && !is_vacant(i) && _data[i]._key != key){
        count++;
        i = next_index(i, key);
    }
    if(_data[i]._key == key){
        index = i;
        return true;
    }

    return false;
}
template<typename T>
bool OpenHash<T>::never_used(int index) const{
    assert(index < CAPACITY);
    return _data[index]._key == NEVER_USED;
}
template<typename T>
bool OpenHash<T>::is_vacant(int index) const{
    assert(index < CAPACITY);
    return _data[index]._key < 0;
}
//==========================================================================

#endif