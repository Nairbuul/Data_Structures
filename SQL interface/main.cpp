#include <iostream>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string.h>
#include <fstream>
#include <assert.h>
#include <algorithm>
// #include <bits/stdc++.h>
#include <string>

#include "includes/stl_utils/vector_utilities.h"

using namespace std;


void put_2gether(vector<string>& a, vector<string>& b){
    for(int i = 0; i < b.size();i++){
        a.push_back(b[i]);
    }
}

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    // fstream a;
    // vector<string> test = {"Booo", "ooooo", "oooooooooooooo", "k"};
    // string test2 = "abcdefg";
    // a.open("test.txt", std::ios_base::out);
    // if(a.is_open()){
    //     cout << "open" << endl;
    //     a << "abcdefghijklmnopq";
    //     a.close();
        // for(int i =0; i < test.size[0](); i++){      
        //     a << 
        // }
    // }
    // else if(a.fail()){
    //     cout << "failed" << endl;
    // }
    
    // a.open("test.txt");
    // if(a.is_open()){
    //     string output;
    //     getline(a, output);
    //     cout << output;
    // }

    vector<string> a {"b","c","d"};
    vector<string> s;
    vector<string> z {"y","x","c","w"};
    // put_2gether(s,z);
    // for(int i =0;i<a.size();i++){
    //     cout <<s[i]<<"|";
    // }
    
    // for(int i = 0; i < z.size(); i++){
    //     if(find(a.begin(),a.end(), z[i]) != a.end()){
    //         cout << "ya" << endl;
    //     }
    //     else{
    //         cout << "nah" << endl;
    //     }
    // }

    //get rid of duplicates;
    // vector<string> duplicates {"a", "b", "c", "c", "d", "e", "f", "g", "h", "i", "a", "g", "z", "13", "156", "13"};
    // vector<string> d2 = duplicates;
    // filter_duplicates(duplicates);
    // cout << duplicates << endl;
    // cout << a.size() << '\t' << a[2] << endl;

    //keep duplicatse only
    // cout << __LINE__ << endl;
    // grab_duplicates(d2);
    // cout << __LINE__ << endl;
    // cout <<d2 << endl;
    // cout << __LINE__ << endl;


    // const vector<string> condition = {"(", "age", "<", "17", "or", "age", ">", "20", ")", "and", "lname", "=", "Jackson"};
    // char test2[300];
    // string test3;
    // for(int i = 0; i < condition.size(); i++){
    //     strcpy(test2, condition[i].c_str());
    //     // cout << i << ": " << test2 << "|" << endl;
    //     test3 += test2;
    //     cout << test3 << "<-size->" << test3.size() << endl;
    //     test3.clear();
    // }

    string b13 = "b13a";
    string b15 = "b14a";

    cout << b13.compare(b15) << endl;


    cout << "\n\n\n=====================" << endl;
    return 0;
}
