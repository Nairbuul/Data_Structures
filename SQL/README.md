
# Work Report

## Name: <ins> BRIAN LUU  </ins>

## Features:

- Not Implemented:
  - SQL batchfile constructor.

<br><br>

- Implemented:
  - Stack and Queue
  - Shunting Yards & RPN mixed into 1
  - FileRecord:(Class|: binary file read/write )
  - text file read/write function
  - Parser:(organizes commands,fields,values, and conditions)
  - String tokenizer (Breaks up strings into words/operators/etc... and stores them as a token)
  - Token: (defines strings)
  - Vector functions(append/grab repeats/delete repeats/ ostream/ append)

<br><br>

- Partly implemented:
  - what features have not been implemented

<br><br>

- Bugs
  - Known bugs

<br><br>

# Reflections:

- I'm so sorry about some of the code that I've written in this project. I hope at the very least it gives somebody a good laugh. Uh They're very specific, and maybe a little hackish, but I was scared if I stopped and planned out how to I would run out of time. So I kept on writing and when I got an issue ran back and threw duct tape at the problem hoping and praying that it doesn't spring up somewhere else. This project was a...  struggle mostly due to time. I think my time management could have been better. I did spend a lot of time just shooting in the dark and hoping that something will click for me. I do think that I could've asked more questions and been more proactive about it and it's something I'm genuinely working on. In retrospect now that the deadline has passed I do feel like my critical thinking and problemsolving skills have skyrocketed compared to 15 weeks ago. The three biggest takeaway that I'm taking from this class is 1.) Drawing and mapping out the steps is infinetly more efficent and it helps me really understand what I'm trying to write. 2.)I learned that for better or worse I can be really hardheaded when it tackling a problem and develop tunnel vision. And finally 3.) I think the biggest take away from this class is working with other people. When working with other people I get to see the many different perspective of how people approach a problem or break it down and I feel like that's something I can absorb and apply into my own projects. 
- Youtube link: https://youtu.be/8EUXCsovhX4

# **output**
<pre>
<br/><br/><br/><br/>
## Delete this line and paste the output of your basic test and then testB here
</pre>


<br/><br/>

# basic_test.cpp output:
<pre>
<br/><br/><br/><br/>
PS C:\Users\Luu_B\Desktop\CS 008\99_99_final_project-Nairbuul> ."C:/Users/Luu_B/Desktop/CS 008/99_99_final_project-Nairbuul/build/bin/basic_test.exe"


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from SQL_BASIC
[ RUN      ] SQL_BASIC.SQLBasic
>make table employee fields  last,       first,         dep,      salary, year
basic_test: table created.

>make table employee fields  last,       first,         dep,      salary, year
>insert into employee values Blow,       Joe,           CS,       100000, 2018
>insert into employee values Blow,       JoAnn,         Physics,  200000, 2016
>insert into employee values Johnson,    Jack,          HR,       150000, 2014
>insert into employee values Johnson,    "Jimmy",     Chemistry,140000, 2018
>make table student fields  fname,          lname,    major,    age
>insert into student values Flo,            Yao,        Art,    20
>insert into student values Bo,                      Yang,      CS,             28
>insert into student values "Sammuel L.", Jackson,      CS,             40
>insert into student values "Billy",         Jackson,   Math,   27
>insert into student values "Mary Ann",   Davis,        Math,   30



>select * from employee

Table name: employee_0, records: 4
    record                     last                    first                      dep                   salary                     year

         0                     Blow                      Joe                       CS                   100000                     2018
         1                     Blow                    JoAnn                  Physics                   200000                     2016
         2                  Johnson                     Jack                       HR                   150000                     2014
         3                  Johnson                    Jimmy                Chemistry                   140000                     2018


basic_test: records selected: 0 1 2 3

>select last, first, age from employee
basic_test: records selected:

>select last from employee

Table name: employee_0, records: 5
    record                     last

         0                     Blow                       Φ»                        ═
         1                     Blow                       Φ»                        ═
         2                     Blow                       Φ»                        ═
         3                  Johnson                       Φ»                        ═
         4                  Johnson                       Φ»                        ═


basic_test: records selected: 0 1 2 3 4

>select * from employee where last = Johnson

Table name: employee_0, records: 2
    record                     last                    first                      dep                   salary                     year

         0                  Johnson                     Jack                       HR                   150000                     2014
         1                  Johnson                    Jimmy                Chemistry                   140000                     2018


basic_test: records selected: 2 3

>select * from employee where last=Blow and major="JoAnn"

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year



basic_test: records selected:

>select * from student

Table name: student_0, records: 5
    record                    fname                    lname                    major                      age

         0                      Flo                      Yao                      Art                       20
         1                       Bo                     Yang                       CS                       28
         2               Sammuel L.                  Jackson                       CS                       40
         3                    Billy                  Jackson                     Math                       27
         4                 Mary Ann                    Davis                     Math                       30


basic_test: records selected: 0 1 2 3 4 

>select * from student where (major=CS or major=Art)

Table name: student_0, records: 3
    record                    fname                    lname                    major                      age

         0                       Bo                     Yang                       CS                       28
         1               Sammuel L.                  Jackson                       CS                       40
         2                      Flo                      Yao                      Art                       20


basic_test: records selected: 1 2 0

>select * from student where lname>J

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age

         0                       Bo                     Yang                       CS                       28                      ╪π»
         1                      Flo                      Yao                      Art                       20                      ╪π»


basic_test: records selected: 1 0

>select * from student where lname>J and (major=CS or major=Art)

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age

         0                       Bo                     Yang                       CS                       28
         1                      Flo                      Yao                      Art                       20


