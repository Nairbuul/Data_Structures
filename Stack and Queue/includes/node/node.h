#ifndef NODE_H //headers make sure to include #endif at the end of the file
#define NODE_H

#include <iostream>
#include <iomanip>
#include <assert.h>
#include <stdlib.h>

using namespace std;

template <class T>
struct node{
    T _item;
    node<T>* _next;
    node<T>* _prev;
    node(const T& item = T(), node<T>* next = NULL, node<T>* prev = NULL):
                                                                       _item(item), 
                                                                       _next(next),
                                                                       _prev(prev){}
    friend ostream& operator << (ostream& outs, const node<T>& print_me){
        outs<<"["<<print_me._item<<"]->";
        return outs;
    }
};

//Linked List General Functions:
template <typename T>
void _print_list(node<T>* head);

//recursive fun! :)
template <typename T>
void _print_list_backwards(node<T> *head);

//return ptr to key or NULL
template <typename T>
node<T>* _search_list(node<T>* head,
                            T key);


template <typename T>
node<T>* _insert_head(node<T> *&head,
                            T insert_this);

//insert after ptr: insert head if marker null
template <typename T>
node<T>* _insert_after(node<T>*& head,
                                node<T> *after_this,
                                T insert_this);

//insert before ptr: insert head if marker null
template <typename T>
node<T>* _insert_before(node<T>*& head,
                                node<T>* before_this,
                                T insert_this);

//ptr to previous node
template <typename T>
node<T>* _previous_node(node<T>* prev_to_this);

//delete, return item
template <typename T>
T _delete_node(node<T>*& head, node<T>* delete_this);

//duplicate the list...
template <typename T>
node<T>* _copy_list(node<T>* head);

//duplicate the list, return pointer to last node in dest... 
//     use this function in your queue big three 
template <typename T>
node<T> *_copy_list(node<T> *&dest, node<T> *src);



//delete all the nodes
template <typename T>
void _clear_list(node<T>*& head);

//_item at this position
template <typename T>
T& _at(node<T>* head, int pos);

/*========================================================================================

|                                Function Definitions                                    |

========================================================================================*/
//TIP: use switch if there are more then 5 cases.

template <typename T>
void _print_list(node<T>* head){

    bool debug = false;

    if(debug == true){
        cout << "_print_list start of function." << endl;
    }

    if(head == nullptr){                                                //Message to alert user of empty list.
        cout << "Error: Cannot print an empty list. \nExiting..." << endl; 
        exit(0);
    }

    cout << "Head->"; 

    node<T>* walker = head; 

    while(walker != nullptr){
        if(walker->_prev != nullptr){
            cout << " <-" << *walker;
        }
        else{
            cout << *walker;
        }
        walker = walker->_next;
    }
    
    cout << " |||" << endl;

    if(debug == true){
        cout << "_print_list end of function." << endl;
    }
}

template <typename T>
void _print_list_backwards(node<T> *head){

    // WARNING FUNCTION WILL ABSOLUTELY DIE IF THE LEFT ADDRESSES ARE NOT LINKED.

    bool debug = false;

    if(debug == true){
        cout << "_print_list_backwards start of function" << endl;
    }
    
    if(head->_next == nullptr && head->_prev == nullptr){           //CASE: single node.
        cout << "||| <-[" <<head->_item  << "] <-Head";
    }

    if(head->_next == nullptr){                                     //Head->_next only hits nullptr
        cout << "|||";                                              //once.
    }

    if(head->_next != nullptr){                                     //Idea is that we update the addresses by one to the
        node<T>*walker = head->_next;                               //right until the if condition fails and it'll begin
        _print_list_backwards(walker);                              // at the right.
        cout <<  " <-" << *walker; 
        if(head->_prev == nullptr){                                 //Since this conditon isn't met until
            cout << " <-[" << walker->_prev->_item << "] <-Head";   //it already cycles we know the head will
            cout << endl;                                           //be the original head and thefore we can 
        }                                                           //print the first node.
    }                                                               

    if(debug == true){
        cout << "_print_list_backwards end of function." << endl;
    }
}

template <typename T>
node<T>* _search_list(node<T>* head,T key){
    
    bool debug = false;

    if(debug == true){                                                  
        cout << "_search_list start of function." << endl;      
    }

    if(head == nullptr){
        cout << "Cannot search for element in an empty list." << endl;
        return nullptr; 
    }

    node<T>* Seeker = head;

    while(Seeker != nullptr){                                               //If item is found at seeker's address we'll 
        if(Seeker->_item == key){                                           //return the address.
            return Seeker;
        }
        else{
            Seeker = Seeker->_next;
        }
    }

    if(debug == true){                                                  
        cout << "_search_list end of function." << endl;      
    }

    return nullptr;                                                       //Return nullptr if not found.
}

