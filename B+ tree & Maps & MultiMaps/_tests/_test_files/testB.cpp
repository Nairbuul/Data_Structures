#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>

using namespace std;

#include "../../includes/bplustree/bplustree.h"
#include "../../includes/bplustree/map.h"
#include "../../includes/bplustree/multimap.h"

void line(){
  for(int i = 0; i < 15; i++){
    cout << "===";
  }
  cout << endl;
}

void break_BPT(){
  BPlusTree<int> bpt;
  for(int i = 0; i < 3; i++){
    bpt.get(i);
    // bpt.insert(i);
  }
  bpt.clear_tree();
}

void break_map(){
  Map<string, int> m;
  for(int i =0; i < 3; i++){
    cout << i << " ";
    m.insert(to_string(i), i);
  }
  cout << "end of loop" << endl;
  cout << m << endl;
  m.clear();
  line();
}

Map<int, string> mapzinzert(Map<int, string> _m, int keys, string values){
  for(int i = 0; i < 3; i++){
    _m.insert(keys+i, values += to_string(i+keys));
  }
  return _m;
}

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}


bool insertBPT(bool debug = false){
  cout << "testing insert: " << endl;  
  
  // return true;

  BPlusTree<int> BPT; 

  BPT.insert(0);
  BPT.insert(1);
  BPT.insert(2);
  cout << BPT << endl;

  return true;
}

bool manualBPlusTree(bool debug = false){
  cout << endl << endl << endl;
  cout << "Testing manual BPlusTree" << endl;
  
  // return true;

  //Find function.
  BPlusTree<int> bpt;
  //root
  bpt.data[0] = 13;
  bpt.data_count = 1;
  bpt.child_count =2;

  bpt.subset[0] = new BPlusTree<int>();
  bpt.subset[1] = new BPlusTree<int>();

  //left
  bpt.subset[0]->data[0]= 10;
  bpt.subset[0]->data_count = 1;
  bpt.subset[0]->child_count = 0;

  //right
  bpt.subset[1]->data[0] = 14;
  bpt.subset[1]->data_count = 1;
  bpt.subset[1]->child_count = 0;

  //Search 
  const int t = bpt.contains(14);
  //will error out (segmentation fault) if derefencing a nullptr.

  // cout << "find_ptr(pointer find): " << bpt.find_ptr(14) << '\t' << *bpt.find_ptr(14) << endl;
  // cout << "find_ptr(iterator find): " << *bpt.find(10) << endl;
  // cout << "contains: " << boolalpha << bpt.contains(4) << endl;
  // cout << "get: " << bpt.get(4) << endl; 
  // cout << "contains: " << boolalpha << bpt.contains(4) << endl;
  // cout << bpt << endl;
  // line();

  // cout << "find_ptr(pointer find): " << bpt.find_ptr(0) << endl;
  // cout << "find_ptr(iterator find): " << *bpt.find(0) << endl;

  cout << endl << endl << endl;
  return true;
}
bool BPTIterator(bool debug = false){
  cout << "BPTITERATOR+++ " << endl<< endl<< endl<< endl;

  BPlusTree<int> bpt;
  //altering size to slowly build tree to see if it's valid.
  int size = 7;

  for(int i = 0; i < size; i++){
    bpt.insert((i+1)*10);
  }
  cout << bpt << endl;

  cout << "Iterator Print: " << endl;
  line();
  //Manual increment..
  //================================================
  // BPlusTree<int>::Iterator it = bpt.begin(); 
  // for(int i = 0; i < size; i++){
  //   cout << "Iterator: "  << i << " ";
  //   cout << *it << endl;
  //   it++;
  // }
  //   cout << __LINE__ << endl;

  // Iterator loop (it++)
  // ================================================
  int i = 0;
  for(BPlusTree<int>::Iterator it = bpt.begin(); it != bpt.end(); it++){
    cout << "Iterator: " << i << " " << *it << endl;
    i++;
  }
  cout << endl << endl << endl;

  //Iterator loop (++it)
  //================================================
  // int i = 0;
  // for(BPlusTree<int>::Iterator it = bpt.begin(); it != bpt.end(); ++it){
  //   cout << "Iterator: " << i << " " << *it << endl;
  //   i++;
  // }
  cout << endl << endl << endl;

  //Testing orders: 
  cout << "In_Order: " << bpt.in_order() << endl;
  cout << "Pre_Order: " << bpt.pre_order() << endl;
  cout << "Post_Order: " << bpt.post_order() << endl;
  cout << endl << endl << endl;

  cout << "get: 20 " << bpt.get(20) << endl;
  cout << "get: 25 " << bpt.get(25) << endl;

  cout << bpt << endl;
  line();

  return true;
}

