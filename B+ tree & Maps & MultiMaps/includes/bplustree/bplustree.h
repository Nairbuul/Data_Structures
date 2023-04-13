#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include "btree_array_funcs.h"
#include "pair.h"
#include "multipair.h"

template <class T>
class BPlusTree
{
public:
    class Iterator{
    public:

        friend class BPlusTree;
        Iterator(BPlusTree<T>* _it=NULL, int _key_ptr = 0): it(_it), key_ptr(_key_ptr){
            
        }

        T operator *(){
            return it->data[key_ptr];
        }
        Iterator operator++(int un_used){
          Iterator current = *this;
            key_ptr++;
            if(key_ptr == it->data_count){
                key_ptr = 0;
                it = it->next;
            }
          return current;
        }
        Iterator operator++(){
            key_ptr++;
            if(key_ptr == it->data_count){
                key_ptr = 0;
                it = it->next;
            }
            return *this;
        }
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs){
            return lhs.it == rhs.it;
        }
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs){
            return lhs.it != rhs.it;
        }
        void print_Iterator(){
            if (it){
                cout<<"iterator: ";
                print_array(it->data, it->data_count, key_ptr);
            }
            else{
                cout<<"iterator: NULL, key_ptr: "<<key_ptr<<endl;
            }
        }
        bool is_null(){return !it;}
        void info(){
            cout<<endl<<"Iterator info:"<<endl;
            cout<<"key_ptr: "<<key_ptr<<endl;
            cout<<"it: "<<*it<<endl;
        }

    private:
        BPlusTree<T>* it;
        int key_ptr;
    };

    BPlusTree(bool dups = false);
    BPlusTree(T *a, int size, bool dups = false);

    //big three:
    BPlusTree(const BPlusTree<T>& other);
    ~BPlusTree();
    BPlusTree<T>& operator =(const BPlusTree<T>& RHS);

    void copy_tree(const BPlusTree<T>& other);  //copy other into this object
    void copy_tree(const BPlusTree<T>& other, BPlusTree<T>*& last_node);

    void insert(const T& entry);   //insert entry into the tree
    void remove(const T& entry);   //remove entry from the tree
    void clear_tree();             //clear this object (delete all nodes etc.)

    bool contains(const T& entry) const; //true if entry can be found
    T& get(const T& entry);              //return a reference to entry
    const T& get(const T& entry)const;   //return a reference to entry
    T& get_existing(const T& entry);     //return a reference to entry
    Iterator find(const T& key);         //return an iterator to this key.
                                         //     NULL if not there.
    Iterator lower_bound(const T& key);  //return first that goes NOT BEFORE
                                         // key entry or next if does not
                                         // exist: >= entry
    Iterator upper_bound(const T& key);  //return first that goes AFTER key
                                         //exist or not, the next entry  >entry
    Iterator equal_bound(const T& key);

    int size() const;                    //count the number of elements

    bool empty() const;                  //true if the tree is empty

    void print_tree(int level = 0,
                    ostream &outs=cout) const;
    friend ostream& operator<<(ostream& outs,
                               const BPlusTree<T>& print_me){
        print_me.print_tree(0, outs);
        return outs;
    }

    bool is_valid();
    string in_order();
    string pre_order();
    string post_order();

    Iterator begin();
    Iterator end();
    ostream& list_keys(Iterator from = NULL, Iterator to = NULL){
        if (from == NULL) from = begin();
        if (to == NULL) to = end();
        for (Iterator it = from; it != to; it++)
            cout<<*it<<" ";
        return cout;

    }

