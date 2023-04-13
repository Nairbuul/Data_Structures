/*These are include gaurds. Their primary purpose is to prevent headers from being
declared multiple times.*/
#ifndef MYQUEUE_H   //ifndef checks if the file is not declared. 
#define MYQUEUE_H   //define will declare the file after 

#include <iostream>
#include <iomanip>
#include <assert.h>

#include "../node/node.h"
#include "../../includes/linked_list_functions/linkedlistfunctionsTemplated.h"

template <typename T>
class Queue
{
public:
    class Iterator{
    public:
        friend class Queue;                              
        Iterator(){                             //Constructor.
            _ptr = NULL;
        }                         
        Iterator(node<T>* p){                   //Setter
            _ptr = p;
        }                            
        T operator *(){                         //returns element
            return _ptr->_item;
        }
        bool is_null(){                         //check to see if ptr is pointing at an address.
            return _ptr == nullptr;
        }            
        friend bool operator !=(const Iterator& left, const Iterator& right){ //Comparison
            return left._ptr != right._ptr;
        }   

        friend bool operator ==(const Iterator& left, const Iterator& right){ //Comparison
            return left._ptr == right._ptr;
        }

        Iterator& operator++(){  //move to next node.
            _ptr = _ptr->_next;
            return *this;
        }

        friend Iterator operator++(Iterator& it,int unused){  //Move to next node and returns the current address.
            Iterator hold = it;
            it._ptr = it._ptr->_next;
            return hold;
        }

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Queue();

    Queue(const Queue<T>& copyMe);
    ~Queue();
    Queue& operator=(const Queue<T>& RHS);

    bool empty();
    T front();
    T back();

    void push(T item);
    T pop();

    Iterator begin() const;                                     //Iterator to the head node
    Iterator end() const;                                       //Iterator to NULL
    void clear_queue();
    void print_pointers();
    int size() const { return _size; }
    template<typename TT>
    friend ostream& operator << (ostream& outs, const Queue<TT>& printMe);
private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};

/*=============================================================================

|                                  Definition                                 |

=============================================================================*/
//FIFO = first in first out. Grocery line.

//Constructor
template<typename T>
Queue<T>::Queue(){
    _front = nullptr;
    _rear = nullptr;
    _size = 0;
}
//Big Three
template<typename T>
Queue<T>::Queue(const Queue<T>& copyMe){
    _rear = _copy_list(_front, copyMe._front);
    _size = copyMe._size;
}

template<typename T>
Queue<T>::~Queue(){
    _clear_list(_front);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& RHS){
    //Returning the object if it's trying to copy itself.
    if(this == &RHS){
        return *this;
    }

    //Clearing the private variables.
    _clear_list(_front);
    _front = nullptr;
    _rear = nullptr;
    _size = 0;

    //Copying.
    _rear = _copy_list(_front, RHS._front); //Copying list with _front as the head and returning the address of the last node to _rear.
    _size = RHS._size;

    return *this;
}
//-----------------------------------------------
template<typename T>
bool Queue<T>::empty(){
    return _front == nullptr;
}
template<typename T>
T Queue<T>::front(){
    if(empty()){
        return T();
    }
    return _front->_item;
}
template<typename T>
T Queue<T>::back(){
    if(_rear == nullptr){ //Will really only be nullptr if Queue is empty.
        return T();
    }
    return _rear->_item;
}
template<typename T>
void Queue<T>::push(T item){ //FIFO
    if(_size == 0){
        _insert_head(_front, item);
        _rear = _front;
        _size++;
    }
    else{
        _insert_after(_front, _rear, item);
        _rear = _rear->_next;
        _size++;
    }
}
template<typename T>
T Queue<T>::pop(){  
    T carrier = _delete_node(_front, _front);  
    cout << carrier << endl;
    _size--;
    if(_size == 0){
        _rear = nullptr;
        _front = nullptr;
    }
    return carrier;
}
template<typename T>
typename Queue<T>::Iterator Queue<T>::begin() const{
    return Iterator(_front);
}   
template<typename T>                                 
typename Queue<T>::Iterator Queue<T>::end() const{
    return Iterator(nullptr);
} 
template<typename T>                                     
void Queue<T>::print_pointers(){
    _print_list(_front);
}
template<typename T>
ostream& operator << (ostream& outs, const Queue<T>& printMe){
    node<T>* walker = printMe._front;

    outs << "Head:->";

    while(walker != nullptr){
        outs << *walker;
        walker = walker->_next;
    }
    
    outs << "|||";
    
    return outs;
}

template<typename T>
void Queue<T>::clear_queue(){
    _clear_list(_front);
}
#endif //end of scope of ifndef