bool interactiveBPT(bool debug = false){
  if(debug){
    char user_input;
    int num;
    BPlusTree<int> bpt;
    BPlusTree<int>::Iterator it = bpt.begin();
    cout << "X(close), I(insert), D(clear), E(empty), S(get_smallest),\nA(get_smallest_node), 1(in_order)" << endl;
    while(toupper(user_input) != 'X'){
      cin >> user_input;
      switch(toupper(user_input)){
        case 'I':{
          cin >> num;
          cout << endl << "Inserting: " << num << endl;
          bpt.insert(num);
          cout << bpt << endl;
          cout << "BPT data_count: " << bpt.data_count << "\tBPT child_count: " << bpt.child_count << endl; 
          break;
        }
        case 'D':{
          cout << "Clearing Tree: " << endl;
          bpt.clear_tree();
          cout << bpt << endl;
          cout << "BPT data_count: " << bpt.data_count << "\tBPT child_count: " << bpt.child_count << endl;
          break;
        }
        case 'E':{
          if(bpt.empty()){
            cout << "EMPTY: "; 
            cout << "BPT data_count: " << bpt.data_count << "\tBPT child_count: " << bpt.child_count << endl;
          }
          else{
            cout << "NOT EMPTY: ";
            cout << "BPT data_count: " << bpt.data_count << "\tBPT child_count: " << bpt.child_count << endl;
          }
          break;
        }
        case 'S':{
          int smol; 
          bpt.get_smallest(smol); 
          cout << "Getting Smallest: \n" <<  "smoll: " << smol << endl;
            cout << "BPT data_count: " << bpt.data_count << "\tBPT child_count: " << bpt.child_count << endl;
          break;
        }
        case 'A':{
          cout << "Getting smallest node" << endl;
          BPlusTree<int>* temp = bpt.get_smallest_node();
          cout << *temp << endl;
          cout << "Smallest_node data_count: " <<temp->data_count << "\tBPT child_count: " << temp->child_count << endl;
          break;
        }
        case '1':{
          cout << bpt.in_order();
          break;
        }
        case 'U':{
          cin >> num;
          it = bpt.begin();
          it = bpt.upper_bound(num); 
          if(it != nullptr)
            cout << "Upper_bound: " << *it << endl;
          if(it == nullptr){
            cout << "NULL: setting back to beginning" << endl;
            it = bpt.begin();
          }
          break;
        }
        case 'L':{
          cin >> num;
          it = bpt.begin();
          it = bpt.lower_bound(num);
          if(it != nullptr)
            cout << "Lower_bound: " << *it << endl;
          if(it == nullptr){
            cout << "NULL setting back to beginning" << endl;
            it = bpt.begin();
          }
          break;
        }
        case '=':{
          cout << "iterator = begin" << endl;
          it = bpt.begin();
          cout << *it << endl;
          break;
        }
        case '+':{
          cout << "inc iterator: "<< endl;
          it++;
          if(it == nullptr){
            cout << "NULL setting back to beginning" << endl;
            it = bpt.begin();
          }
          else{
            cout << *it << endl;
          }
          break;
        }
        case 'C':{
          cout << "copying tree: " << endl;
          BPlusTree<int> copy(bpt);
          cout << copy << endl;
          break;
        }
        case '9':{
          cout << "size: " << bpt.size() << endl;
          break;
        }
        case 'V':{
          string inorder = bpt.in_order();
          cout << "in_order: " << inorder << endl;
          break;
        }
      }
      line();
    }
  }
  return true;
}

