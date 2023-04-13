#ifndef BST_FUNCTIONS_H
#define BST_FUNCTIONS_H

#include <assert.h>
#include <string>

#include "../tree/tree.h"

template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me);

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target);
template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr);

template<typename T>
void tree_print(tree_node<T>* root, int depth=0,
                                    ostream& outs=cout);

template<typename T> //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int depth=0,
                                          ostream& outs=cout);

template <typename T> //clear the tree
void tree_clear(tree_node<T>* &root);

template <typename T> //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target);

template <typename T> //erase rightmost node from the tree -> max_value
void tree_remove_max(tree_node<T>* &root, T& max_value);

template <typename T> //print in_order
void in_order(tree_node<T>* root,ostream& outs=cout);

template <typename T> //print pre_order
void  pre_order(tree_node<T>* root,ostream& outs=cout);

template <typename T> //print post_order
void  post_order(tree_node<T>* root,ostream& outs=cout);

template <typename T> //string in_order
string in_order_string(tree_node<T>* root);

template <typename T> //string pre_order
string pre_order_string(tree_node<T>* root);

template <typename T> //string post_order
string post_order_string(tree_node<T>* root);

template <typename T> //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root);

template <typename T> //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src);

template <typename T> //sorted array of ints -> tree
tree_node<T>* tree_from_sorted_list(const T* a);

template <typename T> // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size);

//=============================================================|
//                        Definitions                          |
//=============================================================|

template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me){
    if(!root){                          //[Base case]Two scenarios: empty tree or the proper location is found.
        root = new tree_node<T>(insert_me);
    }
    else if(insert_me < root->_item){   //Updating the location while keeping the isertion item the same. Left if item is lower and right if item is greater.
        //inserting into left tree.
        tree_insert(root->_left, insert_me);
    }
    else{
        //inserting into the right tree.
        tree_insert(root->_right, insert_me);
    }
    root->update_height();
}

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target){
    const bool debug = false;
    if(!root){                 //[Base Case #2]: If item is not found or empty tree is inserted.
        if(debug) cout << "tree_search: " << 
                          "Not Found. root is NULL" << endl;
        return nullptr;
    }
    if(root->_item == target){ //[Base Case #1]: If item is found.
        if(debug) cout << "tree_search: " << 
                          "found target: [" << root->_item << "]" << endl; 
        return root;
    }
    if(target < root->_item){ //Recursion: Updating the position moving left of tree while keeping target the same. (Will only move left if <)
        if(debug) cout << "tree_search: going left" << endl;
        return tree_search(root->_left, target);
    }
    if(target > root->_item){ //Recursion: Updating the position moving right of tree while keeping target the same.(Will only move right if >)
        if(debug) cout << "tree_search: going right" << endl;
        return tree_search(root->_right, target);
    }
    cout << "How did I get here ?!?!" << endl;
    return nullptr;
}

template <typename T>
bool tree_search(tree_node<T>* root, const T& target,tree_node<T>* &found_ptr){
    if(!root){
        return false;
    }
    if(root->_item == target){
        found_ptr = root; 
        return true;
    }
    if(target < root->_item){
        return tree_search(root->_left, target, found_ptr);
    }
    if(target > root->_item){
        return tree_search(root->_right, target, found_ptr);
    }
    return false; //Not needed For compiler.
}

template<typename T>
void tree_print(tree_node<T>* root, int depth,ostream& outs){

    /*This will move to the right side of the tree until it reaches a leaf that points at null on the right side. It'll then print the item at that leaf and check
    the left side and finish the function call. After finishing that function call it'll move to the previous leaf and print it and check if there is a left address.
    If yes it'll move there and continue checking for right and left addresses. If not it'll move back it'll continue to finish function calls until all the leaves
    have been visited.*/

    if(root){
        tree_print(root->_right, depth + 1);
        outs << setw(4 + depth*3) << "[" << root->_item << "]" << endl;
        tree_print(root->_left, depth + 1);
    }
}

template<typename T> //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int depth, ostream& outs){
    if(root){
        bool debug = false;
        if(!debug){
            tree_print_debug(root->_right, depth + 1);
            outs << setw(4 + depth*3) << '[' << root->_item << ':' << root->_height 
                 << " " << "(" << root->balance_factor() << ")]" << endl;
            tree_print_debug(root->_left, depth + 1);
        }
        if(debug){
                bool null_left = true;
                bool null_right = true;
                if(root->_left == nullptr){
                    null_left = false;
                }
                if(root->_right == nullptr){
                    null_right = false;
                }
            
            tree_print_debug(root->_right, depth+1);
            cout << "Node: [" << root->_item << ']' << "\tHeight: " << root->_height 
                 << "\tLeft Child: " << boolalpha << null_left 
                 << "\tRight Child: " << boolalpha << null_right << endl; 
            tree_print_debug(root->_left, depth+1);
        }
    }
}

