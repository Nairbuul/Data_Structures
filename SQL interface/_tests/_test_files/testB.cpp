#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "../../includes/table/table.h"
#include "../../includes/tokenizer/stokenize.h"

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_phase_zero(bool debug = false){
  
  cout << endl << "Phase 0: testing..." << endl << endl;
  //Goal: 1.) - Open a text file (Create if it does not already exist)
  //      2.) - Write into it.
  //      3.) - Close it.

  // vector<string> test = {"Brian", "Luu", "42"};
  // Table make_table("testing", test);
  //Check to see if file is opened/created ("testing._fields.txt") (✓)!
  //Check to see if file has ben written in. (✓)!


  //check to see if we can add more to the text file. (✓)!
  // vector<string> test2 = {"Dexter", "Dog", "10"};
  // make_table.insert_into(test2);

  //Check to see if we can now read the things in it. (✓)!
  // make_table.select_all();

  return true;
}

bool test_phase_one(bool debug = false){
  cout << "Table - phase_one: " << endl;

  // fstream f;
  // //reset the file: use this for new files
  // open_fileRW(f, "record_list.bin");

  // FileRecord r;
  // int recno=-1;
  // vector<string> v;

  // v = vector<string>({"Joe Zero", "000"});
  // r = FileRecord(v); //filling the envelop
  // recno = r.write(f);
  // cout<<"wrote into record: "<<recno<<endl;
  // f.close();

  // cout << "line " << endl;
  // FileRecord r2;
  // //open the file for reading and writing.
  // open_fileRW(f, "record_list.bin" );
  // int i = 0;
  // long bytes = r2.read(f, i); //empty envelop to be filled by the FileRecord object
  // while (bytes>0){
  //   cout<<"record "<<i<<": "<<r2<<endl;
  //   i++;
  //   bytes = r2.read(f, i);
  // }

  // vectorstr fields = {"fname", "lname", "age"};
  // Table t("short", fields);
  // vectorstr row = {"Brian", "Luu", "24"};  
  // vectorstr row1 = {"Dexter", "Dog", "11"};
  // vectorstr row2 = {"Deedee", "Dog", "7"};
  // vectorstr row3 = {"Joey", "Dog", "13"};
  // vectorstr row4 = {"b", "Luu", "42"};
  // t.insert_into(row);
  // t.insert_into(row1);
  // t.insert_into(row2);
  // t.insert_into(row3);
  // t.insert_into(row4);
  // t.select_all();

  // Table t1("short");
  // t.select({"lname, fname"}, "age", "<", "20");
  // cout << t.select_recnos();
  return true;
}

bool test_phase_two(bool debug = false){
  cout << "testing phase two: " << endl; 

  // Queue<Token*> p;
  // p.push(new Relational("a"));
  // cout << p. << endl;

  // make table employee fields  last, 		first, 			dep,  		salary, 	year
  vectorstr fields({"last", "first", "dep", "salary", "year"});

  Table test("employee", fields);
  // vectorstr rec1({"Blow", "Joe", "CS", "100000", 	"2018"});
  // test.insert_into(rec1);
  // cout << test << endl;

  // Relational a ("a");
  // cout << "A!!!!!!!!!!! " << a << endl;

  // char b[] = ("testing 123");
  // STokenizer stk(b);
  // Token t;
  // stk >> t; 
  // cout << t << endl;
  // Queue<Token*> qt;
  // qt.push(new Relational("=)"));
  // cout << *qt.pop() << endl;
  // string tes2t = (*qt.pop()).token_string();
  // cout <<  tes2t << endl;
  // if(tes2t == string("=)")){
  //   cout << "123123213" << endl;
  // }
  
  // Queue<Token *> post;
  // post.push(new TokenStr("lname"));
  // post.push(new TokenStr("Yao"));
  // post.push(new Relational("="));
  // Table selected = test.select({"lname", "age"}, post);
  // cout << "recnos from all the Yaos query: " << test.select_recnos() << endl;
  // cout << "all the Yaos: " << endl
  //    << selected << endl;

  return true;
}

void print_me(Queue<Token* > postfix){
  while(!postfix.empty()){
    Token* t = postfix.pop();
    cout << t->token_string() << " ";
  }
  cout << endl;
}

bool test_phase_three(bool debug =false){
  cout << "Testing Phase 3:" << endl;
  

  vectorstr condition1 = {"lname", "=", "Jackson"};
  vectorstr condition2 = {"fname", "=", "Flo", "or", "major", "=", "CS", "and", "age", "<=", "23"};
  vectorstr condition3 = {"fname", "=", "Flo", "and", "lname", "=", "Yao"};
  vectorstr condition4 = {"or", "and", "or", "and", "or", "and","and","and","or","or"};
  vectorstr condition5 = {"lname", "=", "Yao", "and", "age", "<=", "20"};
  //fname flo = major cs = or  age 23 <= and
  // ShuntingYard sy(condition1);
  // ShuntingYard sy(condition2);
  // ShuntingYard sy(condition3);
  // ShuntingYard sy(condition4);
  ShuntingYard sy(condition5);
  Queue<Token*> postfix = sy.postfix();
  print_me(postfix);


  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_PHASE_ZERO, TestPhaseZero){
  bool success = test_phase_zero(false);
  EXPECT_EQ(success, true);
}

TEST(TEST_PHASE_ONE, TestPhaseOne){
  bool s = test_phase_one(false);
  EXPECT_EQ(s, true);
}

TEST(TEST_PHASE_TWO, TestPhaseTwo){
  bool s = test_phase_two(false);
  EXPECT_EQ(s, true);
}

TEST(TEST_PHASE_THREE, TestPhaseThree){
  bool s = test_phase_three(false);
  EXPECT_EQ(s, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}