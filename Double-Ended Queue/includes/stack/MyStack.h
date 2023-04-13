#ifndef MYSTACK_H 
#define MYSTACK_H

#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

template <typename T>
class Stack{
public:
    class Iterator{
    public:
        friend class Stack;                 //give access to list to access _ptr
        Iterator(){
            _ptr = NULL;
        }           
        Iterator(node<T>* p){
            _ptr = p;
        }      
        T operator *(){
            return _ptr->_item;
        }    
        bool is_null(){ 
            return _ptr == nullptr;
        }         
        friend bool operator !=(const Iterator& left, const Iterator& right){ 
            return left._ptr != right._ptr; 
        }
        friend bool operator ==(const Iterator& left, const Iterator& right)  {
            return left._ptr != right._ptr; 
        }
        Iterator& operator++(){
            _ptr = _ptr->_next;
            return *this;
        }
        friend Iterator operator++(Iterator& it,int unused){    
            Iterator hold = it;
            it._ptr = it._ptr->_next;
            return hold;   
        }

    private:
        node<T>* _ptr;    //pointer being encapsulated
    };

    Stack();
    Stack(const Stack<T>& copyMe);
    ~Stack();
    Stack<T>& operator=(const Stack<T>& RHS);
    T top();
    bool empty();
    void push(T item);
    T pop();
    template<typename ITEM_TYPE>
    friend ostream& operator<<(ostream& outs, const Stack<ITEM_TYPE>& printMe);
    Iterator begin() const;                   //Iterator to the head node
    Iterator end() const;                     //Iterator to NULL
    int size() const { return _size; }

private:
    node<T>* _top;
    int _size;
};

/*=============================================================================

|                                  Definition                                 |

=============================================================================*/
//LIFO last in first out. (Pringles can.)
template<typename T>
Stack<T>::Stack(){
    _top = nullptr;
    _size = 0;
}
//Big Three---------------------------
template<typename T>
Stack<T>::Stack(const Stack<T>& copyMe){ //Copy Ctor.
    _top = _copy_list(copyMe._top);
    _size = copyMe._size;
}   
template<typename T>
Stack<T>::~Stack(){
    _clear_list(_top);
}
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& RHS){
    if(*this == RHS){
        return *this;
    }

    _top = nullptr;
    _size = 0;

    _top = _copy_list(RHS._top);
    _size = RHS._size;

    return *this;
}
//-----------------------------------------
template<typename T>
T Stack<T>::top(){
    if(empty()){
        return T();
    }
    return _top->_item;
}

template<typename T>
bool Stack<T>::empty(){
    return _top == nullptr;
}

template<typename T>
void Stack<T>::push(T item){
    _size++;
    _insert_head(_top, item);
}

template<typename T>
T Stack<T>::pop(){
    _size--;
    return _delete_node(_top, _top);
}

template<typename T>
ostream& operator<<(ostream& outs, const Stack<T>& printMe){
    
    node<T>* walker = printMe._top;
    outs << "Head->";
    while(walker != nullptr){
        outs << *walker;
        walker = walker->_next;
    }
    outs << "|||";
    return outs;
}

template<typename T>
typename Stack<T>::Iterator Stack<T>::begin() const{
    return  Iterator(_top);
}      

template<typename T>           
typename Stack<T>::Iterator Stack<T>::end() const{
    return Iterator(nullptr);
}                
#endif