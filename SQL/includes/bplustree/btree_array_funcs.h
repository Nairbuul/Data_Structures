#ifndef BTREE_ARRAY_FUNCS
#define BTREE_ARRAY_FUNCS

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <assert.h>
#include <vector>

#include "pair.h"
#include "multipair.h"

using namespace std;

//-------------------------------Btree array function declarations.-----------------------------------------

template <class T>
T maximal(const T& a, const T& b);                      //return the larger of the two items

template <class T>
void Swap(T& a, T& b);  //swap the two items

template <class T>
int index_of_maximal(T data[ ], int n);                 //return index of the largest item in data

template <class T>
void ordered_insert(T data[ ], int& n, T entry);        //insert entry into the sorted array
                                                        //data with length n

template <class T>
int first_ge(const T data[ ], int n, const T& entry);   //return the first element in data that is
                                                        //not less than entry

template <class T>
void attach_item(T data[ ], int& n, const T& entry);    //append entry to the right of data

template <class T>
void insert_item(T data[ ], int i, int& n, T entry);    //insert entry at index i in data

template <class T>
void detach_item(T data[ ], int& n, T& entry);          //remove the last element in data and place
                                                        //it in entry

template <class T>
void delete_item(T data[ ], int i, int& n, T& entry);   //delete item at index i and place it in entry

template <class T>
void merge(T data1[ ], int& n1, T data2[ ], int& n2);   //append data2 to the right of data1

template <class T>
void split(T data1[ ], int& n1, T data2[ ], int& n2);   //move n/2 elements from the right of data1
                                                        //and move to data2

template <class T>
void copy_array(T dest[], const T src[],
                int& dest_size, int src_size);              //copy src[] into dest[]

template <class T>
void print_array(const T data[], int n, int pos = -1);  //print array data

template <class T>
bool is_gt(const T data[], int n, const T& item);       //item > all data[i]

template <class T>
bool is_le(const T data[], int n, const T& item);       //item <= all data[i]
//-------------------------------Btree array function definitions.-------------------------------------------
//UNTESTED TEST LATER........
template <class T>
T maximal(const T& a, const T& b){
    if(a > b){
        return a;
    }
    return b;
}

template <class T>
void Swap(T& a, T& b){
    T c = a;
    a = b;
    b = c;
}

template <class T>
int index_of_maximal(T data[ ], int n){
    int largest = data[0];
    for(int i = 0; i < n; i++){
        if(data[i] > largest){
            largest = data[i];
        }
    }
    return largest;
}

template <class T>
void ordered_insert(T data[ ], int& n, T entry){
    int index = first_ge(data, n, entry);
    insert_item(data, index, n, entry);
}

template <class T>
int first_ge(const T data[ ], int n, const T& entry){
    int i;
    for(i = 0; i < n; i++){
        if(data[i] >= entry){
            return i;
        }
    }
    return i;
}

template <class T>
void attach_item(T data[ ], int& n, const T& entry){
    for(int index = n; index >= n; index--){
        data[index] = data[index-1];
    }
    data[n] = entry;
    n++;
}

template <class T>
void insert_item(T data[ ], int i, int& n, T entry){
    assert(i >= 0);
    if(n != 0){
        for(int index = n; index > i; index--){
        // for(int index = n; index >= i; index--){
            data[index] = data[index-1];
        }
    }
    data[i] = entry;
    n++;
}

template <class T>
void detach_item(T data[ ], int& n, T& entry){
    if(n > 0){
        entry = data[n-1];
        data[n-1] = T();
        n--;
    }
}

template <class T>
void delete_item(T data[ ], int i, int& n, T& entry){
    assert(i >= 0);
    entry = data[i];
    if(n != 0 ){
        for(int k = i; k < n; k++){
            data[k] = data[k+1];
        }
        n--;
    }
}

template <class T>
void merge(T data1[ ], int& n1, T data2[ ], int& n2){
    for(int i = 0; i < n2; i++){
        data1[i+n1] = data2[i];
    }
}

template <class T>
void split(T data1[ ], int& n1, T data2[ ], int& n2){
    int split = n1/2;
    if(n1%2 != 0){
        n2 = split;
        n1 = split+1;
        for(int i = 0; i < split; i++){
            data2[i] = data1[(split+1+i)];
        }
    }
    else{
        n2 = split;
        n1 = split;
        for(int i = 0; i <= split; i++){
            data2[i] = data1[(split+i)];
        }
    }
}

template <class T>
void copy_array(T dest[], const T src[],int& dest_size, int src_size){
    dest_size = src_size;
    for(int i = 0; i < src_size; i++){  
        dest[i] = src[i];
    }
}

template <class T>
void print_array(const T data[], int n, int pos){
    for(int i = pos; i < n; i++){
        cout << data[i] << " ";
    }
}

template <class T>
bool is_gt(const T data[], int n, const T& item){
    for(int i = 0; i < n; i ++){
        if(data[i] > item){
            return false;
        }
    }
    return true;
}

template <class T>
bool is_le(const T data[], int n, const T& item){
    for(int i = 0; i < n; i++){
        if(data[i] <= item){
            return false;
        }
    }
    return true;
}

#endif