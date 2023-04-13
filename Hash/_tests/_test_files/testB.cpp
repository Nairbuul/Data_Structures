#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;

#include "../../includes/hash/chained_hash.h"
#include "../../includes/hash/open_hash.h"
#include "../../includes/hash/double_hash.h"
#include "../../includes/hash/constants.h"

int random(int low, int high){
  //call srand in main if you want better random numbers.
  return static_cast<int>(low + (rand() % static_cast<int>((high - low + 1))));
}

struct HashRecord{
    int _key;
    string _item;
    HashRecord(int key=-1, string item=""):_key(key), _item(item){}
    friend ostream& operator <<(ostream& outs, const HashRecord& h){
        cout << "[" << h._key << ":" << h._item << "]";
        return outs;
    }
    friend bool operator < (const HashRecord& left, const HashRecord& right){
        return left._key < right._key;
    }
    friend bool operator > (const HashRecord& left, const HashRecord& right){
        return left._key > right._key;
    }
    friend bool operator == (const HashRecord& left, const HashRecord& right){
        return left._key == right._key;
    }
    friend bool operator >= (const HashRecord& left, const HashRecord& right){
        return left._key >= right._key;
    }
    friend bool operator <= (const HashRecord& left, const HashRecord& right){
        return left._key <= right._key;
    }
};

string to_string(const HashRecord& h){
    return string(to_string(h._key) + " : " + h._item);
}

bool test_stub(bool debug = false){
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }

  return true;
}

bool test_doubleHash(bool debug = false){
  //SET CAPACITY = 19 BEFORE RUNNING.
  if(debug){
    cout << "test double hash:: test-sub() entering test_sub" << endl;

    DoubleHash<HashRecord> double_hash;

    //Calling every single functions to test for spelling errors/incorrect calls.
    //Make sure to comment out private before running. 
    /*
    cout << "Double_hash.insert(1): " << boolalpha 
         << double_hash.insert(HashRecord(1, string("1"))) << endl;
    cout << "Double Hash: is present: " << boolalpha << double_hash.is_present(1) << endl;
    HashRecord T;
    cout << "Double Hash: find: " << boolalpha << double_hash.find(1, T) << endl
         << "Double Hash: size: " << double_hash.size() << endl
         << "Double Hash: collisions: " << double_hash.collisions() << endl;
    cout << "Double Hash: Capacity: " << double_hash.capacity() << endl
         << "Double Hash: remove (1): " << boolalpha << double_hash.remove(1) << endl;
    cout << "Dobule_hash.insert(903): " << boolalpha 
         << double_hash.insert(HashRecord(903, string("903"))) << endl;
    cout << "Double Hash: Hash: " << double_hash.hash(903) << endl
         << "Double Hash: Hash2: " << double_hash.hash2(903) << endl
         << "Double_hash next_index: " << double_hash.next_index(0,903) << endl;
    int a = -1;
    cout << "Double_hash find_index: 903 " << boolalpha << double_hash.find_index(903, a) << endl
         << "DOuble_hash never_used (903): " << boolalpha << double_hash.never_used(double_hash.hash(903)) 
         << endl
         << "Double_hash never_used (0): " << boolalpha << double_hash.never_used(0) << endl;
    cout << "Dobule_hash is_vacant (903): " << boolalpha << double_hash.is_vacant(double_hash.hash(903)) 
         << endl
         << "Double_hash is_vacant(0): " << boolalpha <<  double_hash.is_vacant(0) << endl;
    */

    char user_input;
    int search;
    cout << "Double Hash test:\n" << "[R]andom [I]nsert [D]elete [S]earch [E]nd: " << endl; 
    while(toupper(user_input) != 'E'){
      cin >> user_input;
      switch(toupper(user_input)){
          case 'R':{
            int r = random(100,999);
            double_hash.insert(HashRecord(r, string("item")+to_string(r)));
            cout << double_hash << endl << "Double Hash test:\n" 
                 << "[R]andom [I]nsert [D]elete [S]earch [E]nd: "
                 << user_input << endl; 
            break;
          }
          case 'I':{
            cin >> search;
            double_hash.insert(HashRecord(search, string("item")+to_string(search)));
            cout << double_hash << endl << "Double Hash test:\n"
                 << "[R]andom [I]nsert [D]elete [S]earch [E]nd: "
                 << user_input << endl; 
            break;
          }
          case 'D':{
            cin >> search;
            double_hash.remove(search);
            cout << double_hash << endl << "Double Hash test:\n"
                 << "[R]andom [I]nsert [D]elete [S]earch [E]nd: "
                 << user_input << endl; 
            break;
          }
          case 'S':{
            cin >> search;
            if(double_hash.is_present(search)){
              cout << "true" << endl;
              break;
            }
            else{cout << "false" << endl; break;}
            break;
          }
          case 'E':{
            cout << "Exiting" << endl;
            break;
          }
      }
    }
  }
  return true;
}