bool testMap(bool debug = false){
  cout<< "Testing map: " << endl << endl;
  //Pair Test:
  // Pair<string, int> a("a", 10);
  // Pair<string, int> b("b", 11);
  // Pair<string, int> c("c", 12);
  // Pair<string, int> d("d", 13);
  // Pair<string, int> e("e", 14);
  // Pair<string, int> f("f", 15);
  // Pair<string, int> g("g", 16);
  // Pair<string, int> h("h", 17);
  // Pair<string, int> i("i", 18);
  // Pair<string, int> j("j", 19);
  // Pair<string, int> k("k", 20);
  // Pair<string, int> l("l", 21);
  // Pair<string, int> m("m", 22);
  // a = b;
  // c = Pair<string, int>("assignment", 30);
  // cout << c << endl;

  // BPlusTree<Pair<string, int> > bpt;
  // bpt.insert(a);
  // bpt.insert(b);
  // bpt.insert(c);
  // bpt.insert(d);
  // cout << bpt << endl;

  // Map<string, int> insertion
  //===========================================
  // Map<string, int> map;
  // map.insert(string("a"), 1);
  // map.insert(string("b"), 2);
  // map.insert(string("c"), 3);
  // map.insert(string("d"), 4);
  // map.insert(string("e"), 5);
  // map.insert(string("f"), 6);
  // map.insert(string("g"), 7);
  // for(int i = 0; i < 100; i ++){
  //   map.insert(to_string(i), i);
  // }
  // cout << map << endl;
  // map.clear();
  // line();
  //===========================================

  //Map<string, int> []operator
  //===========================================
  Map<string, int> map;
  
  // map[string("a")] = 1;
  // map.insert(string("Z"), 26);
  // map[string("z")] = 23;
  // map[string("Z")] = 27;
  cout << map << endl;
  //===========================================


  // Map<int, double>
  // Map<int, double> map;
  // map.insert(10,10.5);
  // map.insert(11,11.5);
  // map.insert(12,12.5);
  // map.insert(13,13.5);
  // map.insert(14,14.5);
  // map.insert(15,15.5);
  // map.insert(16,16.5);
  // map.insert(17,17.5);
  // map.insert(18,18.5);
  // map.insert(19,19.5);
  // for(int i = 0 ; i < 100; i++){
  //   map.insert(i, i+0.5);
  // }
  // cout << map << endl;

  // Map<int, char[]> map;
  // vector<char> v_c; 
  // char p[4] = "abc";
  // map.insert(1,p[]);
  // cout << map << endl;


  
  /* ====================================
  BPlusTree<int> breakThis;
  for(int i = 0; i < 50000; i++){
    breakThis.insert(i);
  }
  cout << breakThis << endl;
  line();
  ==================================== */ 
 
  // Break BPT pt2:
  /* ====================================
  BPlusTree<int> bpt;
  for(int i = 0; i < 10000; i++){
    // bpt.get(i);
    cout << i << endl;
    break_BPT();
  }
  cout << bpt << endl;
  ==================================== */
 
  //Manual Map test
  //=============================================
  // BPlusTree<Pair<int, string> > bpt;
  // Pair<int, string> p(10, string("a"));
  // Pair<int, string> p1(11, string("b"));
  // if(p < p1){
  //   cout << "working" << endl;
  // }
  // bpt.insert(p);
  // cout << bpt << endl;
  // cout << bpt << endl;
  //=============================================


  // Map<int, string> m;
  // int keys[] = {10, 20, 42, 30, 69};
  // string values[] = {"first", "second", "third", "fourth", "fifth"};
  // for(int i = 0; i < 4; i++){
  //   m.insert(i, to_string(i));
  // }
  // cout << m << endl;

  //Manual map insertion
  //=============================================
  // m.insert(11, string("b"));
  // m.insert(12, string("c"));
  // m.insert(13, string("d"));
  // m.clear();
  // cout << m << endl;
  //=============================================

  //breaking map pt1:
  //erorr at 4th rep.
  // for(int i = 0; i < 4; i++){
  //   break_map();
  // }
  // cout << "not broken" << endl;

  /*
  break insert pt 2.
  for(int i = 0; i < 1000; i++){
    m.insert(i, to_string(i));
  }
  */
 //function that inserts three elements
 //call that function 50k times
  // m.insert(keys[0], values[1]);
  // cout << m << endl;
  // for(int i = 0; i < 3; i++){
  //   cout << "inserting: " << keys[i] << '\t' << values[i] << endl;
  //   m.insert(keys[i], values[i]);
  // }
  // cout << m << endl; 
  // line();

  //testing bracket operator
  // cout << "Testing Bracket Operator: " << endl;
  // m[30] = "altered";
  // cout << m << endl; 
  // line();
  // cout << "data_count: " <<  m.map.data_count << '\t' << "child_count: " << m.map.child_count << endl;

  // cout << endl << endl << "testing Iterator: " << endl << endl;
  // Map<int, string>::Iterator it = m.begin();
  // while(it != m.end()){
  //   cout << *it << endl;
  //   it++;
  // }
  // int x = 10;
  // it = m.upper_bound(x);
  // cout << "upper bounds: 10->" << *it << endl;
  // x+=1;
  // it = m.lower_bound(x);
  // cout << "lower bounds: 12-> " << *it << endl;
  // line();

  // cout << "testing [] operator:  " << endl;
  // Map<int, string> m2;
  // m2.insert(10, string("a"));
  // m2.insert(20, string("b"));
  // m2.insert(30, string("c"));

  // cout << m2 << endl;

  return true;
}

