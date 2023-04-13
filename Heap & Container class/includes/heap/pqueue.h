#ifndef PQUEUE_H
#define PQUEUE_H

#include "info.h"
#include "heap.h"

template <typename T>
class PQueue
{
public:
    PQueue(){}

    bool push(const T& value, int p);
    T pop();
    info<T> Pop_debug();
    bool is_empty() const {return _heap.is_empty();}
    int size() const {return _heap.size();}
    void print_tree() const;
    friend ostream& operator <<(ostream& outs, const PQueue<T>& print_me){
        outs<<print_me._heap;
        return outs;
    }
    bool verify() const;
private:
    Heap<info<T> > _heap;

};
// ========================DEFINITIONS================================
//
//
// ========================DEFINITIONS================================
template<typename T>
bool PQueue<T>::push(const T& value, int p){
    //Creating a timestamp to ensure the priority queue works in a FIFO method. 
    int time_stamp = _heap.size();

    _heap.insert(info<T> (value,p, time_stamp));
    return true;
}

template<typename T>
T PQueue<T>::pop(){
    return _heap.remove().item;
}

template<typename T>
info<T> PQueue<T>::Pop_debug(){
    return _heap.remove();
}

template<typename T>
void PQueue<T>::print_tree() const{
    cout << _heap << endl;
}

template<typename T>
bool PQueue<T>::verify() const{
    return _heap.verify();
}

#endif