#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
using namespace std;

#include "../../includes/parser/parser.h"

void line(){
  cout << endl;
  for(int i = 0; i < 20; i++){
    cout << "===";
  }
  cout << endl;
}

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_STM(bool debug = false){
  cout << endl << "Testing STM: " << endl << endl;

  char test1[] = "Select * from students";
  char commands[] = "Select Insert Make";
  char fields[] = "select lname fname *";
  char where[] = "select lname fname age from student where age = 24";
  char make[] = "make table student fields first, age, major, class";
  char forward_slash[] = "insert into student values \"Sue Ellen\"";
  // char forward_slash[] = "insert into student values Jones,\"Sue Ellen\", 20, CS, Fr ";
  // string str;
  // char s[300];
  // str = "make table student fields last, first, age, major, class";
  // strcpy(s, str.c_str());
  Parser ptest2(forward_slash);
  mmap_ss c = ptest2.parse_tree();

  cout << c.contains("Sue Ellen") << endl;


  line();
  return true;
  // ptest2.set_string();
  return true;
  // ptest2.set_string(s);
  // line();
  // cout << "assignment operator" <<endl << a;
  // line();
  // ptest2.stokenizer();

  // vector<string> token_list;

  // STokenizer stk(test1);
  // Token t;

  // for(int i = 0; i < 7; i++){
  //   stk>>t;
  //   if(t.type() != TOKEN_SPACE)
  //     token_list.push_back(t.token_str());
  // }
  
  // for(int i = 0; i < token_list.size(); i++){
  //   cout << token_list[i] << endl;
  // }
  // cout << endl; line();  cout << endl;
    
  // Parser parse_test(token_list);
  // parse_test.output_loop();

  return true;
}


TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_STM, TestSTM){
  bool success = test_STM(false);
  EXPECT_EQ(success, 1);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

