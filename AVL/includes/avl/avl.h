#ifndef AVL_H
#define AVL_H

#include "avl_functions.h"
#include "../tree/tree.h"

template <typename T>
class AVL{
public:
    AVL();
    AVL(const T *list, int size = -1);
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    AVL(const AVL<T> &copy_me);
    AVL<T> &operator=(const AVL<T> &rhs);
    ~AVL();
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    bool insert(const T &insert_me);
    bool erase(const T &target);

    bool contains(const T &target) const;

    void clear(tree_node<T>* root);
    void clear_all();
    bool empty()const;

    string pre_order() const;
    string in_order() const;
    string post_order() const;

    bool search(const T &target, tree_node<T> *&found_ptr) const;

    void output_inorder(ostream &outs);

    friend ostream& operator <<(ostream& outs, const AVL<T>& tree){
        tree_print_debug(tree._root, 0, outs);
        return outs;
    }
    AVL<T> &operator+=(const AVL<T> &rhs);

private:
    tree_node<T>* _root;
};

template <typename T>
AVL<T>::AVL(){
    _root = nullptr;
}
template <typename T>
AVL<T>::AVL(const T *list, int size){
    _root = nullptr;
    for (int i = 0; i< size; i++){
        tree_insert(_root, list[i]);
    }
}
//. . . . . . .. . . . . . . .Big Three. . . .  . . . . . . . .
template <typename T>
AVL<T>::AVL(const AVL<T> &copy_me){
    _root = nullptr;
    _root = tree_copy(copy_me._root);
    _root->_height = copy_me._root->_height;
}
template <typename T>
AVL<T> &AVL<T>::operator=(const AVL<T> &rhs){
    if(this == &rhs){
        return *this;
    }

    _root = nullptr;
    _root = tree_copy(rhs._root);
    _root->_height = rhs._root->_height;

    return *this;
}
template <typename T>
AVL<T>::~AVL(){
    tree_clear(_root);
}
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
template <typename T>
bool AVL<T>::insert(const T &insert_me){
    tree_insert(_root, insert_me);
    return tree_search(_root, insert_me);
}

template <typename T>
bool AVL<T>::erase(const T &target){
    return tree_erase(_root, target);
}

template <typename T>
bool AVL<T>::contains(const T &target) const{
    return tree_search(_root, target);
}

template <typename T>
void AVL<T>::clear(tree_node<T>* root){
    //FUNCTION OFF TO THE RETIREMENT HOME
    
    //Delete repeats in tree.
    // if(root){
        // if(tree_search(root, root->_item)){
        //     tree_erase(root->_right, root->_item);
        //     tree_erase(root->_left, root->_item);
        // }
        // if(tree_search(root->_right, root->_item)){
        //     tree_erase(root->_right, root->_item);
        // }
        // if(tree_search(root->_left, root->_item)){
        //     tree_erase(root->_left, root->_item);
        // }
    //     clear(root->_left);
    //     clear(root->_right);
    //     root->update_height();
    // }
}

template <typename T>
void AVL<T>::clear_all(){
    tree_clear(_root);
}

template <typename T>
bool AVL<T>::empty()const{
    return !_root;
}

template <typename T>
string AVL<T>::pre_order() const{
    string pre_order;
    pre_order += pre_order_string(_root);
    return pre_order;
}

template <typename T>
string AVL<T>::in_order() const{
    string in_order;
    in_order += in_order_string(_root);
    return in_order;
}

template <typename T>
string AVL<T>::post_order() const{
    string post_order;
    post_order += post_order_string(_root);
    return post_order;
}

template <typename T>
bool AVL<T>::search(const T &target, tree_node<T> *&found_ptr) const{
    return tree_search(_root, target, found_ptr);
}

template <typename T>
void AVL<T>::output_inorder(ostream &outs){
    outs << in_order(_root, outs);
}

template <typename T>
AVL<T> &AVL<T>::operator+=(const AVL<T> &rhs){
    tree_add(_root, rhs._root);
    return *this;
}

#endif