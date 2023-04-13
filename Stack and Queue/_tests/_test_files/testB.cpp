#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include "../../includes/node/node.h"
#include "../../includes/array_functions/array_functions.h"
#include "../../includes/stack/MyStack.h"

using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_stack(bool debug = false){
  if(debug){
    cout << "testB test_node" << endl;
  }

  Stack<int> s;
  Stack<int>::Iterator it = s.begin();
  // cout << boolalpha << it.is_null() << endl;
  // cout <<  *it << " " << s. << endl;
  cout << *it << "it" << endl << boolalpha  << it.is_null();
  cout << "Empty Check:" << boolalpha << s.empty() << endl;

  return true;
}

bool test_node(bool debug = false){
  if(debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }

  // node<int>* test = new node<int>(1);
  // node<int>* test = nullptr;
  // node<int>* b = nullptr;
  // _insert_before(test, b, 13);
  // _insert_after(test, b, 13);
  // for(int i = 10; i > 0; i--){
  //  _insert_head(test, i);
  // }  

//   // int size = 10;
//   // int a[size];
//   // // _array_init(a, size, -1);
//   // for(int i = 0; i < size; i++){
//   //   a[i] = i*10;
//   // }
//   // _print_array(a,size);
//   // cout << endl << _find(a, size, -1) << endl << _at(a, size, size) << endl;
//  _print_list(test);
//  _print_list_backwards(test);

//   node<int>* search = _search_list(test, 8);
//   cout << endl << search << "  "  << search->_item << endl;

//   _insert_after(test, search, 8008132);
//   _insert_after(test,test,800082);
//   _insert_before(test, search, 11111);
//   _insert_before (test, test, 2222);

//   _print_list(test);
//   _print_list_backwards(test);

//   node<char>* a = nullptr;
//   node<char>* b = nullptr;

//   _insert_after(a, a, 'a');
//   _insert_before(b,b,'b');
//   _print_list(a);
//   _print_list(b);

//   cout << *_previous_node(search) << endl;

//   cout << _delete_node(test, search) << endl;
  
//   _print_list(test);

//   node<int>* copied =  _copy_list(test);
//   _print_list_backwards(copied);
  
//   node<int>* c  = nullptr;
//   node<int>* d =  _copy_list(c, test);

//   cout  << d << ' ' << *d << endl;
//   _print_list(c);
  // node<int>* empty_test =  nullptr;
  // _clear_list(empty_test);
  // _clear_list(test);
  // cout  << *test << endl;
  // _print_list(test);
  // _print_list(empty_test);
//   cout << _at(test, 3);
//   // _print_list(c);

   return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_STUB, TestStack){
    
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stack(true));
}

TEST(TEST_STUB, TestNode){
    
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_node(true));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

