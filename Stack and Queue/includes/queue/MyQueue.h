/*These are include gaurds. Their primary purpose is to prevent headers from being
declared multiple times.*/
#ifndef MYQUEUE_H   //ifndef checks if the file is not declared. 
#define MYQUEUE_H   //define will declare the file after 

#include <iostream>
#include <iomanip>

#include "../node/node.h"

template <typename T>
class Queue
{
public:
    class Iterator{
    public:
        friend class Queue;                               //give access to list to access _ptr
        Iterator(){_ptr = NULL;}                          //default ctor
        Iterator(node<T>* p){}                            //Point Iterator to where
                                                          //  p is pointing to
        T operator *(){}    //dereference operator
        bool is_null(){}            //true if _ptr is NULL
        friend bool operator !=(const Iterator& left,
                                const Iterator& right)  //true if left != right
        {}

        friend bool operator ==(const Iterator& left,
                                const Iterator& right)  //true if left == right
        {}


        Iterator& operator++(){                         //member operator:++it
                                                        // or ++it = new_value
            
        }

        friend Iterator operator++(Iterator& it,
                                   int unused){         //friend operator: it++
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
//REMINDER Queue is pop front push rear. Think grocery line.


#endif //end of scope of ifndef