#ifndef DOUBLE_HASH_H
#define DOUBLE_HASH_H

#include "constants.h"

template<typename T>
class DoubleHash
{
public:
    // static const int CAPACITY = TABLE_SIZE;        //size of the table
    static const int CAPACITY = 19;
    DoubleHash( );                      //CTOR

    bool insert(const T& entry);         //insert entry; false if overwriting.
    bool remove(int key);                //remove this key

    bool is_present(int key) const;      //is this key present?
    bool find(int key, T& result) const; //result <- record with this key
    int size( ) const { return _used; }   //number of keys in this table
                                         //number of collisions in this table
    long collisions() const {return _collisions;}
    long capacity() const {return CAPACITY;}

    //print the entire talbe with keys, records, and hash values
    template<typename TT>
    friend ostream& operator << (ostream& outs,const DoubleHash<TT>& h){
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
    static const int NEVER_USED = -1;        //this cell has never had a value
    static const int PREVIOUSLY_USED = -2;   //this cell has previously
                                             //   held a value that has since
                                             //been deleted.

    vector<T> _data;                          //table of records
    int _used;                                //number of keys in the table
    long _collisions;
    
    int hash(int key) const;                //hash function
    int hash2(int key) const;               //hash2 function
    int hashkey(const string& s);           //string to hash 
    int next_index(int index, int key) const;       //wrap around index
    bool find_index(int key, int& index) const;     //find index of this key
    bool never_used(int index) const;      //is this cell NEVER_USED
    bool is_vacant(int index) const;       //is this cell available for insert
};
// =================================Definitions =================================
template<typename T>
DoubleHash<T>::DoubleHash( ){
    _data.resize(CAPACITY, NEVER_USED);
    _used = 0;
    _collisions = 0;
}
template<typename T>
bool DoubleHash<T>::insert(const T& entry){
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
        _collisions++;
        index = next_index(index, entry._key);
        if(count >= CAPACITY){
            return false;
        }
    }
    _used++;
    _data[index] = entry;

    return true;
}       
template<typename T>
bool DoubleHash<T>::remove(int key){
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
bool DoubleHash<T>::is_present(int key) const{
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
bool DoubleHash<T>::find(int key, T& result) const{
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

//========================Helper Functions ==================================
template<typename T>
int DoubleHash<T>::hash(int key) const{
    return (key % CAPACITY);
}
template<typename T>
int DoubleHash<T>::hash2(int key) const{
    return 1 + (key % (CAPACITY-2));
}
template<typename T>
int DoubleHash<T>::next_index(int index, int key) const{
    return hash2(key);
    // return (index + hash2(key))eCAPACITY;
}
template<typename T>
int DoubleHash<T>::hashkey(const string & s){
    int result = 0;
    for(int i = 0; i < s.length(); i++){
        result = result + static_cast<int>(s[i]);
    }
    return hash(result);
}
template<typename T>
bool DoubleHash<T>::find_index(int key, int& index) const{
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
bool DoubleHash<T>::never_used(int index) const{
    assert(index < CAPACITY && "Double_hash never_used()");
    return _data[index]._key == NEVER_USED;
}
template<typename T>
bool DoubleHash<T>::is_vacant(int index) const{
    assert(index < CAPACITY && "Double_hash is_vacant()");
    return _data[index]._key < 0;
}
//==========================================================================   
#endif