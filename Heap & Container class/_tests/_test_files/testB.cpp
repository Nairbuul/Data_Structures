#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string>


using namespace std;

#include "../../includes/heap/heap.h"
#include "../../includes/heap/pqueue.h"

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }

  Heap<int> test; 
  for(int i = 0; i < 10; i ++ ){
    test.insert(i+rand()%10);
  }
  for(int i = 0; i < 10; i++){
    cout << test.remove() << endl;
  }
  
  // for(int j = 0; j < 100; j++){
  //   test.swap_with_parent(rand()%100);
  // }
  // cout << test << endl;

  // for(int k = 0; k < 100; k++){
  //   cout << test.remove() << endl;
  // }

  // cout << boolalpha << test.verify(0) << endl;
  // cout << test << endl;

  // PQueue<string> test; 

  // cout << test << endl;
  // cout << test.pop() << endl;

  // string a = "A:";
  // for(int i = 0; i < 100; i++){
  //   string b = "[";
  //   b += to_string(i);
  //   b += "]";
  //   a += b;
  //   test.push(a, i+rand()%100);
  //   a = "A:";
  // }
  // cout << test << endl;
  // cout << boolalpha << test.verify() << endl;

  // while(!test.is_empty()){
  //   cout << test.Pop_debug();
  //   cout << endl << "Heap: " << boolalpha << test.verify() << endl << endl;
  // }

  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
 