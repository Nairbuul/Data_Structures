#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include"../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/node/node.h"
#include "../../includes/airport/simulation.h"

using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  Simulation test(debug);
  return  true; 
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

