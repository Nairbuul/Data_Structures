#ifndef MYSTACK_H 
#define MYSTACK_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Stack{
public:
    class Iterator{
    public:
        friend class Stack;                 //give access to list to access _ptr
        Iterator(){_ptr = NULL;}            //default ctor
        Iterator(node<T>* p){}      //Point Iterator to where
                                            //  p is pointing to
        T operator *(){}    //dereference operator
        bool is_null(){return _ptr == NULL;}            //true if _ptr is NULL
        friend bool operator !=(const Iterator& left,
                                const Iterator& right)  //true if left != right
        {return left._ptr != right._ptr;}

        friend bool operator ==(const Iterator& left,
                                const Iterator& right)  //true if left == right
        {}


        Iterator& operator++(){                        //member operator:++it
                                                       // or ++it = new_value
        }

        friend Iterator operator++(Iterator& it,
                                   int unused){        //friend operator: it++
            assert(it._ptr!=NULL);
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
//REMINDER INSERT AND DELETE AT THE TOP. THINK PRINGLES CAN

template<typename T>
Stack<T>::Stack(){
    _top = nullptr;
    _size = 0;
}

template<typename T>
Stack<T>::Stack(const Stack<T>& copyMe){
    _top = _copy_list(copyMe._top);
    _size = copyMe._size;
}

template<typename T> 
Stack<T>::~Stack(){ //Double checked and tested working clear list.
    _clear_list(_top);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& RHS){
    if(*this == RHS){
        return *this;
    }

    //Make sure private variables are empty.
    _clear_list(_top);
    _top = nullptr;
    _size = 0;

    //Now we can copy.
    _top = _copy_list(RHS._top);  //Using the copy function that returns head instead of rear.
    _size = RHS._size;            //Also updating private variable _size to RHS size.

    return *this;
}

template<typename T>
T Stack<T>::top(){
    return _top;                //Returning the address top
}

template<typename T>
bool Stack<T>::empty(){
    return _top == nullptr;
}

template<typename T>
void Stack<T>::push(T item){
    _size++;
    _insert_head(_top, item);   //Pringles can. (First in -> Last out)
}

template<typename T>
T Stack<T>::pop(){
    _size--;
    return _delete_node(_top, _top);   //Pringles can.    
}

template<typename T>
ostream& operator<<(ostream& outs, const Stack<T>& printMe){

    cout << "Head->"; 
    for(int i = 0; i < printMe._size; i++){
        cout << " <-" <<  *printMe._top;
    }
    cout << "|||";
    return outs;
}

template<typename T>
typename Stack<T>::Iterator Stack<T>::begin() const{
    node<T>* test = nullptr; 
    cout << _top << " " << test;
    return nullptr; 
}

template<typename T>
typename Stack<T>::Iterator Stack<T>::end() const{
    return Iterator(nullptr);
}
#endif