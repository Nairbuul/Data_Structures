#ifndef HEAP_H
#define HEAP_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <assert.h>
#include <string>

using namespace std;

template <typename T>
class Heap
{
public:
    Heap():_how_many(0){}
    void insert(const T& insert_me);    //insert into the heap
    T remove();                         //remove and return top value 
    T top();                            //return the value at the top of heap
    bool is_empty() const;
    int size() const;
    int capacity() const;
    friend ostream& operator << (ostream& outs, const Heap<T>& print_me){
        print_me.print_tree(outs);
        return outs;
    }
    bool verify() const;                //true if tree is verified to be a heap
    T *heap_array();                    //returns a copy of underlying array: 

private:
    static const int CAPACITY = 1000;
    T _heap[CAPACITY]; //static array
    int _how_many = 0; //num used

    void print_tree(ostream& outs = cout) const;
    void print_tree(int root, int level = 0, ostream& outs = cout) const;

    bool verify(int root) const;

    bool is_root(int i) const {return i==0;}
    bool is_leaf(int i) const;
    int parent_index(int i) const;
    int left_child_index(int i)const {return 2*i + 1;}
    int right_child_index(int i) const {return 2*i + 2;}
    int big_child_index(int i) const;
    void swap_with_parent(int i);
};
// ========================DEFINITIONS================================
//
//
// ========================DEFINITIONS================================
template<typename T>
void Heap<T>::insert(const T& insert_me){
    _heap[_how_many] = insert_me;
    _how_many++;

    //Sorting the tree as we insert.
    int child = _how_many-1;
    while(_heap[child] > _heap[parent_index(child)]){
        if(child == 0){
            break;
        }
        swap_with_parent(child);
        child = parent_index(child);
    }
}

template<typename T>
T Heap<T>::remove(){
    //Replace head of tree with right most element.

    //Ensuring the tree isn't empty.
    assert(!is_empty());

    //Removing top of tree and replacing withh right most value.
    T return_value = _heap[0];
    _heap[0] = _heap[_how_many-1];
    _how_many--;

    //Sort before removing.
    int sort = 0;
    while(_heap[sort] < _heap[big_child_index(sort)]){
        sort = big_child_index(sort);
        swap_with_parent(sort);
    }

    return return_value;
}   

template<typename T>
T Heap<T>::top(){
    if(is_empty()){
        return T();
    }
    return _heap[0];
}

template<typename T>
bool Heap<T>::is_empty() const{
    return _how_many == 0;
}

template<typename T>
int Heap<T>::size() const{
    return _how_many;
}

template<typename T>
int Heap<T>::capacity() const{
    if(is_empty()){
        return 0;
    }
    return _how_many+1;
}  

template<typename T>
bool Heap<T>::verify() const{
    //capsule
    return verify(0);
}   

template<typename T>
T *Heap<T>::heap_array(){
    //Creating a dynamic array.
    T* array = new int[capacity()];
    for(int i = 0; i < size(); i++){
        array[i] = _heap[i];
    }
    return array;
} 

template<typename T>
void Heap<T>::print_tree(ostream& outs) const{
    //capsule
    print_tree(0,0,outs);
}

template<typename T>
void Heap<T>::print_tree(int root, int level, ostream& outs) const{
    //recursive
    if(root < _how_many){
        print_tree(right_child_index(root),level+1, outs);
        outs << setw(4+level*4) << _heap[root] << endl;
        print_tree(left_child_index(root), level+1, outs);
    }
}

template<typename T>
bool Heap<T>::verify(int root) const{
    //recursive
    bool heap;
    if(root < _how_many){
        heap = verify(right_child_index(root));
        heap = verify(left_child_index(root));
        if(_heap[root] > _heap[parent_index(root)]){
            return false;
        }
        else{
            return true;
        }
    }
    return heap; //For compiler.
}

template<typename T>
bool Heap<T>::is_leaf(int i) const{
    if(left_child_index(i) > _how_many){
        return true;
    }
    return false; //For compiler
}

template<typename T>
int Heap<T>::parent_index(int i) const{
    if(i%2 == 0 && i > 0){
        return i/2-1;
    }
    return (i/2);
}

template<typename T>
int Heap<T>::big_child_index(int i) const{
    //Check to see if child exists.
    if(right_child_index(i) <= _how_many){
        if(_heap[left_child_index(i)] < _heap[right_child_index(i)]){
            return right_child_index(i);
        }
        if(_heap[left_child_index(i)] >= _heap[right_child_index(i)]){
            return left_child_index(i);
        }
    }
    else if(left_child_index(i) <= _how_many && right_child_index(i) > _how_many){
        return left_child_index(i);
    }
    else{
        return i;
    }
    return i; //For compiler
}

template<typename T>
void Heap<T>::swap_with_parent(int i){
    assert(!is_empty());
    T parent = _heap[parent_index(i)];
    T child = _heap[i];
    _heap[parent_index(i)] = child;
    _heap[i] = parent;
}

#endif