#ifndef CHAINED_HASH_H
#define CHAINED_HASH_H

#include "constants.h"
#include "../avl/avl.h"

template<typename T>
class ChainedHash
{
public:
    ChainedHash( );                              //CTOR

    bool insert(const T& entry);            //insert entry; false if overwriting.
    bool remove(int key);                   //remove this key

    bool find(int key, T& result) const;    //result <- record with key
    bool is_present(int key) const;         //is this key present in table?
    int size( ) const { return _total_records; }  //number of keys in the table
    long capacity(){return TABLE_SIZE;}


    //print entire table with keys, etc.
    template<typename TT>
    friend ostream& operator << (ostream& outs,const ChainedHash<TT>& h){
        // outs << h._data.<< endl;
        //print in order
        return outs;
    }

private:
    // AVL<T> _data[TABLE_SIZE];               //table chains
    AVL<T> _data[19];               
    int _total_records;                      //number of keys in the table

    int hash(int key) const;                //hash function
};
//AVL array[index] every index contains a different avl tree
template<typename T>
ChainedHash<T>::ChainedHash(){
    _total_records = 0;
}
template<typename T>
bool ChainedHash<T>::insert(const T& entry){
    return false;
    // assert(entry._key >= 0);
    // size_t hash(entry._key);


}          
template<typename T>
bool ChainedHash<T>::remove(int key){
    return false;
    // assert(key >= 0);
    // T result;
    // find(key, result);
    // return _data->erase(result);
}       
template<typename T>
bool ChainedHash<T>::find(int key, T& result) const{
    return false;
    // assert(key >= 0);
    // tree_node<T>* temp; 
    // return _data->search(key, temp);
}   
template<typename T>
bool ChainedHash<T>::is_present(int key) const{
    return false;
    // assert(key >= 0);
    // tree_node<T>* temp; 
    // return _data->search(key, temp);
}     
//========================Helper Functions ==================================
template<typename T>
int ChainedHash<T>::hash(int key) const{
    return (key%TABLE_SIZE);
} 
//==========================================================================   
#endif