basic_test: records selected: 1 0
----- END TEST --------
[       OK ] SQL_BASIC.SQLBasic (409 ms)
[----------] 1 test from SQL_BASIC (409 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (410 ms total)
[  PASSED  ] 1 test.
PS C:\Users\Luu_B\Desktop\CS 008\99_99_final_project-Nairbuul>
</pre>
# testB.cpp output:
<pre>
<br/><br/><br/><br/>
PS C:\Users\Luu_B\Desktop\CS 008\99_99_final_project-Nairbuul\build\bin> ."C:/Users/Luu_B/Desktop/CS 008/99_99_final_project-Nairbuul/build/bin/testB.exe" 


----------running testB.cpp---------


[==========] Running 3 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 1 test from TEST_STUB
[ RUN      ] TEST_STUB.TestStub
[       OK ] TEST_STUB.TestStub (0 ms)
[----------] 1 test from TEST_STUB (1 ms total)

[----------] 1 test from TEST_PHASE_ONE
[ RUN      ] TEST_PHASE_ONE.TestPhaseOne
[       OK ] TEST_PHASE_ONE.TestPhaseOne (0 ms)
[----------] 1 test from TEST_PHASE_ONE (1 ms total)

[----------] 1 test from TEST_BATCH_FILE
[ RUN      ] TEST_BATCH_FILE.TestBatchFile
test_batch_file: 
30
INITIALIZATION TEST: !

0-initialization: make table employee fields  last,                   first,                      dep,                      salary,     year
1-initialization: insert into employee values Blow,                 Joe,                            CS,                       100000,   2018
2-initialization: insert into employee values Blow,                 JoAnn,            Physics,      200000,     2016
3-initialization: insert into employee values Johnson,      Jack,                         HR,                 150000,   2014
4-initialization: insert into employee values Johnson,      "Jimmy",            Chemistry,        140000,       2018
5-initialization: insert into employee values Yao,                      Jimmy,                    Math,               145000,   2014
6-initialization: insert into employee values "Yao",        Flo,                            CS,                       147000,   2012
7-initialization: insert into employee values Yang,                   Bo,                           CS,                       160000,   2013
8-initialization: insert into employee values Jackson,        "Flo",                    Math,                 165000,   2017
9-initialization: insert into employee values Jackson,        Bo,                                   Chemistry,    130000,       2011
10-initialization: insert into employee values "Jackson",         Billy,                          Math,               170000,   2017
11-initialization: insert into employee values Johnson,       "Mary Ann", Math,               165000,   2014
12-initialization: insert into employee values Johnson,       "Billy Bob",Physics,          142000,     2014
13-initialization: insert into employee values Johnson,       Billy,                      "Phys Ed",    102000,         2014
14-initialization: insert into employee values "Van Gogh",  Vincent,              Art,                240000,   2015
15-initialization: insert into employee values "Van Gogh",  Vincent,              CS,                         245000,   2015
16-initialization: insert into employee values "Van Gogh",  "Jim Bob",  "Phys Ed",      230000,         2010
17-initialization: select * from employee

Table name: employee_0, records: 16
    record                     last                    first                      dep                   salary                     year

         0                     Blow                      Joe                       CS                   100000                     2018
         1                     Blow                    JoAnn                  Physics                   200000                     2016
         2                  Johnson                     Jack                       HR                   150000                     2014
         3                  Johnson                    Jimmy                Chemistry                   140000                     2018
         4                      Yao                    Jimmy                     Math                   145000                     2014
         5                      Yao                      Flo                       CS                   147000                     2012
         6                     Yang                       Bo                       CS                   160000                     2013
         7                  Jackson                      Flo                     Math                   165000                     2017
         8                  Jackson                       Bo                Chemistry                   130000                     2011
         9                  Jackson                    Billy                     Math                   170000                     2017
        10                  Johnson                 Mary Ann                     Math                   165000                     2014
        11                  Johnson                Billy Bob                  Physics                   142000                     2014
        12                  Johnson                    Billy                  Phys Ed                   102000                     2014
        13                 Van Gogh                  Vincent                      Art                   240000                     2015
        14                 Van Gogh                  Vincent                       CS                   245000                     2015
        15                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010


18-initialization: make table student  fields   fname,           lname,        major,              age, company
19-initialization: insert into student values   Flo,                          Yao,                    CS,                                       20,     Google    
20-initialization: insert into student values   Bo,                                   Yang,                 CS,                                         28,      Microsoft
21-initialization: insert into student values   "Sammuel L.",  Jackson,             CS,                                         40,             Uber
22-initialization: insert into student values   "Flo",                    "Jackson",    Math,                                   21,             Google
23-initialization: insert into student values   "Greg",                           "Pearson",    Physics,                        20,             Amazon
24-initialization: insert into student values   "Jim Bob",        Smith,                    Math,                                       23,             Verizon
25-initialization: insert into student values    Calvin,                    Woo,                      Physics,                  22,             Uber
26-initialization: insert into student values   "Anna Grace",  "Del Rio",       CS,                                             22,             USAF
27-initialization: insert into student values   "Teresa Mae",  Gowers,      Chemistry,                      22,         Verizon
28-initialization: insert into student values   Alex,                         Smith,                "Gender Studies", 53,               Amazon
29-initialization: select * from student

Table name: student_0, records: 10
    record                    fname                    lname                    major                      age                  company

         0                      Flo                      Yao                       CS                       20                   Google
         1                       Bo                     Yang                       CS                       28                Microsoft
         2               Sammuel L.                  Jackson                       CS                       40                     Uber
         3                      Flo                  Jackson                     Math                       21                   Google
         4                     Greg                  Pearson                  Physics                       20                   Amazon
         5                  Jim Bob                    Smith                     Math                       23                  Verizon
         6                   Calvin                      Woo                  Physics                       22                     Uber
         7               Anna Grace                  Del Rio                       CS                       22                     USAF
         8               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
         9                     Alex                    Smith           Gender Studies                       53                   Amazon


SIMPLE SELECT TEST:

0-simple-select: select * from student

Table name: student_0, records: 10
    record                    fname                    lname                    major                      age                  company

         0                      Flo                      Yao                       CS                       20                   Google
         1                       Bo                     Yang                       CS                       28                Microsoft
         2               Sammuel L.                  Jackson                       CS                       40                     Uber
         3                      Flo                  Jackson                     Math                       21                   Google
         4                     Greg                  Pearson                  Physics                       20                   Amazon
         5                  Jim Bob                    Smith                     Math                       23                  Verizon
         6                   Calvin                      Woo                  Physics                       22                     Uber
         7               Anna Grace                  Del Rio                       CS                       22                     USAF
         8               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
         9                     Alex                    Smith           Gender Studies                       53                   Amazon


1-simple-select: select * from student where lname = Jackson

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age                  company

         0               Sammuel L.                  Jackson                       CS                       40                     Uber
         1                      Flo                  Jackson                     Math                       21                   Google


2-simple-select: select * from student where major = CS

Table name: student_0, records: 4
    record                    fname                    lname                    major                      age                  company

         0                      Flo                      Yao                       CS                       20                   Google
         1                       Bo                     Yang                       CS                       28                Microsoft
         2               Sammuel L.                  Jackson                       CS                       40                     Uber
         3               Anna Grace                  Del Rio                       CS                       22                     USAF


3-simple-select: select * from student where company = Uber

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age                  company

         0               Sammuel L.                  Jackson                       CS                       40                     Uber
         1                   Calvin                      Woo                  Physics                       22                     Uber


4-simple-select: select * from student where lname = "Del Rio"

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company

         0               Anna Grace                  Del Rio                       CS                       22                     USAF


5-simple-select: select * from student where fname = "Jim Bob"

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company

         0                  Jim Bob                    Smith                     Math                       23                  Verizon


6-simple-select: select * from student where fname = "Anna Grace"

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company

         0               Anna Grace                  Del Rio                       CS                       22                     USAF           ûB☺╠ûB☺╠ûB☺h┌░  
                  B☺╧┌░


7-simple-select: select * from student where fname = "Teresa Mae"

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company

         0               Teresa Mae                   Gowers                Chemistry                       22                  Verizon                   ûB☺h┌░


8-simple-select: select * from student where lname = "Does Not Exist"

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company



RELATIONAL_OPERATORS TEST:

0-relational_operators: select * from student where lname > Yang

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company



1-relational_operators: select * from student where major > Math

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age                  company

         0                     Greg                  Pearson                  Physics                       20                   Amazon
         1                   Calvin                      Woo                  Physics                       22                     Uber


2-relational_operators: select * from student where fname > "Sammuel L."

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company

         0               Teresa Mae                   Gowers                Chemistry                       22                  Verizon


3-relational_operators: select * from employee where salary > 200000

Table name: employee_0, records: 4
    record                     last                    first                      dep                   salary                     year

         0                     Blow                    JoAnn                  Physics                   200000                     2016
         1                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
         2                 Van Gogh                  Vincent                      Art                   240000                     2015
         3                 Van Gogh                  Vincent                       CS                   245000                     2015


4-relational_operators: select * from employee where dep > Chemistry

Table name: employee_0, records: 9
    record                     last                    first                      dep                   salary                     year

         0                  Johnson                     Jack                       HR                   150000                     2014
         1                      Yao                    Jimmy                     Math                   145000                     2014
         2                  Jackson                      Flo                     Math                   165000                     2017
         3                  Jackson                    Billy                     Math                   170000                     2017
         4                  Johnson                 Mary Ann                     Math                   165000                     2014
         5                  Johnson                    Billy                  Phys Ed                   102000                     2014
         6                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
         7                     Blow                    JoAnn                  Physics                   200000                     2016
         8                  Johnson                Billy Bob                  Physics                   142000                     2014


5-relational_operators: select * from employee where last > Jackson

Table name: employee_0, records: 6
    record                     last                    first                      dep                   salary                     year

         0                 Van Gogh                  Vincent                      Art                   240000                     2015           ♦∩oêÆBÅB☺ÿ┌░
         1                 Van Gogh                  Vincent                       CS                   245000                     2015           ♦∩oêÆBÅB☺ÿ┌░
         2                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010           ♦∩oêÆBÅB☺ÿ┌░
         3                     Yang                       Bo                       CS                   160000                     2013           ♦∩oêÆBÅB☺ÿ┌░    
         4                      Yao                    Jimmy                     Math                   145000                     2014           ♦∩oêÆBÅB☺ÿ┌░
         5                      Yao                      Flo                       CS                   147000                     2012           ♦∩oêÆBÅB☺ÿ┌░


6-relational_operators: select * from employee where first > "Billy Bob"

Table name: employee_0, records: 11
    record                     last                    first                      dep                   salary                     year

         0                      Yao                      Flo                       CS                   147000                     2012                   ÅB☺ÿ┌░
         1                  Jackson                      Flo                     Math                   165000                     2017                   ÅB☺ÿ┌░
         2                  Johnson                     Jack                       HR                   150000                     2014                   ÅB☺ÿ┌░
         3                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010                   ÅB☺ÿ┌░
         4                  Johnson                    Jimmy                Chemistry                   140000                     2018                   ÅB☺ÿ┌░
         5                      Yao                    Jimmy                     Math                   145000                     2014                   ÅB☺ÿ┌░
         6                     Blow                    JoAnn                  Physics                   200000                     2016                   ÅB☺ÿ┌░
         7                     Blow                      Joe                       CS                   100000                     2018                   ÅB☺ÿ┌░
         8                  Johnson                 Mary Ann                     Math                   165000                     2014                   ÅB☺ÿ┌░
         9                 Van Gogh                  Vincent                      Art                   240000                     2015                   ÅB☺ÿ┌░  
        10                 Van Gogh                  Vincent                       CS                   245000                     2015                   ÅB☺ÿ┌░


7-relational_operators: select * from student where age > 50

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company

         0                     Alex                    Smith           Gender Studies                       53                   Amazon             ~ΩoÉÆB☺►ÅB☺♠  


8-relational_operators: select * from student where age > 35

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age                  company

         0               Sammuel L.                  Jackson                       CS                       40                     Uber                     ÅB☺♠
         1                     Alex                    Smith           Gender Studies                       53                   Amazon                     ÅB☺♠


9-relational_operators: select * from student where fname > T

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company



10-relational_operators: select * from employee where salary > 130000

Table name: employee_0, records: 14
    record                     last                    first                      dep                   salary                     year

         0                  Jackson                       Bo                Chemistry                   130000                     2011                   &∞oÿ█░
         1                  Johnson                    Jimmy                Chemistry                   140000                     2018                   &∞oÿ█░
         2                  Johnson                Billy Bob                  Physics                   142000                     2014                   &∞oÿ█░
         3                      Yao                    Jimmy                     Math                   145000                     2014                   &∞oÿ█░
         4                      Yao                      Flo                       CS                   147000                     2012                   &∞oÿ█░
         5                  Johnson                     Jack                       HR                   150000                     2014                   &∞oÿ█░
         6                     Yang                       Bo                       CS                   160000                     2013                   &∞oÿ█░
         7                  Jackson                      Flo                     Math                   165000                     2017                   &∞oÿ█░
         8                  Johnson                 Mary Ann                     Math                   165000                     2014                   &∞oÿ█░  
         9                  Jackson                    Billy                     Math                   170000                     2017                   &∞oÿ█░
        10                     Blow                    JoAnn                  Physics                   200000                     2016                   &∞oÿ█░
        11                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010                   &∞oÿ█░
        12                 Van Gogh                  Vincent                      Art                   240000                     2015                   &∞oÿ█░
        13                 Van Gogh                  Vincent                       CS                   245000                     2015                   &∞oÿ█░


11-relational_operators: select * from employee where  year > 2009

Table name: employee_0, records: 16
    record                     last                    first                      dep                   salary                     year

         0                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010                   ÆB☺╪┌░
         1                  Jackson                       Bo                Chemistry                   130000                     2011                   ÆB☺╪┌░
         2                      Yao                      Flo                       CS                   147000                     2012                   ÆB☺╪┌░
         3                     Yang                       Bo                       CS                   160000                     2013                   ÆB☺╪┌░
         4                  Johnson                     Jack                       HR                   150000                     2014                   ÆB☺╪┌░
         5                      Yao                    Jimmy                     Math                   145000                     2014                   ÆB☺╪┌░
         6                  Johnson                 Mary Ann                     Math                   165000                     2014                   ÆB☺╪┌░
         7                  Johnson                Billy Bob                  Physics                   142000                     2014                   ÆB☺╪┌░  
         8                  Johnson                    Billy                  Phys Ed                   102000                     2014                   ÆB☺╪┌░
         9                 Van Gogh                  Vincent                      Art                   240000                     2015                   ÆB☺╪┌░
        10                 Van Gogh                  Vincent                       CS                   245000                     2015                   ÆB☺╪┌░
        11                     Blow                    JoAnn                  Physics                   200000                     2016                   ÆB☺╪┌░
        12                  Jackson                      Flo                     Math                   165000                     2017                   ÆB☺╪┌░
        13                  Jackson                    Billy                     Math                   170000                     2017                   ÆB☺╪┌░  
        14                     Blow                      Joe                       CS                   100000                     2018                   ÆB☺╪┌░
        15                  Johnson                    Jimmy                Chemistry                   140000                     2018                   ÆB☺╪┌░


12-relational_operators: select * from student where age  > 53

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company

         0                     Alex                    Smith           Gender Studies                       53                   Amazon               _φoûÆB☺╧┌░


13-relational_operators: select * from student where lname > Yao

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company



14-relational_operators: select * from student where fname > "Teresa Mae"

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company



15-relational_operators: select * from employee where last > "Van Gogh"

Table name: employee_0, records: 3
    record                     last                    first                      dep                   salary                     year

         0                     Yang                       Bo                       CS                   160000                     2013
         1                      Yao                    Jimmy                     Math                   145000                     2014
         2                      Yao                      Flo                       CS                   147000                     2012


16-relational_operators: select * from employee where first > Vincent

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year



17-relational_operators: select * from employee where salary > 260000

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year



18-relational_operators: select * from student where age > 54

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company



19-relational_operators: select * from student where lname > Zoolander

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company



20-relational_operators: select * from employee where last > Zoolaner

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year



21-relational_operators: select * from employee where first > Xu

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year



22-relational_operators: select * from student where lname >= Yang

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age                  company

         0                       Bo                     Yang                       CS                       28                Microsoft           ♦∩o►ÅB☺▬ÅB☺╪┌░
         1                      Flo                      Yao                       CS                       20                   Google           ♦∩o►ÅB☺▬ÅB☺╪┌░


23-relational_operators: select * from student where fname >= "Sammuel L."

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age                  company

         0               Sammuel L.                  Jackson                       CS                       40                     Uber
         1               Teresa Mae                   Gowers                Chemistry                       22                  Verizon


24-relational_operators: select * from student where age >= 40

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age                  company

         0               Sammuel L.                  Jackson                       CS                       40                     Uber             ÆB☺ÉÆB☺►ÅB☺♠
         1                     Alex                    Smith           Gender Studies                       53                   Amazon             ÆB☺ÉÆB☺►ÅB☺♠


25-relational_operators: select * from employee where last >= Jack

Table name: employee_0, records: 14
    record                     last                    first                      dep                   salary                     year

         0                  Jackson                      Flo                     Math                   165000                     2017                     ÅB☺♠
         1                  Jackson                       Bo                Chemistry                   130000                     2011                     ÅB☺♠
         2                  Jackson                    Billy                     Math                   170000                     2017                     ÅB☺♠
         3                  Johnson                     Jack                       HR                   150000                     2014                     ÅB☺♠
         4                  Johnson                    Jimmy                Chemistry                   140000                     2018                     ÅB☺♠
         5                  Johnson                 Mary Ann                     Math                   165000                     2014                     ÅB☺♠
         6                  Johnson                Billy Bob                  Physics                   142000                     2014                     ÅB☺♠  
         7                  Johnson                    Billy                  Phys Ed                   102000                     2014                     ÅB☺♠
         8                 Van Gogh                  Vincent                      Art                   240000                     2015                     ÅB☺♠
         9                 Van Gogh                  Vincent                       CS                   245000                     2015                     ÅB☺♠
        10                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010                     ÅB☺♠
        11                     Yang                       Bo                       CS                   160000                     2013                     ÅB☺♠
        12                      Yao                    Jimmy                     Math                   145000                     2014                     ÅB☺♠
        13                      Yao                      Flo                       CS                   147000                     2012                     ÅB☺♠  


26-relational_operators: select * from employee where first >= Bill

Table name: employee_0, records: 16
    record                     last                    first                      dep                   salary                     year

         0                  Jackson                    Billy                     Math                   170000                     2017
         1                  Johnson                    Billy                  Phys Ed                   102000                     2014
         2                  Johnson                Billy Bob                  Physics                   142000                     2014
         3                     Yang                       Bo                       CS                   160000                     2013
         4                  Jackson                       Bo                Chemistry                   130000                     2011
         5                      Yao                      Flo                       CS                   147000                     2012
         6                  Jackson                      Flo                     Math                   165000                     2017
         7                  Johnson                     Jack                       HR                   150000                     2014
         8                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
         9                  Johnson                    Jimmy                Chemistry                   140000                     2018
        10                      Yao                    Jimmy                     Math                   145000                     2014
        11                     Blow                    JoAnn                  Physics                   200000                     2016
        12                     Blow                      Joe                       CS                   100000                     2018
        13                  Johnson                 Mary Ann                     Math                   165000                     2014
        14                 Van Gogh                  Vincent                      Art                   240000                     2015
        15                 Van Gogh                  Vincent                       CS                   245000                     2015


27-relational_operators: select * from employee where salary >= 235000

Table name: employee_0, records: 2
    record                     last                    first                      dep                   salary                     year

         0                 Van Gogh                  Vincent                      Art                   240000                     2015                   ú└w
         1                 Van Gogh                  Vincent                       CS                   245000                     2015                   ú└w


28-relational_operators: select * from student where lname < Jackson

Table name: student_0, records: 4
    record                    fname                    lname                    major                      age                  company

         0               Anna Grace                  Del Rio                       CS                       22                     USAF                     M☻o☺  
          :wûJì↑■   Hè░
         1               Teresa Mae                   Gowers                Chemistry                       22                  Verizon                     M☻o☺  
          :wûJì↑■   Hè░
         2               Sammuel L.                  Jackson                       CS                       40                     Uber                     M☻o☺  
          :wûJì↑■   Hè░
         3                      Flo                  Jackson                     Math                       21                   Google                     M☻o☺  
          :wûJì↑■   Hè░


29-relational_operators: select * from student where major < Math

Table name: student_0, records: 8
    record                    fname                    lname                    major                      age                  company

         0                      Flo                      Yao                       CS                       20                   Google
         1                       Bo                     Yang                       CS                       28                Microsoft
         2               Sammuel L.                  Jackson                       CS                       40                     Uber
         3               Anna Grace                  Del Rio                       CS                       22                     USAF
         4               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
         5                     Alex                    Smith           Gender Studies                       53                   Amazon
         6                      Flo                  Jackson                     Math                       21                   Google
         7                  Jim Bob                    Smith                     Math                       23                  Verizon


30-relational_operators: select * from student where fname < "Jim Bob"

Table name: student_0, records: 8
    record                    fname                    lname                    major                      age                  company

         0                     Alex                    Smith           Gender Studies                       53                   Amazon
         1               Anna Grace                  Del Rio                       CS                       22                     USAF
         2                       Bo                     Yang                       CS                       28                Microsoft
         3                   Calvin                      Woo                  Physics                       22                     Uber
         4                      Flo                      Yao                       CS                       20                   Google
         5                      Flo                  Jackson                     Math                       21                   Google
         6                     Greg                  Pearson                  Physics                       20                   Amazon
         7                  Jim Bob                    Smith                     Math                       23                  Verizon


31-relational_operators: select * from employee where salary < 200000

Table name: employee_0, records: 12
    record                     last                    first                      dep                   salary                     year

         0                     Blow                      Joe                       CS                   100000                     2018
         1                  Johnson                    Billy                  Phys Ed                   102000                     2014
         2                  Jackson                       Bo                Chemistry                   130000                     2011
         3                  Johnson                    Jimmy                Chemistry                   140000                     2018
         4                  Johnson                Billy Bob                  Physics                   142000                     2014
         5                      Yao                    Jimmy                     Math                   145000                     2014
         6                      Yao                      Flo                       CS                   147000                     2012
         7                  Johnson                     Jack                       HR                   150000                     2014
         8                     Yang                       Bo                       CS                   160000                     2013
         9                  Jackson                      Flo                     Math                   165000                     2017
        10                  Johnson                 Mary Ann                     Math                   165000                     2014
        11                  Jackson                    Billy                     Math                   170000                     2017


32-relational_operators: select * from employee where dep < CS

Table name: employee_0, records: 7
    record                     last                    first                      dep                   salary                     year

         0                 Van Gogh                  Vincent                      Art                   240000                     2015                   ÆB☺Σë░
         1                     Blow                      Joe                       CS                   100000                     2018                   ÆB☺Σë░
         2                      Yao                      Flo                       CS                   147000                     2012                   ÆB☺Σë░
         3                     Yang                       Bo                       CS                   160000                     2013                   ÆB☺Σë░
         4                 Van Gogh                  Vincent                       CS                   245000                     2015                   ÆB☺Σë░
         5                  Johnson                    Jimmy                Chemistry                   140000                     2018                   ÆB☺Σë░
         6                  Jackson                       Bo                Chemistry                   130000                     2011                   ÆB☺Σë░


33-relational_operators: select * from employee where last < Jackson

Table name: employee_0, records: 10
    record                     last                    first                      dep                   salary                     year

         0                     Blow                      Joe                       CS                   100000                     2018                   ¿└w
         1                     Blow                    JoAnn                  Physics                   200000                     2016                   ¿└w     
         2                  Jackson                      Flo                     Math                   165000                     2017                   ¿└w
         3                  Jackson                       Bo                Chemistry                   130000                     2011                   ¿└w     
         4                  Jackson                    Billy                     Math                   170000                     2017                   ¿└w
         5                  Johnson                     Jack                       HR                   150000                     2014                   ¿└w
         6                  Johnson                    Jimmy                Chemistry                   140000                     2018                   ¿└w
         7                  Johnson                 Mary Ann                     Math                   165000                     2014                   ¿└w
         8                  Johnson                Billy Bob                  Physics                   142000                     2014                   ¿└w
         9                  Johnson                    Billy                  Phys Ed                   102000                     2014                   ¿└w


34-relational_operators: select * from employee where first < "Billy Bob"

Table name: employee_0, records: 5
    record                     last                    first                      dep                   salary                     year

         0                  Jackson                    Billy                     Math                   170000                     2017
         1                  Johnson                    Billy                  Phys Ed                   102000                     2014
         2                  Johnson                Billy Bob                  Physics                   142000                     2014
         3                     Yang                       Bo                       CS                   160000                     2013
         4                  Jackson                       Bo                Chemistry                   130000                     2011


35-relational_operators: select * from student where age  < 20

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company



36-relational_operators: select * from student where lname < "Del Rio"

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company

         0               Anna Grace                  Del Rio                       CS                       22                     USAF


37-relational_operators: select * from student where fname < Alex

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age                  company

         0                     Alex                    Smith           Gender Studies                       53                   Amazon                     N☻o☺
         1               Anna Grace                  Del Rio                       CS                       22                     USAF                     N☻o☺


38-relational_operators: select * from employee where last < Blow

Table name: employee_0, records: 2
    record                     last                    first                      dep                   salary                     year

         0                     Blow                      Joe                       CS                   100000                     2018
         1                     Blow                    JoAnn                  Physics                   200000                     2016


39-relational_operators: select * from employee where first < Billy

Table name: employee_0, records: 5
    record                     last                    first                      dep                   salary                     year

         0                  Jackson                    Billy                     Math                   170000                     2017
         1                  Johnson                    Billy                  Phys Ed                   102000                     2014
         2                  Johnson                Billy Bob                  Physics                   142000                     2014
         3                     Yang                       Bo                       CS                   160000                     2013
         4                  Jackson                       Bo                Chemistry                   130000                     2011


40-relational_operators: select * from employee where salary < 100000

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year



41-relational_operators: select * from student where age  < 19

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company



42-relational_operators: select * from student where lname < Adams

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company



43-relational_operators: select * from student where fname < Adam

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age                  company

         0                     Alex                    Smith           Gender Studies                       53                   Amazon
         1               Anna Grace                  Del Rio                       CS                       22                     USAF


44-relational_operators: select * from employee where last < Alex

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year



45-relational_operators: select * from employee where first < Avory

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year



46-relational_operators: select * from employee where dep < Alchemy

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year

         0                 Van Gogh                  Vincent                      Art                   240000                     2015


47-relational_operators: select * from student where lname <= Smith

Table name: student_0, records: 7
    record                    fname                    lname                    major                      age                  company

         0               Anna Grace                  Del Rio                       CS                       22                     USAF               Jì↑■   Hè░
         1               Teresa Mae                   Gowers                Chemistry                       22                  Verizon               Jì↑■   Hè░  
         2               Sammuel L.                  Jackson                       CS                       40                     Uber               Jì↑■   Hè░
         3                      Flo                  Jackson                     Math                       21                   Google               Jì↑■   Hè░
         4                     Greg                  Pearson                  Physics                       20                   Amazon               Jì↑■   Hè░
         5                  Jim Bob                    Smith                     Math                       23                  Verizon               Jì↑■   Hè░
         6                     Alex                    Smith           Gender Studies                       53                   Amazon               Jì↑■   Hè░


48-relational_operators: select * from student where fname <= Greg

Table name: student_0, records: 7
    record                    fname                    lname                    major                      age                  company

         0                     Alex                    Smith           Gender Studies                       53                   Amazon
         1               Anna Grace                  Del Rio                       CS                       22                     USAF
         2                       Bo                     Yang                       CS                       28                Microsoft
         3                   Calvin                      Woo                  Physics                       22                     Uber
         4                      Flo                      Yao                       CS                       20                   Google
         5                      Flo                  Jackson                     Math                       21                   Google
         6                     Greg                  Pearson                  Physics                       20                   Amazon


49-relational_operators: select * from student where age <= 40

Table name: student_0, records: 9
    record                    fname                    lname                    major                      age                  company

         0                      Flo                      Yao                       CS                       20                   Google
         1                     Greg                  Pearson                  Physics                       20                   Amazon
         2                      Flo                  Jackson                     Math                       21                   Google
         3                   Calvin                      Woo                  Physics                       22                     Uber
         4               Anna Grace                  Del Rio                       CS                       22                     USAF
         5               Teresa Mae                   Gowers                Chemistry                       22                  Verizon
         6                  Jim Bob                    Smith                     Math                       23                  Verizon
         7                       Bo                     Yang                       CS                       28                Microsoft
         8               Sammuel L.                  Jackson                       CS                       40                     Uber


50-relational_operators: select * from employee where last <= Peach

Table name: employee_0, records: 10
    record                     last                    first                      dep                   salary                     year

         0                     Blow                      Joe                       CS                   100000                     2018
         1                     Blow                    JoAnn                  Physics                   200000                     2016
         2                  Jackson                      Flo                     Math                   165000                     2017
         3                  Jackson                       Bo                Chemistry                   130000                     2011
         4                  Jackson                    Billy                     Math                   170000                     2017
         5                  Johnson                     Jack                       HR                   150000                     2014
         6                  Johnson                    Jimmy                Chemistry                   140000                     2018
         7                  Johnson                 Mary Ann                     Math                   165000                     2014
         8                  Johnson                Billy Bob                  Physics                   142000                     2014
         9                  Johnson                    Billy                  Phys Ed                   102000                     2014


51-relational_operators: select * from employee where first <= Gary

Table name: employee_0, records: 7
    record                     last                    first                      dep                   salary                     year

         0                  Jackson                    Billy                     Math                   170000                     2017
         1                  Johnson                    Billy                  Phys Ed                   102000                     2014
         2                  Johnson                Billy Bob                  Physics                   142000                     2014
         3                     Yang                       Bo                       CS                   160000                     2013
         4                  Jackson                       Bo                Chemistry                   130000                     2011
         5                      Yao                      Flo                       CS                   147000                     2012
         6                  Jackson                      Flo                     Math                   165000                     2017


52-relational_operators: select * from employee where salary <= 23500

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year



LOGIC-O-TEST:

0-Logic-o tes:select * from student where fname = "Flo" and lname = "Yao"

Table name: student_0, records: 0
    record                    fname                    lname                    major                      age                  company

         0                      Flo                      Yao                       CS                       20                   Google


1-Logic-o tes:select * from student where major = "CS" and age < 25

Table name: student_0, records: 2
    record                    fname                    lname                    major                      age                  company

         0                      Flo                      Yao                       CS                       20                   Google
         1               Anna Grace                  Del Rio                       CS                       22                     USAF


2-Logic-o tes:select * from student where major < Math and age > 25

Table name: student_0, records: 3
    record                    fname                    lname                    major                      age                  company

         0                       Bo                     Yang                       CS                       28                Microsoft
         1               Sammuel L.                  Jackson                       CS                       40                     Uber
         2                     Alex                    Smith           Gender Studies                       53                   Amazon


3-Logic-o tes:select * from employee where dep = CS and salary > 150000

Table name: employee_0, records: 2
    record                     last                    first                      dep                   salary                     year

         0                     Yang                       Bo                       CS                   160000                     2013                     ô∩o

         1                 Van Gogh                  Vincent                       CS                   245000                     2015                     ô∩o



4-Logic-o tes:select * from employee where last = Jackson and year < 2015

Table name: employee_0, records: 0
    record                     last                    first                      dep                   salary                     year

         0                  Jackson                       Bo                Chemistry                   130000                     2011


5-Logic-o tes:select * from employee where last = Johnson and year >=2014

Table name: employee_0, records: 5
    record                     last                    first                      dep                   salary                     year

         0                  Johnson                     Jack                       HR                   150000                     2014
         1                  Johnson                 Mary Ann                     Math                   165000                     2014
         2                  Johnson                Billy Bob                  Physics                   142000                     2014
         3                  Johnson                    Billy                  Phys Ed                   102000                     2014
         4                  Johnson                    Jimmy                Chemistry                   140000                     2018


6-Logic-o tes:select * from student where fname = Flo or lname = Jackson

Table name: student_0, records: 3
    record                    fname                    lname                    major                      age                  company

         0                      Flo                      Yao                       CS                       20                   Google
         1                      Flo                  Jackson                     Math                       21                   Google
         2               Sammuel L.                  Jackson                       CS                       40                     Uber


7-Logic-o tes:select * from student where age >=40  or company = Verizon

Table name: student_0, records: 4
    record                    fname                    lname                    major                      age                  company

         0               Sammuel L.                  Jackson                       CS                       40                     Uber                   ╬σoÇè░  
              @w ◄≡o°è░
         1                     Alex                    Smith           Gender Studies                       53                   Amazon                   ╬σoÇè░  
              @w ◄≡o°è░
         2                  Jim Bob                    Smith                     Math                       23                  Verizon                   ╬σoÇè░  
              @w ◄≡o°è░
         3               Teresa Mae                   Gowers                Chemistry                       22                  Verizon                   ╬σoÇè░  
              @w ◄≡o°è░


8-Logic-o tes:select * from employee where first = Bo or last = Johnson

Table name: employee_0, records: 7
    record                     last                    first                      dep                   salary                     year

         0                     Yang                       Bo                       CS                   160000                     2013
         1                  Jackson                       Bo                Chemistry                   130000                     2011
         2                  Johnson                     Jack                       HR                   150000                     2014
         3                  Johnson                    Jimmy                Chemistry                   140000                     2018
         4                  Johnson                 Mary Ann                     Math                   165000                     2014
         5                  Johnson                Billy Bob                  Physics                   142000                     2014
         6                  Johnson                    Billy                  Phys Ed                   102000                     2014


9-Logic-o tes:select * from employee where year >= 2015 or dep = CS

Table name: employee_0, records: 9
    record                     last                    first                      dep                   salary                     year

         0                 Van Gogh                  Vincent                      Art                   240000                     2015                   D@wîè░
         1                 Van Gogh                  Vincent                       CS                   245000                     2015                   D@wîè░  
         2                     Blow                    JoAnn                  Physics                   200000                     2016                   D@wîè░
         3                  Jackson                      Flo                     Math                   165000                     2017                   D@wîè░
         4                  Jackson                    Billy                     Math                   170000                     2017                   D@wîè░
         5                     Blow                      Joe                       CS                   100000                     2018                   D@wîè░
         6                  Johnson                    Jimmy                Chemistry                   140000                     2018                   D@wîè░
         7                      Yao                      Flo                       CS                   147000                     2012                   D@wîè░
         8                     Yang                       Bo                       CS                   160000                     2013                   D@wîè░  


10-Logic-o tes:select * from student where fname = Flo or major = CS and age <= 23

Table name: student_0, records: 3
    record                    fname                    lname                    major                      age                  company

         0                      Flo                      Yao                       CS                       20                   Google
         1                      Flo                  Jackson                     Math                       21                   Google
         2               Anna Grace                  Del Rio                       CS                       22                     USAF


11-Logic-o tes:select * from student where lname = Jackson or age < 23 and company > Uber

Table name: student_0, records: 3
    record                    fname                    lname                    major                      age                  company

         0               Sammuel L.                  Jackson                       CS                       40                     Uber                   D@wîè░
         1                      Flo                  Jackson                     Math                       21                   Google                   D@wîè░
         2               Teresa Mae                   Gowers                Chemistry                       22                  Verizon                   D@wîè░


12-Logic-o tes:select * from employee where last = "Van Gogh" or last = Jackson and salary >= 165000

Table name: employee_0, records: 5
    record                     last                    first                      dep                   salary                     year

         0                 Van Gogh                  Vincent                      Art                   240000                     2015
         1                 Van Gogh                  Vincent                       CS                   245000                     2015
         2                 Van Gogh                  Jim Bob                  Phys Ed                   230000                     2010
         3                  Jackson                      Flo                     Math                   165000                     2017
         4                  Jackson                    Billy                     Math                   170000                     2017


13-Logic-o tes:select * from student where age <30 and major=CS or major = Physics and company = Amazon

Table name: student_0, records: 4
    record                    fname                    lname                    major                      age                  company

         0                      Flo                      Yao                       CS                       20                   Google                   D@wîè░
         1                       Bo                     Yang                       CS                       28                Microsoft                   D@wîè░
         2               Anna Grace                  Del Rio                       CS                       22                     USAF                   D@wîè░
         3                     Greg                  Pearson                  Physics                       20                   Amazon                   D@wîè░


14-Logic-o tes:select * from student where age <=40 and company=Uber or major = CS and company = Google

Table name: student_0, records: 3
    record                    fname                    lname                    major                      age                  company

         0               Sammuel L.                  Jackson                       CS                       40                     Uber                     ë;w◄
         1                   Calvin                      Woo                  Physics                       22                     Uber                     ë;w◄
         2                      Flo                      Yao                       CS                       20                   Google                     ë;w◄


15-Logic-o tes:select * from employee where dep = CS and salary >= 160000 or year > 2014 and last = "Van Gogh"

Table name: employee_0, records: 3
    record                     last                    first                      dep                   salary                     year

         0                     Yang                       Bo                       CS                   160000                     2013
         1                 Van Gogh                  Vincent                       CS                   245000                     2015
         2                 Van Gogh                  Vincent                      Art                   240000                     2015


16-Logic-o tes:select * from student where lname = Yang or major = CS and age < 23 or company = Google

Table name: student_0, records: 4
    record                    fname                    lname                    major                      age                  company

         0                       Bo                     Yang                       CS                       28                Microsoft             F@w╧6<w&N☻o☺
         1                      Flo                      Yao                       CS                       20                   Google             F@w╧6<w&N☻o☺
         2               Anna Grace                  Del Rio                       CS                       22                     USAF             F@w╧6<w&N☻o☺
         3                      Flo                  Jackson                     Math                       21                   Google             F@w╧6<w&N☻o☺


17-Logic-o tes:select * from student where major = Physics or major = Math and company = Google or lname = Jackson

Table name: student_0, records: 4
    record                    fname                    lname                    major                      age                  company

         0                     Greg                  Pearson                  Physics                       20                   Amazon
         1                   Calvin                      Woo                  Physics                       22                     Uber
         2                      Flo                  Jackson                     Math                       21                   Google
         3               Sammuel L.                  Jackson                       CS                       40                     Uber


18-Logic-o tes:select * from employee where dep = CS or year >2014 and year < 2018 or salary >= 265000

Table name: employee_0, records: 13
    record                     last                    first                      dep                   salary                     year

         0                     Blow                      Joe                       CS                   100000                     2018
         1                      Yao                      Flo                       CS                   147000                     2012
         2                     Yang                       Bo                       CS                   160000                     2013
         3                 Van Gogh                  Vincent                       CS                   245000                     2015
         4                  Johnson                     Jack                       HR                   150000                     2014
         5                      Yao                    Jimmy                     Math                   145000                     2014
         6                  Johnson                 Mary Ann                     Math                   165000                     2014
         7                  Johnson                Billy Bob                  Physics                   142000                     2014
         8                  Johnson                    Billy                  Phys Ed                   102000                     2014
         9                 Van Gogh                  Vincent                      Art                   240000                     2015
        10                     Blow                    JoAnn                  Physics                   200000                     2016
        11                  Jackson                      Flo                     Math                   165000                     2017
        12                  Jackson                    Billy                     Math                   170000                     2017


[       OK ] TEST_BATCH_FILE.TestBatchFile (6618 ms)
[----------] 1 test from TEST_BATCH_FILE (6619 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 3 test suites ran. (6622 ms total)
[  PASSED  ] 3 tests.
PS C:\Users\Luu_B\Desktop\CS 008\99_99_final_project-Nairbuul\build\bin> 
</pre>


