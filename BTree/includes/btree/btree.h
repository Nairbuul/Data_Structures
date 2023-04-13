#ifndef BTREE_H
#define BTREE_H

#include "../btree_array_functions/btree_array_functions.h"

#include <assert.h>

template <class T>
class BTree
{
public:
    BTree(bool dups = false);
    BTree(T *a, int size, bool dups = false);
    //big three:
    BTree(const BTree<T>& other);
    ~BTree();
    BTree<T>& operator=(const BTree<T>& RHS);

    void insert(const T& entry);                //insert entry into the tree
    void remove(const T& entry);                //remove entry from the tree

    void clear_tree();                          //clear this object
                                                //  (delete all nodes etc.)
    void copy_tree(const BTree<T>& other);      //copy other into this object

    bool contains(const T& entry);              //true if entry can be found in
                                                //                  the array
    T& get(const T& entry);                     //return a reference to entry
                                                //                  in the tree
    T* find(const T& entry);                    //return a pointer to this key.
                                                //          NULL if not there.

    int size() const;                           //count the number of elements
                                                //              in the tree
    bool empty() const;                         //true if the tree is empty

    bool is_valid();
                                                //print a readable version of
                                                //                  the tree
    void print_tree(int level = 0, ostream &outs=cout) const;
    friend ostream& operator<<(ostream& outs, const BTree<T>& print_me){
        print_me.print_tree(0, outs);
        return outs;
    }

    string in_order();                          // traverse the tree in an
                                                // inorder fashion, return a 
                                                // string of all the data items
                                                // with vertical delimiters

// private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    bool dups_ok;                               //true if duplicate keys may be
                                                //      inserted
    int data_count;                             //number of data elements
    T data[MAXIMUM + 1];                        //holds the keys
    int child_count;                            //number of children
    BTree* subset[MAXIMUM + 2];                 //subtrees

    bool is_leaf() const {return child_count==0;} //true if this is a leaf node

    //insert element functions
    void loose_insert(const T& entry);          //allows MAXIMUM+1 data
                                                //      elements in the root
    void fix_excess(int i);                     //fix excess of data elements
                                                //                  in child i

    //remove element functions:
    void loose_remove(const T& entry);          //allows MINIMUM-1 data
                                                //      elements in the root
    void fix_shortage(int i);                   //fix shortage of data elements
                                                //                  in child i

