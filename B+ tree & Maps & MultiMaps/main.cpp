#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    vector<int> a = {0,1,2,3,4,5,6,7,8,9,10};
    for(vector<int>::iterator it = a.begin(); it != a.end(); it++){
        cout << *it << endl;
    }


    cout << "\n\n\n=====================" << endl;
    return 0;
}