// private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    bool dups_ok;                        //true if duplicate keys are allowed
    int data_count;                      //number of data elements
    T data[MAXIMUM + 1];                 //holds the keys
    int child_count;                     //number of children
    BPlusTree* subset[MAXIMUM + 2];      //subtrees
    BPlusTree* next;
    bool is_leaf() const
    {return child_count==0;}             //true if this is a leaf node

    T* find_ptr(const T& entry);         //return a pointer to this key.
                                         // NULL if not there.

    //insert element functions
    void loose_insert(const T& entry);   //allows MAXIMUM+1 data elements in
                                         //   the root
    void fix_excess(int i);              //fix excess in child i

    //remove element functions:
    void loose_remove(const T& entry);  //allows MINIMUM-1 data elements
                                        //  in the root

    BPlusTree<T>* fix_shortage(int i);  //fix shortage in child i
    // and return the smallest key in this subtree
    BPlusTree<T>* get_smallest_node();
    void get_smallest(T& entry);      //entry := leftmost leaf
    void get_biggest(T& entry);       //entry := rightmost leaf
    void remove_biggest(T& entry);    //remove the biggest child of tree->entry
    void transfer_left(int i);        //transfer one element LEFT from child i
    void transfer_right(int i);       //transfer one element RIGHT from child i
    BPlusTree<T> *merge_with_next_subset(int i); //merge subset i with  i+1

};
//---------------------------------------------------------------------
//            C T O R  /  B I G   T H R E E
//---------------------------------------------------------------------

template <typename T>
BPlusTree<T>::BPlusTree(bool dups):dups_ok(dups), data_count(0), child_count(0), next(NULL){
    //left empty
}
template <typename T>
BPlusTree<T>::BPlusTree(T *a, int size, bool dups){
    dups_ok = dups;
    data_count = 0;
    child_count = 0;
    next = nullptr;
    for(int i = 0; i < size; i++){
        insert(a[i]);
    }
}
template <typename T>
BPlusTree<T>::BPlusTree(const BPlusTree<T>& other):data_count(0), child_count(0){
    clear_tree();
    copy_tree(other);
}

template <typename T>
BPlusTree<T>::~BPlusTree(){
    const bool debug = false;
    if (debug) cout<<"** destructor fired!"<<endl;
    clear_tree();
}

template <typename T>
BPlusTree<T>& BPlusTree<T>::operator =(const BPlusTree<T>& RHS){
    const bool debug = false;
    if (debug) cout<<"** assignment operator fired!"<<endl;
    if(RHS == &this){
        return *this;
    }

    clear_tree();
    copy_tree(RHS);

    return *this;
}
template <typename T>
void BPlusTree<T>::copy_tree(const BPlusTree<T>& other){
    //assumes this bptree is empty.
    assert(empty());
    BPlusTree<T>* temp = nullptr;
    copy_tree(other, temp);
}
template <typename T>
void BPlusTree<T>::copy_tree(const BPlusTree<T>& other, BPlusTree<T>*& last_node){
    copy_array(data, other.data, data_count, other.data_count);
    child_count = other.child_count;
    for(int i = 0; i < child_count; i++){
        subset[i] = new BPlusTree<T>();
        subset[i]->copy_tree(*other.subset[i], last_node);
        if(subset[i]->is_leaf() && last_node != subset[i]){
            if(last_node != nullptr)
                last_node->next = subset[i];
            last_node = subset[i];
        }
    }
}