bool testMultiMap(bool debug = false){
  cout << "TESTING MULTIMAP: " << endl; line();
  int keys[] = {43, 20, 96, 100, 69};
  string values[] = {"430", "200", "960", "1000", "690"};

  MPair<int, string> mpair(43, string("43"));
  MMap<int, string> mm;
  mm[keys[0]] += values[0];
  mm[keys[0]] += values[1];
  mm[keys[0]] += values[2];
  for(int i = 0; i < 150; i++){
    mm[0] += i;
  }
  cout << mm << endl;

  return true;
}

bool bpt_traversal(bool debug = false){
  cout << "testing traversals" << endl;
  int a[] = {43, 20, 96, 100, 69};
  BPlusTree<int> bpt(a, 5);

  
  cout << bpt << endl;
  cout << "in_order:  \t" << bpt.in_order() << endl;
  cout << "pre_order: \t" << bpt.pre_order() << endl;
  cout << "post_order:\t" << bpt.post_order() << endl;

  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_INSERTBPT, TestInsertBPT){
  bool success = insertBPT(false);
  EXPECT_EQ(success, true);
}

TEST(TEST_MANUALBPLUSTREE, TestManualBPlusTree){
  bool success = manualBPlusTree(false);
  EXPECT_EQ(success, true);
}

TEST(TEST_BPTITERATOR, TestBPTIterator){
  bool success = BPTIterator(false);
  EXPECT_EQ(success, true);
}

TEST(TEST_INTERACTIVEBPT, TestInteractiveBPT){
  bool success = interactiveBPT(true);
  EXPECT_EQ(success,true);
}
TEST(TEST_MAP,  TestMap){
  bool success = testMap(false);
  EXPECT_EQ(success,true);
}
TEST(TEST_MULTI_MAP, TestMultiMap){
  bool success = testMultiMap(false);
  EXPECT_EQ(success,true);
}
TEST(TEST_BPT_TRAVERSAL, TestBptTraversal){
  bool s = bpt_traversal(false);
  EXPECT_EQ(s, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

