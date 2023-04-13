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

template<typename T>
void append(vector<T>& dest, vector<T>source){
    for(int i = 0; i < source.size();i++){
        dest.push_back(source[i]);
    }
}

template<typename T>
void filter_duplicates(vector<T>& source){
    vector<T> temp = source;
    source.clear();
    for(int i = 0; i < temp.size(); i++){
        if(find(source.begin(),source.end(), temp[i]) != source.end()){
            // cout << "found: " << temp[i] << endl;
        }
        else{
            source.push_back(temp[i]);
        }
    }
}

template<typename T>
void grab_duplicates(vector<T>& source){
    vector<T>temp = source;
    vector<T> dups;
    source.clear();
    
    //reused code seems a little hackish but it works i guess...
    for(int i = 0; i < temp.size(); i++){
        if(find(source.begin(),source.end(), temp[i]) != source.end()){
            // cout << "found: " << temp[i] << endl;
            dups.push_back(temp[i]);
        }
        else{
            source.push_back(temp[i]);
        }
    }

    source = dups;
}

#endif