template <typename T>
void BPlusTree<T>::insert(const T& entry){
    // if(contains(entry)){
    //     return;
    // }
    loose_insert(entry);
    if(data_count == MAXIMUM+1){
        BPlusTree<T>* growth = new BPlusTree();
        copy_array(growth->data, data, growth->data_count, data_count);
        copy_array(growth->subset, subset, growth->child_count, child_count);
        data_count = 0;
        child_count = 0;
        subset[child_count] = growth;
        fix_excess(child_count);
    }
}
template <typename T>
void BPlusTree<T>::remove(const T& entry){
    /*
     * ---------------------------------------------------------------------------------
     * Same as BTree:
     * Loose_remove the entry from this tree.
     * Shrink if you have to
     * ---------------------------------------------------------------------------------
     * once you return from loose_remove, the root (this object) may have no data and
     * only a single subset:
     * now, the tree must shrink:
     *
     * point a temporary pointer (shrink_ptr) and point it to this root's only subset
     * copy all the data and subsets of this subset into the root (through shrink_ptr)
     * now, the root contains all the data and poiners of it's old child.
     * now, simply delete shrink_ptr, and the tree has shrunk by one level.
     * Note, the root node of the tree will always be the same, it's the
     * child node we delete
     *
     *
     */

}
template <typename T>
void BPlusTree<T>::clear_tree(){
    if(is_leaf()){
        next = nullptr;
    }
    for(int i = 0; i < child_count; i++){
        subset[i]->clear_tree();
        subset[i] = nullptr;
    }
    data_count = 0;
    child_count = 0;
}   
// ========================= FIND FUNCTIONS =========================
template <typename T>
bool BPlusTree<T>::contains(const T& entry) const{
    int i = first_ge(data, data_count, entry);
    if(i < data_count && data[i] == entry){
        return true;
    }
    if(!is_leaf()){
        return subset[i]->contains(entry);
    }
    return false;
}
template <typename T>
T& BPlusTree<T>::get(const T& entry){
    if(!contains(entry)){
        insert(entry);
    }

    return get_existing(entry);
}     
template <typename T>
const T& BPlusTree<T>::get(const T& entry)const{
    const bool debug = false;
    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if(is_leaf()){
        if(found){
            return data[i];
        }
        else{
            if(debug) cout << "const get was called with nonexistent entry" << endl;
            assert(found);
        }
    }
    if (found) 
        return subset[i+1]->get(entry);
    else 
        return subset[i]->get(entry);
}  
template <typename T>
T& BPlusTree<T>::get_existing(const T& entry){   
/*
 * ---------------------------------------------------------------
 * This routing explains plainly how the BPlusTree is organized.
 * i = first_ge
 *       |      found         |    !found         |
 * ------|--------------------|-------------------|
 * leaf  |  you're done       | it's not there    |
 *       |                    |                   |
 * ------|--------------------|-------------------|
 * !leaf | subset[i+1]->get() |  subset[i]->get() |
 *       | (inner node)       |                   |
 * ------|--------------------|-------------------|
 *       |                    |                   |
 *
 * ---------------------------------------------------------------
 *
 */
    //assert that entry is not in the tree.
    //assert(contains(entry));

    const bool debug = false;
    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if (is_leaf()){
        if (found){
            return data[i];
        }
        else{
            if (debug) cout<<"get_existing was called with nonexistent entry"<<endl;
            assert(found);
        }
    }
    if (found) //inner node
        return subset[i+1]->get(entry);
        //or just return true?
    else //not found yet...
        return subset[i]->get(entry);
}
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::find(const T& key){
    int i = first_ge(data, data_count, key);
    if(i < data_count && data[i] == key){
        return Iterator(this, i);
    }
    if(!is_leaf()){
        return subset[i]->find(key);
    }
    return Iterator(nullptr);
}  
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::lower_bound(const T& key){
    BPlusTree<T>::Iterator walker = begin();
    while(walker != end()){
        if(*walker >= key){
            return walker;
        }
        walker++;
    }
    return Iterator(NULL);
}
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::upper_bound(const T& key){
    BPlusTree<T>::Iterator walker = begin();
    while(walker != end()){
        if(*walker >= key){
            walker++;
            return walker;
        }
        walker++;
    }
    return Iterator(NULL);
}
template<typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::equal_bound(const T& key){
    BPlusTree<T>::Iterator walker = begin();
    while(walker != end()){
        if(*walker == key){
            return walker;
        }
        walker++;
    }
    return Iterator(NULL);
}
template <typename T>
int BPlusTree<T>::size() const{
    int size = 0;
    if(!is_leaf()){
        for(int i = 0; i < child_count; i++){
           size += subset[i]->size();
        }
        size += data_count;
    }
    else{
        return data_count;
    }
    return size;
}               
template <typename T>
bool BPlusTree<T>::empty() const{
    return data_count == 0;
}                  
template <typename T>
void BPlusTree<T>::print_tree(int level, ostream &outs) const{
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
            if(data_count != 0){
                if(next == nullptr){
                    cout << setw(6+level*3) << "≅"<< endl;
                }
                cout << setw(4+level*3) << "^" << endl;
                cout << setw(4+level*3) << "|" << endl;
                cout << setw(4+level*3) << "-" << endl;
                for(int i = data_count -1; i >= 0; i--){
                    outs << setw(4+level*3) << data[i] << endl;
                }
                outs << setw(4+level*3) << "-" << endl;
            }
    }
}
template <typename T>
bool BPlusTree<T>::is_valid(){
    return true;
}
template <typename T>
string BPlusTree<T>::in_order(){
    string in_order;
    if(!is_leaf()){
        for(int i = 0; i < child_count; i++){
            in_order += subset[i]->in_order();
            if( i < data_count){
                in_order += to_string(data[i]) + "|";
            }
        }
    }
    else{
        for (int i = 0; i < data_count; i++){
            in_order += to_string(data[i]) + "|";
        }
    }
    return in_order;
}
template <typename T>
string BPlusTree<T>::pre_order(){
  string pre_order;
  if(!is_leaf()){
    for(int i = 0; i < child_count; i++){
        if(i < data_count){
            pre_order += to_string(data[i]) + "|";
        }
        pre_order += subset[i]->pre_order();
    }
  }
  else{
    for(int i = 0; i < data_count; i++){
        pre_order += to_string(data[i]) + "|";
    }
  }
  return pre_order;
}
template <typename T>
string BPlusTree<T>::post_order(){
    string post_order;
    if(!is_leaf()){
        for(int i = 0; i < child_count; i++){
            post_order += subset[i]->post_order();
            if(i > 0)
                post_order += to_string(data[i-1]) + "|";
        }
    }
    if(is_leaf()){
        for(int i =0; i < data_count; i++){
            post_order += to_string(data[i]) + "|";
        }
    }
    return post_order;
}

