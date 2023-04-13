#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <stdlib.h>
#include "../../includes/tree/tree.h"
#include "../../includes/bst/bst.h"
#include "../../includes/bst_functions/bst_functions.h"

using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool bst_test(bool debug = false){
  if(debug){
    cout << "testB:: bst_test() entering bst_test" << endl;
  }

  // int arr[10];
  // for(int i = 0; i < 10; i++){
  //   arr[i] = i;
  // }

  // BST<int> test (arr, 10);
  // cout << boolalpha << test.contains(5) <<  '\t' << boolalpha << test.contains(11100) << endl;
  // BST<int> test2(test); 
  // BST<int> test3 = test2;
  // test2.erase(5);
  // test2.erase(6);
  // cout << test2 << endl << endl << endl << test3;
  // test3.clear_all();
  // cout << boolalpha << test3.empty() << endl;
  // string a = test.pre_order();
  // string b = test.post_order();
  // string c = test.in_order();
  // cout << a << endl << b << endl << c << endl;
  // string d = test3.in_order();
  // string e =test2.pre_order();
  // cout << d << endl << e << endl;

  // BST<int> test4;
  // test4.contains(13);
  // test4.clear_all();
  // string f = test4.pre_order();
  // cout << f << endl;

  return true;
}

bool build_tree(bool debug = false){
  if(debug){
    cout << "testB:: test_tree() entering test_tree" << endl;
  }

  // int b = 10;
  // int a[b] = {50,25,75,15,95,1,100,17,13,69};

  //Tree
  //              50
  //        25          75
  //    15     17   69     95
  //1       13                100

  //Prefix: 50,25,15,1,13,17,75,69,95,100
  //In_order: 1,13,15,17,25,50,69,75,95,100
  //Postfix: 1,13,15,17,25,69,100,95,75,50
  
  // int b = 50;
  // int a[b] ={48,50,72,34,18,10,52,72,80,92,50,28,36,66,42,90  
  //           ,12,46,48,34,98,74,38,60,94,36,40,62,26,54,
  //           28,88,68,14,46,44,54,88,58,62,52,36,26,48,
  //           64,78,18,94,94,78};

  // int b = 22;
  // int a[22] = {49,60,35,67,95,31,100,83,54,35,25,42,86,79,64,8,65,46,9,49,83,55};

  // int b = 21;
  // int a[21] = {49,60,35,67,95,31,83,54,35,25,42,86,79,64,8,65,46,9,49,83,55};
  
  int b = 15;
  int a[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

  tree_node<int>* t = nullptr;
  t  = tree_from_sorted_list(a, 15);


  // for(int i = 0; i < b; i++){
  //   tree_insert(t, a[i]);
  // }

  tree_print_debug(t,0);

  // int max = 0;
  // tree_remove_max(t, max);
  // tree_erase(t,95);
  // tree_print(t,0);
  // cout << endl << endl;
  // tree_print_debug(t,0);

  // tree_print(t, 0);
  // cout << endl << "Printing in order: " << endl;
  // in_order(t);
  // cout << endl << "Printing pre-order: " << endl;
  // pre_order(t);
  // cout << endl << "Printing post-order: " << endl;
  // post_order(t); 

  // int v = 0; 
  // tree_remove_max(t, v);
  // cout << endl << "Removing Largest value [" << v << ']' << endl;
  // tree_print(t, 0);

  // cout << endl << endl << *tree_search(t, 1) << endl;

  // string test = in_order_string(t);
  // cout << endl << test << endl;

  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_STUB, BuildTree) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, build_tree(false));
}

TEST(TEST_STUB, BSTTEST){
  bool success = bst_test(false);
  EXPECT_EQ(success, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