template <typename T>
node<T>* _insert_head(node<T> *&head, T insert_this){

    bool debug = false;

    if(debug == true){                                                  
        cout << "_insert_head start of function." << endl;      
    }

    if(head == nullptr){
        head = new node<T>(insert_this);
    }
    else{
        node<T>* addon = head;
        head = new node<T>(insert_this);
        head->_next = addon;
        addon->_prev = head;
    }

    if(debug == true){
        cout << "_insert_head end of function." << endl;
    }

    return head;                                                           //Return the new head of the list.
}

template <typename T>//redo
node<T>* _insert_after(node<T>*& head, node<T> *after_this, T insert_this){

    bool debug = false;

    if(debug == true){
        cout << "_insert_after start of function." << endl;
    }

    if(head == nullptr || after_this == nullptr){
        _insert_head(head, insert_this);
    }
   
    node<T>* insert = new node<T>(insert_this);
    insert->_prev = after_this;
    insert->_prev = after_this;
    insert->_next = after_this->_next;
    after_this->_next = insert; 

    if(debug == true){
        cout << "_insert_after end of function." << endl;
    }

    return insert;                                                //Return the start of the list.
}

template <typename T>//redo
node<T>* _insert_before(node<T>*& head, node<T>* before_this, T insert_this){
    
    bool debug = false;
    if(debug == true){
        cout << "_insert_before start of function." << endl;
    }

    if(before_this == nullptr || before_this == head){
        return head = _insert_head(head, insert_this);
    }

    node<T>* insert = new node<T>(insert_this);
    node<T>* walker = before_this->_prev;
    
    walker->_next = insert;
    insert->_prev = walker;
    insert->_next = before_this;
    before_this->_prev = insert;

    if(debug == true){
        cout << "_insert_before end of function." << endl;
    }

    return insert;
}

//ptr to previous node
template <typename T>
node<T>* _previous_node(node<T>* prev_to_this){

    /*Since we're  not given the head of the list we can only rely 
    on the given node to have an address in _prev. */

    if(prev_to_this->_prev != nullptr){
        return prev_to_this->_prev;
    }

    return nullptr;
}   

//delete, return item
template <typename T>
T _delete_node(node<T>*& head, node<T>* delete_this){

    if(delete_this == head){
        //Careful when head is given and head->_prev is != nullptr.
        head = head->_next;
    }

    T item = delete_this->_item;
    node<T>* walker = head;

    if(delete_this->_prev != nullptr){
        walker = _previous_node(delete_this);
        walker->_next = delete_this->_next;
    }
    else{
        while(walker != nullptr){
            if(walker->_next == delete_this){
                walker->_next = delete_this->_next;
                break;
            }
            walker = walker->_next;
        }
    }

    delete delete_this;

    return item;
}

//duplicate the list...
template <typename T>
node<T>* _copy_list(node<T>* head){

    if(head == nullptr){
        return  nullptr;
    }

    node<T>* walker = head;
    node<T>* copy = new node<T>(walker->_item);
    node<T>* copy_index = copy;
    walker = walker->_next;

    while(walker != nullptr){

        copy = _insert_after(copy, copy_index, walker->_item);
        walker = walker->_next;
        copy_index = copy_index->_next;
    }

    return copy;
}

//duplicate the list, return pointer to last node in dest... 
//     use this function in your queue big three 
template <typename T>
node<T> *_copy_list(node<T> *&dest, node<T> *src){

    if(src == nullptr){
        return nullptr;
    }

    node<T>* walker = src;
    dest = new node<T>(walker->_item);
    node<T>* dest_index = dest;
    walker = walker->_next;

    while(walker != nullptr){
        dest = _insert_after(dest, dest_index, walker->_item);
        walker = walker->_next;
        dest_index = dest_index->_next;
    }

    return dest_index;
}

//delete all the nodes
template <typename T>
void _clear_list(node<T>*& head){

    while(head != nullptr){
        _delete_node(head, head);
    }
}

//_item at this position
template <typename T>
T& _at(node<T>* head, int pos){

    node<T>*walker = head;
    for(int i = 0; i < pos; i++){
        walker = walker->_next;
    }

    return  walker->_item;
}

#endif