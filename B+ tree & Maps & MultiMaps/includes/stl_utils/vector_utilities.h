#ifndef VECTOR_UTILITIES_H
#define VECTOR_UTILITIES_H

#include <ostream>
#include <vector>

using namespace std;

template<typename T>
ostream& operator << (ostream&outs, const vector<T>& print_me){
    for (int i = 0; i < print_me.size(); i++){
        outs << print_me[i] << ' ';
    }
    return outs;
}

template <typename T>
vector<T>& operator +=(vector<T>& list, const T& addme){
    list.push_back(addme);
    return list;
}

#endif