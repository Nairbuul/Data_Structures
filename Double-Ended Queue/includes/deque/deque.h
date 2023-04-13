#ifndef DEQUE_H
#define DEQUE_H

#include "../queue/myQueue.h"

template<typename T>
class Deque
{
public:
    class Iterator{
        public:
            Iterator(){
                _ptr = NULL;
            }
            Iterator(node<T>* p){
                _ptr = p;
            }
            T operator*(){
                return _ptr->_item;
            }
            bool is_null(){
                return _ptr == nullptr;
            }
            friend bool operator !=(const Iterator& left,const Iterator& right){
                return left._ptr != right._ptr;
            }
            friend bool operator ==(const Iterator& left, const Iterator& right){
                return left._ptr == right._ptr;
            
            }
            Iterator& operator--(){ //Can now iterate right to left. 
                _ptr = _ptr->_prev;
                return *this;
            }
            Iterator& operator++(){
                _ptr = _ptr->_next;
                return *this;
            }
            friend Iterator operator++(Iterator& it, int unused){
                Iterator hold = it;
                it._ptr = it._ptr->_next;
                return hold;
            }
            friend Iterator operator--(Iterator& it, int unused){
                Iterator hold = it;
                it._ptr = it._ptr->_prev;
                return hold;
            }
        private:
            node<T>* _ptr;
    };
    //CTOR
    Deque();
    //BIG THREE
    Deque(const Deque<T>& copyMe);
    ~Deque();
    Deque& operator=(const Deque<T>& RHS);
    //Functions 

    //Push functions. (Front & Rear.)
    void push_back(T item);
    void push_front(T item);

    //Pop functions. (Front & rear.) 
    T pop_back();
    T pop_front(); 

    //Return elements (Front & rear).
    T front();
    T rear(); 

    //Lets private variable be readable. 
    int size() const {return _size;}

    //Empty Queue check.
    bool empty();

    //Initializes _ptr in iterator.
    Iterator begin() const;
    Iterator rear() const;
    Iterator end() const;
    
    //OSTRAAAAM
    template<typename woo>
    friend ostream& operator << (ostream& outs, const Deque<woo>& printMe);
private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};
//========================================================================
//CTOR
template<typename T>
Deque<T>::Deque(){
    _front = nullptr;
    _rear = nullptr;
    _size = 0;
}
//Big three
template<typename T>
Deque<T>::Deque(const Deque<T>& copyMe){
    _rear = _copy_list(_front, copyMe._front);
    _size = copyMe._size
;}

template<typename T>
Deque<T>::~Deque(){
    _clear_list(_front);
}

template<typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& RHS){
    if(*this == RHS){
        return *this;
    }

    _clear_list(_front);
    _front = nullptr;
    _rear = nullptr;
    _size = 0;

    _rear = _copy_list(_front, RHS._front);
    _size = RHS._size;

    return *this;
}
//Push functions
template<typename T>
void Deque<T>::push_back(T item){
    if(_size == 0){
        _insert_head(_front, item);
        _rear = _front;
        _size++; 
    }
    else{
        _insert_after(_front,_rear, item);
        _rear = _rear->_next;
        _size++;
    }
}

template<typename T>
void Deque<T>::push_front(T item){
    if(_size == 0){
        _insert_head(_front, item);
        _rear = _front;
        _size++;
    }
    else{
        _size++;
        _insert_head(_front,item);
    }
}

//Pop Functions
template<typename T>
T Deque<T>::pop_back(){
    _size--;
    node<T>*hold = _rear->_prev;
    T element_carrier = _delete_node(_front, _rear);
    _rear = hold;
    if(_size == 0){
        _rear = nullptr;
        _front = nullptr;
    }
    return element_carrier;
}

template<typename T>
T Deque<T>::pop_front(){ //Comeback to this
    _size--;
    
    if(_size == 0){
        _rear = nullptr;
        _front = nullptr;
    }
    return _delete_node(_front, _front);
}   

//Empty check
template<typename T>
bool Deque<T>::empty(){
    if(_front == nullptr && _rear == nullptr){ //Incase one of the pointers go haywire.
        return true;
    }
    else{
        return false;
    }
}   
//Elements
template<typename T>
T Deque<T>::front(){
    return _front->_item;
}
template<typename T>
T Deque<T>::rear(){
    return _rear->_item;
}   

//ITERATION
template<typename T>
typename Deque<T>::Iterator Deque<T>::begin() const{ 
    return Iterator(_front);
}

template<typename T>
typename Deque<T>::Iterator Deque<T>::rear() const{
    return Iterator(_rear);
}

template<typename T>
typename Deque<T>::Iterator Deque<T>::end() const{
    return Iterator(nullptr);
}

//OSTRAM
template<typename woo>
ostream& operator << (ostream& outs, const Deque<woo>& printMe){
    node<woo>* walker = printMe._front;

    outs << "Head:->";

    while(walker != nullptr){
        outs << *walker;
        walker = walker->_next;
    }
    
    outs << "|||";
    
    return outs;
}
#endif