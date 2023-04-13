#ifndef TREE_H
#define TREE_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;

template <typename T>
struct tree_node{
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    int _height;
    int balance_factor(){
        //balance factor = height of the left subtree 
        //                        - the height of the right subtree
        //a NULL child has a height of -1
        //a leaf has a height of 0
        
        if(!_left && _right){
            return -1 - _right->_height;
        }
        else if(_left && !_right){
            return _left->_height - (-1);
        }
        else if(_left && _right){
            return _left->_height - _right->_height;
        }
        else{
            return 0;
        }
    }

    int height(){
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)
        
        //Revise this monstrosity
        if(!_right && !_left){
            return 0;
        }
        else if(_right && !_left){
            return _right->_height + 1;
        }
        else if(!_right  && _left){
            return _left->_height + 1;
        }
        else if(_right && _left){
            if(_right->_height > _left->_height){
                return _right->_height + 1;
            }
            else{
                return _left->_height + 1;
            }
        }
        else{
            return -1;
        }
    }
    int update_height(){
        //set the _height member variable (call height();)
        return _height = height();
    }

    tree_node(T item=T(), tree_node* left=NULL, 
                          tree_node* right=NULL):
                    _item(item), _left(left), _right(right)
    {   
        //don't forget to set the _height.
        _height = height();
    }
    friend ostream& operator <<(ostream& outs, const tree_node<T>& t_node){
        outs<<"|"<<t_node._item<<"|";
        return outs;
    }
};

#endif