    void remove_biggest(T& entry);              //remove the biggest child of
                                                //          this tree->entry
    void rotate_left(int i);                    //transfer one element LEFT
                                                //              from child i
    void rotate_right(int i);                   //transfer one element RIGHT
                                                //              from child i
    void merge_with_next_subset(int i);         //merge subset i with subset
                                                //                      i+1

};
//-------------------------------------- BTree definitions -------------------------------------------
template<typename T>
BTree<T>::BTree(bool dups){
    dups_ok = dups;
    data_count = 0;
    child_count = 0;
}
template<typename T>
BTree<T>::BTree(T *a, int size, bool dups){
    dups_ok = dups;

    for(int i = 0; i < size; i++){
        insert(a[i]);
    }
}
//big three:-------------------------------------
template<typename T>
BTree<T>::BTree(const BTree<T>& other){
    copy_tree(other);
}
template<typename T>
BTree<T>::~BTree(){
    clear_tree();
}
template<typename T>
BTree<T>& BTree<T>::operator=(const BTree<T>& RHS){
    if(this == &RHS){
        return *this;
    }
    
    clear_tree();
    copy_tree(RHS);

    return *this;
}   
//------------------------------------------------
template<typename T>
void BTree<T>::insert(const T& entry){
    loose_insert(entry);
    if(data_count == MAXIMUM+1){
        BTree<T>* growth = new BTree();
        copy_array(growth->data, data, growth->data_count, data_count);
        copy_array(growth->subset, subset, growth->child_count, child_count);
        data_count = 0;
        child_count = 0;
        subset[child_count] = growth;
        fix_excess(child_count);
    }
}
template<typename T>
void BTree<T>::remove(const T& entry){
    loose_remove(entry);
    //condition if removing straight from the root.
    if(data_count == MINIMUM-1 && child_count != 0){
        BTree<T>* shrink = subset[MINIMUM-1];
        copy_array(data, shrink->data, data_count, shrink->data_count);
        copy_array(subset, shrink->subset, child_count, shrink->child_count);
        shrink->child_count = 0;
        shrink->data_count = 0;
        delete shrink; 
    }
}
template<typename T>
void BTree<T>::clear_tree(){
    if(data_count == 0 && child_count == 0)
        return;
    for(int i = 0; i < data_count; i++){
        data[i] = 0;
    }
    if(!is_leaf()){
        for(int i = 0; i < child_count; i++){
            subset[i]->clear_tree();
        }
    }
    data_count = 0;
    child_count = 0;
}
template<typename T>
void BTree<T>::copy_tree(const BTree<T>& other){
    copy_array(data, other.data, data_count, other.data_count);
    child_count = other.child_count;
    for(int i = 0; i < child_count; i++){
        subset[i] = new BTree();
        subset[i]->copy_tree(*other.subset[i]);
    }
}
template<typename T>
bool BTree<T>::contains(const T& entry){
    if(find(entry)){
        return true;
    }
    return false;
}
template<typename T>
T& BTree<T>::get(const T& entry){
    if(!contains(entry)){
        insert(entry);
    }   
    return *find(entry);
}
template<typename T>
T* BTree<T>::find(const T& entry){
    int i = first_ge(data, data_count, entry);
    if(i < data_count && data[i] == entry){
        T* here = &data[i];
        return here;
    }
    if(!is_leaf()){
        return subset[i]->find(entry);
    }
    return nullptr;
}
template<typename T>
int BTree<T>::size() const{
    return data_count;
}
template<typename T>
bool BTree<T>::empty() const{ 
    if(data_count != 0 && child_count != 0){
        return false;
    }
    return true;
}
template<typename T>
bool BTree<T>::is_valid(){
    //B-tree rule 1.(root can have 0 elements but every other nodes must have minimum elements)
    //B-tree rule 2.(The maximum number of entries in a node is twice the value of minimum).
    //B-tree rule 3.(all elements are arranged in ascending order).
    //B-tree rule 4.(The number of subtrees below a nonleaf node is always 1+entries in node.)
    //B-tree rule 5.(For any non leaf i is greater then all elements in subtree[i]).
    return true;
}
template<typename T>
void BTree<T>::print_tree(int level, ostream &outs) const{
    if(!is_leaf()){
        int index = data_count - 1;
        for(int i = child_count-1; i >= 0; i--){
            subset[i]->print_tree(level+1, outs);
            if(i == data_count){ //Top Bracket
                outs << setw(4+level*3) << "-" << endl;
            }
            if(index >= 0){
                outs << setw(4+level*3) << data[index] << endl;
                index--;
            }
            if(i == 1){  //Bottom Bracket
                outs << setw(4+level*3) << "-"  << endl;
            }
        }
    }
    else{
            cout << setw(4+level*3) << "-" << endl;
            for(int i = data_count -1; i >= 0; i--){
                outs << setw(4+level*3) << data[i] << endl;
            }
            outs << setw(4+level*3) << "-" << endl;
    }
}
template<typename T>
string BTree<T>::in_order(){
    string btree;
    if(!is_leaf()){
        for(int i = 0; i < child_count; i++){
            btree += subset[i]->in_order();
            if(i < data_count){
                btree += to_string(data[i]) + "|";
            }
        }
    }
    else{
        for(int i = 0; i < data_count; i++){
            btree += to_string(data[i]) + "|";
        }
    }
    return btree;
}
//insert element functions
template<typename T>
void BTree<T>::loose_insert(const T& entry){
    //check
    if(!is_valid()){
        return;
    }
    if(contains(entry)){
        return;
    }
    //work
    int i = first_ge(data,data_count,entry);
    if(child_count != 0){
        subset[i]->loose_insert(entry);
        if(subset[i]->data_count == MAXIMUM+1){
            fix_excess(i);
        }
    }
    else{
        insert_item(data, i, data_count, entry);
    }
}
template<typename T>
void BTree<T>::fix_excess(int i){
    BTree<T>* temp = new BTree();
    split(subset[i]->data, subset[i]->data_count, temp->data, temp->data_count);
    split(subset[i]->subset, subset[i]->child_count, temp->subset, temp->child_count);
    T capsule;
    delete_item(subset[i]->data, subset[i]->data_count-1, subset[i]->data_count, capsule);
    insert_item(subset, i+1, child_count, temp);
    ordered_insert(data, data_count, capsule);
    child_count = data_count+1;
}   
//remove element functions:
template<typename T>
void BTree<T>::loose_remove(const T& entry){
    //check
    if(!is_valid()){ 
        return;
    }
    if(!contains(entry)){ 
        return;
    }
    //work
    int i = first_ge(data, data_count, entry);
    if(data[i] == entry){
        T container;
        delete_item(data, i, data_count, container);
        if(data_count < child_count-1 && !is_leaf()){
            delete_item(subset[i]->data, 0, subset[i]->data_count, container);
            ordered_insert(data, data_count, container);
            fix_shortage(i);
        }
        return;
    }
    if(child_count != 0){
        subset[i]->loose_remove(entry);
        if(subset[i]->data_count < MINIMUM){
            fix_shortage(i);
        }
    }
}
template<typename T>
void BTree<T>::fix_shortage(int i){
    //rotate_left
    if(i+1 < child_count && subset[i+1]->data_count > MINIMUM){
        cout << "calling rotate_left at subset: " << i << endl;
        rotate_left(i);
        return;
    }
    // rotate_right
    if(i-1 >= 0 && subset[i-1]->data_count > MINIMUM){
        cout << "calling rotate_right at subset: " << i << endl;
        rotate_right(i);
        return;
    }
    // merge
    if(data_count <= child_count-1){
        cout << "calling merge at subset: " << i << endl;
        merge_with_next_subset(i);
        return;
    }
}
template<typename T>
void BTree<T>::remove_biggest(T& entry){
    //wrong...
    int i = first_ge(data, data_count, entry);
    if(!is_leaf()){
        subset[i]->remove_biggest(entry);
        if(subset[i]->data_count == 0){
            fix_shortage(i);
        }
    }   
    if(is_leaf()){
        detach_item(data, data_count, entry);
    }
}
template<typename T>
void BTree<T>::rotate_left(int i){
    //transfer one element left from child i
    //borrow from right

    // assert(subset[i+1]->data_count >= MAXIMUM);

    //moving datas...
    insert_item(subset[i]->data, MINIMUM-1, subset[i]->data_count, data[data_count-1]);
    delete_item(subset[i+1]->data, MINIMUM-1, subset[i+1]->data_count, data[data_count-1]);

    //moving subsets...
    if(!subset[i]->is_leaf()){
        delete_item(subset[i+1]->subset, MINIMUM-1, subset[i+1]->child_count, subset[i]->subset[MINIMUM]);
        subset[i]->child_count++;
    }
}
template<typename T>
void BTree<T>::rotate_right(int i){
    //transfer one element right from child i
    //borrow from left...

    // assert(subset[i-1]->data_count >= MAXIMUM);

    //moving datas..
    T Capsule = data[i-1];
    ordered_insert(subset[i]->data, subset[i]->data_count, Capsule);
    detach_item(subset[i-1]->data, subset[i-1]->data_count, data[i-1]);

    //moving subsets...
    if(!subset[i]->is_leaf()){
        BTree* capsule;
        delete_item(subset[i-1]->subset, child_count-1, subset[i-1]->child_count, capsule);
        insert_item(subset[i]->subset, MINIMUM-1, subset[i]->child_count, capsule);
    }
}   
template<typename T>
void BTree<T>::merge_with_next_subset(int i){

    //merge right...
    if(subset[i]->data_count == MINIMUM-1 && i != child_count-1){
        T capsule;
        BTree<T>* temp;

        cout << "merge right: " << endl;
        //moving datas..
        insert_item(subset[i+1]->data, MINIMUM-1, subset[i+1]->data_count, data[i]);
        delete_item(data, i, data_count, capsule);

        // moving subsets... [move all to the right(non-empty btree) assign empty btree as the ->rihgt tree.
        if(!subset[i]->is_leaf()){
            insert_item(subset[i+1]->subset, MINIMUM-1, subset[i+1]->child_count, subset[i]->subset[MINIMUM-1]);
        }

        subset[i] = subset[i+1];
        delete_item(subset, i+1, child_count, temp);

        return;
    }

    //merge left...
    if(subset[i]->data_count == MINIMUM-1 && i <= child_count-1){
        cout << "merge left: " << endl;

        // moving datas...
        insert_item(subset[i-1]->data, subset[i-1]->data_count, subset[i-1]->data_count, data[i-1]);

        //moving subsets.
        if(!subset[i]->is_leaf()){
            insert_item(subset[i-1]->subset, subset[i-1]->child_count, subset[i-1]->child_count, subset[i]->subset[MINIMUM-1]);
        }
        data_count--;
        child_count--;

        return;
    }

}

#endif