bool test_openHash(bool debug = false){
  //SET CAPACITY = 19 BEFORE RUNNING.
 if(debug){
    cout << "test Open hash:: test-sub() entering test_sub" << endl;
  
    OpenHash<HashRecord> open_hash;
  
    //Calling every single functions to test for spelling errors/incorrect calls.
    //Make sure to comment out private before running. 
    /*
    cout << "open_hash.insert(1): " << boolalpha 
         << open_hash.insert(HashRecord(1, string("1"))) << endl;
    cout << "Open Hash: is present: " << boolalpha << open_hash.is_present(1) << endl;
    HashRecord T;
    cout << "Open Hash: find: " << boolalpha << open_hash.find(1, T) << endl
         << "Open Hash: size: " << open_hash.size() << endl
         << "Open Hash: collisions: " << open_hash.collisions() << endl;
    cout << "Open Hash: Capacity: " << open_hash.capacity() << endl
         << "Open Hash: remove (1): " << boolalpha << open_hash.remove(1) << endl;
    cout << "Dobule_hash.insert(903): " << boolalpha 
         << open_hash.insert(HashRecord(903, string("903"))) << endl;
    cout << "Open Hash: Hash: " << open_hash.hash(903) << endl 
         << "open_hash next_index: " << open_hash.next_index(0,903) << endl;
    int a = -1;
    cout << "open_hash find_index: 903 " << boolalpha << open_hash.find_index(903, a) << endl
         << "open_hash never_used (903): " << boolalpha << open_hash.never_used(open_hash.hash(903)) 
         << endl
         << "open_hash never_used (0): " << boolalpha << open_hash.never_used(0) << endl;
    cout << "Dobule_hash is_vacant (903): " << boolalpha << open_hash.is_vacant(open_hash.hash(903)) 
         << endl
         << "open_hash is_vacant(0): " << boolalpha <<  open_hash.is_vacant(0) << endl;
    */

    char user_input;
    int search;
    cout << "Open Hash test: \n" << "[R]andom [I]nsert [D]elete [S]earch [E]nd: " << endl; 
    while(toupper(user_input) != 'E'){
      cin >> user_input;
      switch(toupper(user_input)){
          case 'R':{
            int r = random(100,999);
            open_hash.insert(HashRecord(r, string("item")+to_string(r)));
            cout << open_hash << endl << "Open Hash test: \n"
                 << "[R]andom [I]nsert [D]elete [S]earch [E]nd: "
                 << user_input << endl; 
            break;
          }
          case 'I':{
            cin >> search;
            open_hash.insert(HashRecord(search, string("item")+to_string(search)));
            cout << open_hash << endl << "Open Hash test: \n"
                 << "[R]andom [I]nsert [D]elete [S]earch [E]nd: "
                 << user_input << endl; 
            break;
          }
          case 'D':{
            cin >> search;
            open_hash.remove(search);
            cout << open_hash << endl << "Open Hash test: \n"
                 << "[R]andom [I]nsert [D]elete [S]earch [E]nd: "
                 << user_input << endl; 
            break;
          }
          case 'S':{
            cin >> search;
            if(open_hash.is_present(search)){
              cout << "true" << endl;
              break;
            }
            else{cout << "false" << endl; break;}
            break;
          }
          case 'E':{
            cout << "Exiting" << endl;
            break;
          }
      }
    }
  }

  return true;
}

bool test_chainedHash(bool debug = false){
  //SET CAPACITY = 19 BEFORE RUNNING.
 if(debug){
    cout << "test Open hash:: test-sub() entering test_sub" << endl;
  
    ChainedHash<HashRecord> ChainedHash;
  
    cout << "insert: " <<  boolalpha << ChainedHash.insert(HashRecord(1, string("item__ 1"))) << endl;
    HashRecord T;
    cout << ChainedHash << endl;
    cout << "Find: " << boolalpha << ChainedHash.find(1, T) << endl;
    cout << "is_present: " << boolalpha << ChainedHash.is_present(1) << endl;
    cout << "remove: " << boolalpha <<  ChainedHash.remove(1) << endl;
    cout << "size: " << ChainedHash.size() << endl;
    cout << "capacity: " << ChainedHash.capacity() << endl;
    // exit(0);

    char user_input;
    int search;
    cout << "Chained Hash test: \n" << "[R]andom [I]nsert [D]elete [S]earch [E]nd: " << endl; 
    while(toupper(user_input) != 'E'){
      cin >> user_input;
      switch(toupper(user_input)){
          case 'R':{
            int r = random(100,999);
            ChainedHash.insert(HashRecord(r, string("item")+to_string(r)));
            cout << ChainedHash << endl << "Open Hash test: \n"
                 << "[R]andom [I]nsert [D]elete [S]earch [E]nd: "
                 << user_input << endl; 
            break;
          }
          case 'I':{
            cin >> search;
            ChainedHash.insert(HashRecord(search, string("item")+to_string(search)));
            cout << ChainedHash << endl << "Open Hash test: \n"
                 << "[R]andom [I]nsert [D]elete [S]earch [E]nd: "
                 << user_input << endl; 
            break;
          }
          case 'D':{
            cin >> search;
            ChainedHash.remove(search);
            cout << ChainedHash << endl << "Open Hash test: \n"
                 << "[R]andom [I]nsert [D]elete [S]earch [E]nd: "
                 << user_input << endl; 
            break;
          }
          case 'S':{
            cin >> search;
            if(ChainedHash.is_present(search)){
              cout << "true" << endl;
              break;
            }
            else{cout << "false" << endl; break;}
            break;
          }
          case 'E':{
            cout << "Exiting" << endl;
            break;
          }
      }
    }
  }

  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_DOUBLEHASH, Test_doubleHash){
  
  bool success = test_doubleHash(true); //Switch to true for interactive test.
  
  EXPECT_EQ(success, true);
}

TEST(TEST_OPENHASH, Test_openHash){
  
  bool success = test_openHash(false);
  
  EXPECT_EQ(success, true);
}

TEST(TEST_CHAINEDHASH, Test_chainedHash){
  
  bool success = test_chainedHash(false);
  
  EXPECT_EQ(success, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

