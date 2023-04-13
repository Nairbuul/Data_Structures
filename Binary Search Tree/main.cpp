#include <iostream>
#include <iomanip>

using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
    for (int i = 10 ; i >= 0; i--){
        cout << a[i] << '\t' <<  a[i]/2 << "\t" ; 
        cout << a[i] << '\t' <<  a[i]%2 << endl; 
        // cout << a[i]
    }
    // int* b = a;
    // int c = b[3*2-1];
    // cout << c;
    // cout << -1-(-3);
    


    cout << "\n\n\n=====================" << endl;
    return 0;
}