template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::begin(){  //Checked
    return Iterator(get_smallest_node());
}
template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::end(){ //Checked
    return Iterator(NULL);
}
//Helper
template <typename T>
T* BPlusTree<T>::find_ptr(const T& entry){
    
    int i = first_ge(data, data_count, entry);
    if(i < data_count && data[i] == entry){
        return &data[i];
    }
    if(!is_leaf()){
       return subset[i]->find_ptr(entry);
    }
    return nullptr;
}
template <typename T>
void BPlusTree<T>::loose_insert(const T& entry){

    // check
    if(!is_valid()){
        return;
    }
    int index = first_ge(data,data_count, entry);
    bool found = data[index] == entry && index < data_count; 
    if(!found){
        if(!is_leaf()){
            subset[index]->loose_insert(entry);
            if(subset[index]->data_count >= MAXIMUM+1)
                fix_excess(index);
        }
        if(is_leaf()){
            insert_item(data, index, data_count, entry);
        }
    }
}   
template <typename T>
void BPlusTree<T>::fix_excess(int i){
    BPlusTree<T>* temp = new BPlusTree();
    split(subset[i]->data, subset[i]->data_count, temp->data, temp->data_count);
    split(subset[i]->subset, subset[i]->child_count, temp->subset, temp->child_count);
    T capsule;
    delete_item(subset[i]->data, subset[i]->data_count-1, subset[i]->data_count, capsule);
    insert_item(subset, i+1, child_count, temp);
    ordered_insert(data, data_count, capsule);
    child_count = data_count+1;
    if(subset[i]->is_leaf()){
        insert_item(temp->data, 0, temp->data_count, capsule); //Bring down.
        temp->next = subset[i]->next; //connect new node to prev node next
        subset[i]->next = temp; //connect the middle node to the new one
    }
}
template <typename T>
void BPlusTree<T>::loose_remove(const T& entry){

}
template <typename T>
BPlusTree<T>* BPlusTree<T>::fix_shortage(int i){
    return nullptr;
}  
template <typename T>
BPlusTree<T>* BPlusTree<T>::get_smallest_node(){
    if(!is_leaf()){
        return subset[0]->get_smallest_node();
    }
    if(is_leaf()){
        return this;
    }
    return nullptr;
}
template <typename T>
void BPlusTree<T>::get_smallest(T& entry){
    if(!is_leaf()){
        subset[0]->get_smallest(entry);
    }
    if(is_leaf()){
        entry = data[0];
    }
}
template <typename T>
void BPlusTree<T>::get_biggest(T& entry){

}
template <typename T>
void BPlusTree<T>::remove_biggest(T& entry){

}
template <typename T>
void BPlusTree<T>::transfer_left(int i){

}
template <typename T>
void BPlusTree<T>::transfer_right(int i){

}
template <typename T>
BPlusTree<T> *BPlusTree<T>::merge_with_next_subset(int i){
    return nullptr;
}
#endif