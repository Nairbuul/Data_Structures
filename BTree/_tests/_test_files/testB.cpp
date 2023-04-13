#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

#include "../../includes/btree/btree.h"

using namespace std;

void line(){
  cout << "========================================================" << endl;
}

template<typename T>
void print_array(T ra[], int size){
  for(int i = 0; i < size; i++){
    cout << ra[i] << " "; 
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

bool test_fix_excess(bool debug = false){
  return true;
  cout << endl << endl << endl;
  //comment out fix_shortage

  BTree<int> bt;
  for(int i = 0; i < 5; i++){
    bt.insert((i+1)*10);
  }
  cout << bt << endl;
  line();

  cout <<"Removing: 30 " << endl;
  bt.remove(30);
  cout << bt << endl;
  line();

  cout << "Merge with right: " << endl;
  bt.merge_with_next_subset(1);
  cout << bt << endl;
  line();

  cout << "insert 30: " << endl;
  bt.insert(30);
  cout << bt << endl;
  line();
 
  // int capsule;
  // // bt.remove_biggest(capsule);
  // cout << "Removing biggest: " << capsule << endl;
  cout << "removing: 50" << endl;
  bt.remove(50);
  cout << bt << endl;
  line();

  cout << "Merge with left: " << endl;
  bt.merge_with_next_subset(2);
  cout << bt << endl;
  line();

  cout << "Inserting: 50,60" << endl;
  bt.insert(50);
  bt.insert(60);
  cout << bt << endl;
  line();

  cout << "Removing: 30 "<< endl;
  bt.remove(30); 
  cout << bt << endl;
  line();

  cout << "rotate_left(borrow from right): " << endl;
  bt.rotate_left(1);
  cout << bt << endl;
  line();

  cout << "reseting tree for rotate_right (borrow from left): " << endl;
  bt.clear_tree();
  for(int i = 0 ; i < 5; i++){
    bt.insert((i+1)*10);
  }
  bt.insert(5);
  cout << bt << endl;
  line();

  cout << "Removing: 30" << endl;
  bt.remove(30);
  cout << bt << endl;
  line();

  cout << "Rotate right: " << endl;
  bt.rotate_right(1);
  cout << bt << endl;
  line();

  cout << "merge into root: " << endl;
  bt.clear_tree();
  bt.insert(10);
  bt.insert(20);
  bt.insert(30);
  cout << bt << endl; 
  line();

  bt.remove(30);
  cout << bt << endl;
  line();

  cout << "merging: " << endl;
  bt.merge_with_next_subset(1);
  cout << bt << endl;
  line();

  cout << endl << endl << endl;
  return true;
}

// bool test_emmanual_btree(bool debug = false)
// {
//   if (debug){
//     cout << "" << endl;
//   }
//   return true;
//   BTree<int> bt;

//   bt.data[0] = 50;
//   bt.data[1] = 100;
//   bt.data_count = 2;
//   bt.child_count = 3;
//   bt.subset[0] = new BTree<int>();
//   bt.subset[0]->data_count = 2;
//   bt.subset[0]->child_count = 3;
//   bt.subset[0]->data[0] = 30;
//   bt.subset[0]->data[1] = 40;
//   bt.subset[0]->subset[0] = new BTree<int>();
//   bt.subset[0]->subset[0]->data[0]= 10;
//   bt.subset[0]->subset[0]->data_count = 1;
//   bt.subset[0]->subset[0]->child_count = 0;
//   bt.subset[0]->subset[1] = new BTree<int>();
//   bt.subset[0]->subset[1]->data[0] = 35;
//   bt.subset[0]->subset[1]->data_count = 1;
//   bt.subset[0]->subset[1]->child_count = 0;
//   bt.subset[0]->subset[2] = new BTree<int>();
//   bt.subset[0]->subset[2]->data[0] = 45;
//   bt.subset[0]->subset[2]->data_count = 1;
//   bt.subset[0]->subset[2]->child_count = 0;


//   bt.subset[1] = new BTree<int>();
//   bt.subset[1]->data_count = 2;
//   bt.subset[1]->child_count = 0;
//   bt.subset[1]->data[0] = 60;
//   bt.subset[1]->data[1] = 70;

//   bt.subset[2] = new BTree<int>();
//   bt.subset[2]->data_count = 2;
//   bt.subset[2]->child_count = 0;
//   bt.subset[2]->data[0] = 110;
//   bt.subset[2]->data[1] = 120;
//   string a  = bt.in_order();
//   cout << a << endl << endl;
//   cout << bt << endl;
//   // cout << endl;
//   // bt.get(35);
//   // int* here = bt.find(35);
//   // cout << *here;
//   // cout << endl;


//   return true;
// }

bool interactive_buildBTree(bool debug = false){
  // return true;
  char user_input;
  int num;
  BTree<int> copy;
  BTree<int> bt;
  while(toupper(user_input) != 'X'){
    cin >> user_input;
    switch(toupper(user_input)){
      case 'I':{
        cin >> num;
        bt.insert(num);
        cout << bt << endl;
        cout << "BT data_count: " << bt.data_count << "\tBT child_count: " << bt.child_count << endl; 
        line();
        break;
      }
      case 'C':{
        //copy
        copy = bt;
        cout << "COPIED" << endl << copy << endl;
        line();
        break;
      }
      case 'G':{
        cin >> num;
        cout << "gotted num :] " << bt.get(num) << endl; 
      }
      case 'R':{
        cin >> num;
        cout << "removing: " <<  num  << endl;
        bt.remove(num);
        cout << bt << endl;
        cout << "BT data_count: " << bt.data_count << "\tBT child_count: " << bt.child_count << endl;
        line();
        break;
      }
      case 'L':{
        cout << "Removing Largest";
        cin >> num;
        bt.remove_biggest(num);
        break;
      }
      case 'D':{
        cout << "Deleteing Tree" << endl;
        bt.clear_tree();
        cout << "Deleted Tree: \n" << bt << endl;
        line();
        break;
      }
      case '}':{
        cin >> num;
        cout << "rotate_right: " << num << endl;
        bt.rotate_right(num);
        cout << bt << endl;
        cout << "BT data_count: " << bt.data_count << "\tBT child_count: " << bt.child_count << endl;
        line();
        break;
      }
      case '{':{
        cin >> num;
        cout << "rotate_left: " << num << endl;
        bt.rotate_left(num);
        cout << bt << endl;
        cout << "BT data_count: " << bt.data_count << "\tBT child_count: " << bt.child_count << endl;
        line();
        break;
      }
      case 'M':{
        cin >> num;
        cout << "merge at subset: " << num << endl;
        bt.merge_with_next_subset(num);
        cout << bt << endl;
        cout << "BT data_count: " << bt.data_count << "\tBT child_count: " << bt.child_count << endl;
        line();
        break;
       }
       case '-':{
        cout << "Shrinking: " << endl;
        BTree<int>* shrink = bt.subset[0];
        copy_array(bt.data, shrink->data, bt.data_count, shrink->data_count);
        copy_array(bt.subset, shrink->subset, bt.child_count, shrink->child_count);
        shrink->child_count = 0;
        shrink->data_count = 0;
        delete shrink; 
        cout << bt << endl;
        cout << "BT data_count: " << bt.data_count << "\tBT child_count: " << bt.child_count << endl;
        line();
        break;
       }
    }
  }
  return true;
}

// bool test_fix_excess(bool debug = false){
//   //was just a bunch of cout statements.
//   if(debug == false){
//     return true;
//   }
//   BTree<int> bt;
//   for(int i = 0; i < 7; i++){
//     bt.insert((i+1)*100);
//     cout << bt << endl;
//     line();
//   }

//   return true;
// }

// bool test_rotate(bool debug = false){
//   BTree<int> bt;
//   for(int i = 0; i < 3; i++){
//     bt.insert((i+1)*300);
//   }
//   //merge left.
//   // int capsule;
//   // bt.remove_biggest(capsule);
//   // bt.merge_with_next_subset(0);
//   bt.remove(300);
//   cout << bt.child_count << endl;
//   cout << bt << endl;
//   return true;
// }

// bool Test_BTree(bool debug = false){
//   return true;
//   BTree<int> bt;
//   //BT all function calls to test for make error
//   // int array[10] = {1,2};
//   // int* ptr = array;
//   // BTree<int> btwo(ptr, 2, false);
//   // cout << btwo;
//   // BTree<int> copy(btwo);
//   // cout << "Copied BTree: " << endl << copy << endl;
//   // BTree<int> copy2(btwo);
//   // cout << "Copied2 BTree: " << endl << copy << endl;
//   // cout << boolalpha << btwo.contains(2) << endl;
//   // return true;

//   //Loose remove
//   // bt.insert(30);
//   // bt.insert(40);
//   // bt.insert(50);
//   // bt.insert(20);
//   // bt.insert(35);
//   // cout << bt << endl;
//   // line();
//   // bt.loose_remove(30);



//   //Merge
//   // bt.insert(100);
//   // bt.insert(50);
//   // bt.insert(75);
//   // bt.insert(40);
//   // bt.insert(65);
//   // bt.insert(25);
//   // bt.insert(65);
//   // cout << bt << endl; 
//   // line();
//   // bt.remove(50);
//   // bt.rotate_right(1);

//   // bt.remove_biggest(bt.get(100));
//   // bt.remove(50);
//   // cout << bt << endl; 
//   // line();
//   // bt.rotate_right(0);
//   // cout << bt.data[0] << "\t" << bt.data[1] << endl;
//   // bt.merge_with_next_subset(1);
//   // bt.rotate_left(1);
//   // bt.child_count = 0;
//   // bt.merge_with_next_subset(1);

//   // bt.merge_with_next_subset(2);
//   // bt.rotate_left(i)
//   // bt.rotate_right(1);
//   // cout << "MERGE LEFT: removed(100) " << endl << bt << endl; 
//   // line();
//   // cout << "merge right: removed(25) "  << endl;
//   // bt.clear_tree();
//   // bt.insert(100);
//   // bt.insert(65);
//   // bt.insert(70);
//   // bt.insert(50);
//   // bt.insert(50);
//   // bt.insert(25);
//   // bt.remove(25);
//   // bt.merge_with_next_subset(0);
//   // cout << bt << endl;
//   // line();
//   // cout << "rotate_right(): " << endl;
//   // cout << bt.data_count << endl;
//   // bt.remove(100);
//   // cout << bt.data_count << endl;
//   // bt.rotate_left(0);
//   // cout << bt.data_count << '\t' << bt.child_count << endl;
//   // cout << bt.subset[0]->data_count << '\t' << bt.subset[1]->data_count << endl;

//   //REMOVE BIGGEST
//   // bt.insert(100);
//   // bt.insert(200);
//   // bt.insert(300);
//   // bt.insert(150);
//   // bt.insert(50);
//   // bt.insert(125);
//   // bt.insert(175);
//   // bt.insert(250);
//   // bt.insert(225);
//   // bt.insert(75);
//   // bt.insert(25);
//   // int v = 150;
//   // bt.remove_biggest(bt.get(150));


//   // bt.insert(50);
//   // bt.insert(150);
//   // bt.insert(100);
//   // bt.insert(60);
//   // bt.insert(90);
//   // bt.insert(85);
//   // cout << bt << endl;
//   // line();
//   // bt.insert(86);
//   // int* test = bt.find(50);
//   // *test = 1;
//   // cout << bt << endl;
//   // line();
//   //        GOAL
//   //---------------------
//   //       86
//   //   60        100
//   // 50  85    90    160
//   //---------------------
//   //      
//   //    60    86    100 
//   // 50    85     90    150
//   //---------------------
//   //  
//   //    60        100
//   // 50   85 86 90   150
//   //---------------------

//   // bt.insert(30);
//   // cout << bt.child_count << endl;
//   // bt.insert(45);
//   // bt.insert(25);
//   // bt.insert(100);
//   // bt.insert(7);
//   // cout << bt.child_count << endl;
//   // bt.insert(9);
//   // bt.insert(8);
//   // line();
//   // cout << bt.data[0] << endl;
//   // cout << bt.data[1] << endl;
//   // cout << bt.data[2] << endl;
//   // cout << bt.child_count << " " <<  bt.data_count << endl;

//   // for(int i = 0; i < bt.child_count; i++){
//   //   cout << i << '\t';
//   //   cout << bt.subset[i]->data_count << '\t' << bt.subset[i]->child_count << endl;
//   // }
//   // cout << bt.subset[0]->subset[0]->data_count << endl;
//   // cout << bt.subset[0]->subset[1]->data_count << endl;
//   // cout << bt.subset[0]->subset[0]->child_count << endl;
//   // cout << bt.subset[0]->subset[1]->child_count << endl;
//   // cout << bt << endl;
//   // BTree<int> a(bt);
//   // line();
//   // a.clear_tree();
//   // cout << a << endl;
//   // cout << *bt.subset[1];

//   // for(int i = 0; i < a.child_count; i++){
//   //   cout << i << '\t' << a.subset[i]->data_count << '\t' << a.subset[i]->child_count << endl;
//   // }
  
//   // cout << a << endl;

//   // cout << a.subset[0]->data[0];
//   // cout << endl << a.subset[0]->data_count;
//   // cout << a << endl;


//   //split test
//   // int array1[100] = {1,2,3,4,5,6,7,8,9,10};
//   // int array2[100];
//   // int size1 = 5;
//   // int size2 = 0;
//   // split(array1, size1, array2, size2);

//   // print_array(array1, size1);
//   // print_array(array2, size2);
//   // cout << size1 << '\t' <<  size2 << endl;

//   // bt.insert(50);
//   // bt.insert(30);
//   // bt.insert(65);
  
//   // cout << boolalpha << bt.contains(70) << endl;
//   // cout << boolalpha << bt.contains(50) << endl;

//   // bt.insert(70);
//   // bt.insert(40);
//   // bt.insert(35);

//   // line();


//   // cout << bt << endl;
//   // string a = bt.in_order();
//   // cout << a << "  yes" << endl;



//   return true;
// }

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_FIX_EXCESS, TestFixExcess){
  bool success = test_fix_excess(false);
  EXPECT_EQ(success, true);
}

// TEST(TEST_ROTATE, TestRotate){
//   bool success = test_rotate(false);
//   EXPECT_EQ(success, true);
// }

// TEST(TEST_FIX_EXCESS, TestFixExcess){
//   bool success = test_fix_excess(false);
//   EXPECT_EQ(success, true);
// }

TEST(TEST_INTERACTIVE_BUILDBTREE, TestInteractiveBuildBTree){
  bool success = interactive_buildBTree(false);
  EXPECT_EQ(success, true);
}

// TEST(TEST_EMMANUAL_BTREE, TestEmmanualBtree){

//   bool success = test_emmanual_btree(false);

//   EXPECT_EQ(success, true);
// }

// TEST(TEST_BTREE, TestBTree){
//   bool success = Test_BTree(false);
//   EXPECT_EQ(success, true); 
// }



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