template <typename T> //clear the tree
void tree_clear(tree_node<T>* &root){
    if(root){
        tree_clear(root->_right); //Moves all the way to the right first.
        tree_clear(root->_left);  //Then left. If there are no nodes the function will unfreeze and delete.

        delete root;
        root = nullptr;
    }
}

template <typename T> //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target){ 
    if(!root){
        return false;
    }
    if(target == root->_item){
        if(!root->_left){
            //If this node is pointing to nothing we'll just delete it.
            tree_node<T>* temp = root;
            root = root->_right;

            delete temp;           
            return true;
        }
        else{
            //If this node is pointing to a left child. We'll grab the largest right node.
            //If that node has a left child we'll link that to the grandparent node. Grab the item
            //and use it as a replacement for the node we're going to delete.
            int replacement = 0;
            tree_remove_max(root->_left, replacement);
            root->_item = replacement;
            return true; 
        }
    }
    else if(target < root->_item){
        tree_erase(root->_left, target);
    }   
    else{
        tree_erase(root->_right, target);
    }
    root->update_height();
    return false;
}

template <typename T> //erase rightmost node from the tree -> max_value
void tree_remove_max(tree_node<T>* &root, T& max_value){ 
    //Issue if max_value is uninitialize it might be an issue.
    if(root){
        tree_remove_max(root->_right, max_value);
        root->update_height();
        if(!root->_right && root->_left && max_value < root->_item){
            //Case #1 left child is not null. 
            //Case #2 max_value < root->_item in case we alter the tree and the new node is in the same
            //scenario as the previous removed node that is larger.
            max_value = root->_item;                            
            tree_node<T>* temp = root;
            root = root->_left;
            delete temp;
            temp = nullptr;
        }
        else if(!root->_right && !root->_left && max_value < root->_item){
            //Case #3 left and right are pointing to null. 
            max_value = root->_item;
            delete root;
            root = nullptr;
        }
    }
}

template <typename T> //print in_order
void in_order(tree_node<T>* root,ostream& outs){
    if(root){
        in_order(root->_left);
        outs << '[' <<root->_item << ']';
        in_order(root->_right);
    }
}

template <typename T> //print pre_order
void  pre_order(tree_node<T>* root,ostream& outs){
    if(root){
        outs << '[' <<root->_item << ']';
        pre_order(root->_left);
        pre_order(root->_right);
    }
}

template <typename T> //print post_order
void  post_order(tree_node<T>* root,ostream& outs){
    if(root){
        post_order(root->_left);
        post_order(root->_right);
        outs << '[' <<root->_item << ']';
    }
}

template <typename T> //string in_order
string in_order_string(tree_node<T>* root){
    string in_order;
    if(root){
        in_order += '[' + to_string(root->_item) + ']';  
        return in_order_string(root->_left) += in_order += in_order_string(root->_right);
    }
    return in_order;
}

template <typename T> //string pre_order
string pre_order_string(tree_node<T>* root){
    string pre_order;
    if(root){
        pre_order += '[' + to_string(root->_item) + ']';
        return pre_order += pre_order_string(root->_left) += pre_order_string(root->_right);
    }
    return pre_order;
}

template <typename T> //string post_order
string post_order_string(tree_node<T>* root){
    string post_order;
    if(root){
        post_order += '[' + to_string(root->_item) + ']';
        return post_order_string(root->_left) += post_order_string(root->_right) += post_order;
    }
    return post_order;
}


template <typename T> //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root){

    if(root){
        return new tree_node<T>(root->_item, tree_copy(root->_left), tree_copy(root->_right));
    }
    else{
        return NULL;
    }

    /*It'll return the item and then call itself again updating the postion to the left.
    then once it reaches the end it'll go back and move to the right. Order: all the way left.
    then right -> left move back if done repeat.*/
}

template <typename T> //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src){
    if(src){
        tree_insert(dest, src->_item);
        tree_add(dest, src->_left);
        tree_add(dest, src->_right);
    }
}

template <typename T> //sorted array of ints -> tree
tree_node<T>* tree_from_sorted_list(const T* a){
    
    return nullptr;
}

template <typename T> // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size){
   /*
    Given a sorted array of T; 
    Construct a binary tree

    //[1] [2] [3]
    
    
    [4][5][6][7][8][9] [10] [11][12][13][14][15][16][17][18][19][20]
    
    //Draw the chart they have an ueven left and right side.

    Step 1: Break into half.
    Step 2: insert the middle of the array.
    Step 3: Recursively add.
   */

    if(size == 0){
        return nullptr;
    }

    int mid = size/2;
    
    tree_node<T>* sorted_tree = new tree_node<T>(a[mid]);
     
    sorted_tree->_left = tree_from_sorted_list(a, mid);
    sorted_tree->_right = tree_from_sorted_list(a+mid+1, size-mid-1); 

    sorted_tree->update_height();

    return sorted_tree;
}   

#endif