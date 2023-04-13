#include <iostream>
#include <iomanip>
#include <algorithm>

#include "includes/btree_array_functions/btree_array_functions.h"
using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    
    int a[15] = {1,2,3,4,5};
    int b[15] = {6,7,8,9,10};
    int c[15] = {};
    int size=4;
    int size2;
    split(a, size, c, size2);
    cout << size2 << endl;
    for(int i = 0; i < size2; i++){
        cout << c[i] << " " ;
    }
    cout << endl;
    // int* ptr = &b[1];
    // cout << *ptr << endl;  
    // *ptr = 9999;
    // for(int i = 0; i < 5; i++){
    //     cout << b[i] << "b ";
    // }
    // cout << endl;
    // for(int i = 0; i < 5; i++){
    //     a[i+5] = b[i];
    // }
    
    // for(int i = 0; i < 10; i++){
    //     cout << a[i] << " ";
    // }

    // a[10] = 11;

    // int k = 11/2;
    // cout << k << endl;
    // int c[15];
    // for(int i = 0; i <= k; i++){
    //     c[i] = a[k+i];
    // }

    // for(int i = 0; i <= k; i++){
    //     cout << c[i] << " ";
    // }

    cout << "\n\n\n=====================" << endl;
    return 0;
}
