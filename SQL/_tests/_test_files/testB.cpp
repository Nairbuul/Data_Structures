#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include "../../includes/sql/sql.h"

using namespace std;

void print_postfix(Queue<Token*> a ){
  while(!a.empty()){
    cout << a.pop()->token_string() << endl;
  }
}

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}
bool test_phase_one(bool debug = false){
  // cout << "Phase one testing: " << endl;

  // string a = ("make table employee fields  last,       first,         dep,      salary, year");
  // ShuntingYard sy(a);
  // Queue<Token*> postfix = sy.postfix();
  // print_postfix(postfix);
  
  return true;
}

bool test_batch_file(bool debug = false){
  cout << "test_batch_file: " << endl;
  //INITIALIZATION
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  const vectorstr initialization = {
  /*00*/  "make table employee fields  last, 		      first, 			  dep,  		    salary, 	year",
  /*01*/   "insert into employee values Blow, 		    Joe, 			    CS,		 	      100000, 	2018",
  /*02*/   "insert into employee values Blow, 		    JoAnn,	      Physics, 	    200000, 	2016",
  /*03*/  "insert into employee values Johnson, 	    Jack, 			  HR, 		      150000, 	2014",
  /*04*/  "insert into employee values Johnson, 	    \"Jimmy\", 		Chemistry,	  140000, 	2018",
  /*05*/  "insert into employee values Yao,	 	        Jimmy, 			  Math,		      145000, 	2014",
  /*06*/  "insert into employee values \"Yao\", 	    Flo, 			    CS,			      147000, 	2012",
  /*07*/  "insert into employee values Yang, 		      Bo, 			    CS,			      160000, 	2013",
  /*08*/  "insert into employee values Jackson,	      \"Flo\", 			Math,		      165000, 	2017",
  /*09*/  "insert into employee values Jackson,	      Bo,	 			    Chemistry,	  130000, 	2011",
  /*10*/  "insert into employee values \"Jackson\",	  Billy, 			  Math,	 	      170000, 	2017",
  /*11*/  "insert into employee values Johnson,	      \"Mary Ann\", Math,		      165000, 	2014",
  /*12*/  "insert into employee values Johnson,	      \"Billy Bob\",Physics,	    142000, 	2014",
  /*13*/  "insert into employee values Johnson,	      Billy, 			  \"Phys Ed\",	102000, 	2014",
  /*14*/  "insert into employee values \"Van Gogh\",  Vincent, 		  Art,		      240000, 	2015",
  /*15*/  "insert into employee values \"Van Gogh\",  Vincent, 		  CS,			      245000, 	2015",
  /*16*/  "insert into employee values \"Van Gogh\",  \"Jim Bob\", 	\"Phys Ed\",	230000, 	2010",
  /*17*/  "select * from employee", 

/*18-00*/  "make table student  fields   fname,           lname,        major,              age, company",
/*19-01*/  "insert into student values   Flo, 			      Yao, 		      CS, 				        20, 	Google",
/*20-02*/  "insert into student values   Bo, 				      Yang, 		    CS, 				        28,		Microsoft",
/*21-03*/  "insert into student values   \"Sammuel L.\",  Jackson, 	    CS, 				        40,		Uber",
/*22-04*/  "insert into student values   \"Flo\", 			  \"Jackson\", 	Math,	 			        21,		Google",    
/*23-05*/  "insert into student values   \"Greg\", 			  \"Pearson\", 	Physics,		        20,		Amazon",
/*24-06*/  "insert into student values   \"Jim Bob\", 	  Smith, 		    Math,	 			        23,		Verizon",
/*25-07*/  "insert into student values    Calvin, 		    Woo, 		      Physics,		        22,		Uber",
/*26-08*/  "insert into student values   \"Anna Grace\",  \"Del Rio\", 	CS,	 				        22,		USAF",
/*27-09*/  "insert into student values   \"Teresa Mae\",  Gowers, 	    Chemistry,			    22,		Verizon",
/*28-10*/  "insert into student values   Alex,			      Smith,		    \"Gender Studies\", 53,		Amazon",
/*29-11*/  "select * from student",
  
  };

  SQL sql;
  cout << initialization.size() << endl;
  // for(int i = 0; i < initialization.size(); i++){
  cout << "INITIALIZATION TEST: !" << endl << endl;
  for(int i = 0; i < initialization.size(); i++){
    cout << i << "-initialization: " << initialization[i] << endl;
    sql.command(initialization[i]);
  }
  //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


  //****************************************************************************
  //		SIMPLE SELECT:
  //****************************************************************************
  const vectorstr simple_select = {
  /*00*/  "select * from student",
  /*01*/  "select * from student where lname = Jackson",
  /*02*/  "select * from student where major = CS",
  /*03*/  "select * from student where company = Uber",
  /*04*/  "select * from student where lname = \"Del Rio\"",
  /*05*/  "select * from student where fname = \"Jim Bob\"",
  /*06*/  "select * from student where fname = \"Anna Grace\"",
  /*07*/  "select * from student where fname = \"Teresa Mae\"",
  /*08*/  "select * from student where lname = \"Does Not Exist\"",
  };

  //00->00 
  //01->03 simple strings
  //04->07 quoted strings
  //08 non-existant string

  // cout << "SIMPLE SELECT TEST: " << endl << endl;
  // for(int i = 0; i < simple_select.size(); i++){
  //   cout << i << "-simple-select: " << simple_select[i] << endl;
  //   sql.command(simple_select[i]);
  // }

  //****************************************************************************
  //		RELATIONAL OPERATORS:
  //****************************************************************************

const vectorstr relational_operators = {
//.................
//:Greater Than   :
//.................
/*00*/"select * from student where lname > Yang",
/*01*/"select * from student where major > Math",
/*02*/"select * from student where fname > \"Sammuel L.\"",
/*03*/"select * from employee where salary > 200000",
/*04*/"select * from employee where dep > Chemistry",
/*05*/"select * from employee where last > Jackson",
/*06*/"select * from employee where first > \"Billy Bob\"",


//. . . . . . . . . . . . . (Greater Than: Non-existing) . . . . . . . . . . . . . . . . . . . . . 
/*08*/"select * from student where age > 50",
/*09*/"select * from student where age > 35",
/*10*/"select * from student where fname > T",
/*11*/"select * from employee where salary > 130000",
/*12*/"select * from employee where  year > 2009",

//. . . . . . . . . . . . . (Greater than: last item) . . . . . . . . . . . . . . . . . .
/*13*/"select * from student where age  > 53",
/*14*/"select * from student where lname > Yao",
/*15*/"select * from student where fname > \"Teresa Mae\"",
/*16*/"select * from employee where last > \"Van Gogh\"",
/*17*/"select * from employee where first > Vincent",
/*18*/"select * from employee where salary > 260000",

//. . . . . . . . . . . . . (Greater Than: Passed last item) . . . . . . . . . . . . . . . . . . . . . 
/*19*/"select * from student where age > 54",
/*20*/"select * from student where lname > Zoolander",
/*21*/"select * from employee where last > Zoolaner",
/*22*/"select * from employee where first > Xu",

//.................
//:Greater Equal  :
//.................
/*23*/"select * from student where lname >= Yang",
/*24*/"select * from student where fname >= \"Sammuel L.\"",
/*25*/"select * from student where age >= 40",
//. . . . . .  (Greater Equal non-existing: ) . . . . . . . . . . . 
/*26*/"select * from employee where last >= Jack",
/*27*/"select * from employee where first >= Bill",
/*28*/"select * from employee where salary >= 235000",


//.................
//:Less Than      :
//.................


//. . . . . . . . . . . . . (Less Than: Non-existing) . . . . . . . . . . . . . . . . . . . . . 
/*29*/"select * from student where lname < Jackson",
/*30*/"select * from student where major < Math",
/*31*/"select * from student where fname < \"Jim Bob\"",
/*32*/"select * from employee where salary < 200000",
/*33*/"select * from employee where dep < CS",
/*34*/"select * from employee where last < Jackson",
/*35*/"select * from employee where first < \"Billy Bob\"",

//. . . . . . . . . . . . . (Less than: first item) . . . . . . . . . . . . . . . . . .
/*36*/"select * from student where age  < 20",
/*37*/"select * from student where lname < \"Del Rio\"",
/*38*/"select * from student where fname < Alex",
/*39*/"select * from employee where last < Blow",
/*40*/"select * from employee where first < Billy",
/*41*/"select * from employee where salary < 100000",


//. . . . . . . . . . . . . (Less Than: before first item) . . . . . . . . . . . . . . . . . . . . . 

/*42*/"select * from student where age  < 19",
/*43*/"select * from student where lname < Adams",
/*44*/"select * from student where fname < Adam",
/*45*/"select * from employee where last < Alex",
/*46*/"select * from employee where first < Avory",
/*47*/"select * from employee where dep < Alchemy",


//.................
//:Less Equal     :
//.................
/*48*/"select * from student where lname <= Smith",
/*49*/"select * from student where fname <= Greg",
/*50*/"select * from student where age <= 40",

//. . . . . .  (Less Equal non-existing: ) . . . . . . . . . . . 
/*51*/"select * from employee where last <= Peach",
/*52*/"select * from employee where first <= Gary",
/*53*/"select * from employee where salary <= 23500",

};
    /*
    //Greater Thans---------------------
    0-6 Greater than
    8-12 Greater than non-existing
    13-18 Greater than last item
    19-22 Greater than passed last item
    23-28 Greater Equal
    --------------------------------------
    Less thans
    29-35 Less than non-existing
    36-41 Less than first item
    42-47 less than before first item
    48-50 Less equal
    51-53 less equal non-existing
    --------------------------------------
    */

   cout << "RELATIONAL_OPERATORS TEST: " << endl << endl;
    for(int i = 0; i < 53; i++){
      cout << i << "-relational_operators: " << relational_operators[i] << endl;
      sql.command(relational_operators[i]);
    }


const vectorstr logical{
//.................
//:AND            :
//.................

/*00*/"select * from student where fname = \"Flo\" and lname = \"Yao\"",
/*01*/"select * from student where major = \"CS\" and age < 25",
/*02*/"select * from student where major < Math and age > 25",
/*03*/"select * from employee where dep = CS and salary > 150000",
/*04*/"select * from employee where last = Jackson and year < 2015",
/*05*/"select * from employee where last = Johnson and year >=2014",


//.................
//:OR            :
//.................
/*06*/"select * from student where fname = Flo or lname = Jackson",
/*07*/"select * from student where age >=40  or company = Verizon",
/*08*/"select * from employee where first = Bo or last = Johnson",
/*09*/"select * from employee where year >= 2015 or dep = CS",


//.................
//:OR AND         :
//.................
/*10*/"select * from student where fname = Flo or major = CS and age <= 23",
/*11*/"select * from student where lname = Jackson or age < 23 and company > Uber",
/*12*/"select * from employee where last = \"Van Gogh\" or last = Jackson and salary >= 165000",


//.................
//:AND OR AND     :
//.................

/*13*/"select * from student where age <30 and major=CS or major = Physics and company = Amazon",
/*14*/"select * from student where age <=40 and company=Uber or major = CS and company = Google",
/*15*/"select * from employee where dep = CS and salary >= 160000 or year > 2014 and last = \"Van Gogh\"",


//.................
//:OR AND OR      :
//.................

/*16*/"select * from student where lname = Yang or major = CS and age < 23 or company = Google ",
/*17*/"select * from student where major = Physics or major = Math and company = Google or lname = Jackson",
/*18*/"select * from employee where dep = CS or year >2014 and year < 2018 or salary >= 265000",
};

  // cout << "LOGIC-O-TEST: " << endl << endl;
  // for(int i = 0; i < 19; i++){
  //   cout << i << "-Logic-o tes:" << logical[i] << endl;
  //   sql.command(logical[i]);
  // }



  return true;
}


bool test_batch_file2(bool debug = false){
  // cout << "tbf2 " << endl;
  // SQL("_!select.txt");
  // SQL("_!sample.txt");
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}
TEST(TEST_PHASE_ONE, TestPhaseOne){
  bool s = test_phase_one(false);
  EXPECT_EQ(s, true);
}
TEST(TEST_BATCH_FILE, TestBatchFile){
  bool s = test_batch_file(false);
  EXPECT_EQ(s, true);
}
// TEST(TEST_BATCH_FILE2, TestBatchFile2){
//   bool s = test_batch_file2(false);
//   EXPECT_EQ(s, true);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

