#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

#include "../../includes/tree/tree.h"
#include "../../includes/avl/avl.h"
#include "../../includes/avl/avl_functions.h"

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}
bool interactive(bool debug = false){
  int num;
  AVL<int> avl; 

  char user_input;
  while(toupper(user_input) != 'X'){
    cin >> user_input;
    switch(toupper(user_input)){
      case 'I': {
        cin >> num;
        cout << "inserting: " << num << endl;
        avl.insert(num);
        cout << avl << endl;
        break;
      }
      case 'R':{
        cin >> num; 
        cout << "removing: " << num << endl;
        avl.erase(num);
        cout << avl << endl;
        break;
      }
      case 'C':{
        cout << "clearing: " << endl;
        avl.clear_all();
        cout << avl << endl; 
        break;
      }
    }
  }
  return true;
}

bool spin_class(bool debug = false){
  return true;
  if(debug) cout <<  "testB :: spin-class() we're spinnning << endl";
  
  int a[30] = {300,350,330,320,310,250,260,270,280,290,285,286,315,314};
  // int a[30] = {300,350,330,320,310,315,314};
  // int a[30] = {50,25,75,12,35};          //For right rotation.
  // int a[30] = {300,350,330,320,310,315};
  // int a[30] = {300,330,350,320,310};
  // int a[30] = {300,350,330,320};
  // int a[30] = {300,350,330};             //For right left rotation.
  // int a[30] = {300,250,260,270,280,290,285,286};
  // int a[30] = {300,250,260,270,280,290};
  // int a[30] = {300,250,260,270,280};
  // int a[30] = {300,250,260,270};
  // int a[30] = {300,250,260};             //For left right rotation.
  // int a[30] = {77,45,3,58,87,82,91};
  tree_node<int>* t = nullptr;
  // for(int i = 0; i < 14; i++){
  //   tree_insert(t, a[i]);
  // }
  
  // for(int i = 0; i < 13; i++){            //Completely right leaning  tree.
  //   tree_insert(t, i);
  //   tree_print_debug(t,0);
  //   cout << endl << endl << endl;
  // }

  for(int i = 9; i >= 0; i--){            //Completely left leaning  tree.
    tree_insert(t, i);
    tree_print_debug(t,0);
    cout << endl << endl << endl;
  }

  // tree_print_debug(t, 0);
  // tree_insert(t, 6);                   //For the right rotation test.  
  // cout << endl << endl << endl;
  // tree_print_debug(t, 0);
  // rotate_right(t);
  // rotate_left(t);
  // cout << endl << endl << endl;
  // tree_print_debug(t,0);

  // tree_print_debug(t,0);

  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_INTERACTIVE, TestInteractive){
  bool success = interactive(false);
  EXPECT_EQ(success, true);
}

TEST(TEST_STUB, SpinClass){
  bool success= spin_class(false);
  EXPECT_EQ(success, true);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

