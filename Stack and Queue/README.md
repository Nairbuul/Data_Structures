
# Work Report

## Name: <ins> Brian Luu </ins>

## Features:

- Not Implemented:
  - Can only run using play button on bottom of vsc.

<br><br>

- Implemented:
  - Working cmake.
  - Implemented array functions
    - initilization
    - append
    - find
    - index return

<br><br>

- Partly implemented:
  - what features have not been implemented

<br><br>

- Bugs
  - VSC only runs basic_test if I use the bottom. I type in the terminal to make it run. (EDIT: I figured it out I was typing the wrong commands.)
  - if node is nullptr  _insert_head has a segmentation error due to _Prev being wonky. However if _prev does not link the previous nodes. _print_list_backwards does not work.

<br><br>

# Reflections:

- Any thoughts you may have and would like to share.

# **output**
<pre>
<br/><br/><br/><br/>
</pre>
<br/><br/>

# basic_test.cpp output:
<pre>
<br/><br/><br/><br/>
PS C:\Users\Luu_B\Desktop\CS 008\00_lab_0-Nairbuul> ."C:/Users/Luu_B/Desktop/CS 008/00_lab_0-Nairbuul/build/bin/basic_test.exe" 


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from BASIC_TEST
[ RUN      ] BASIC_TEST.BasicTest


after init: -1 -1 -1 -1 -1 [5]
-1 -1 -1 -1 -1 50 [6]
-1 -1 -1 -1 -1 50 60 [7]
-1 -1 -1 -1 -1 50 60 70 [8]
-1 -1 -1 -1 -1 50 60 70 80 [9]
-1 -1 -1 -1 -1 50 60 70 80 90 [10]
found 70 at: 70
changing 70 to 700:
-1 -1 -1 -1 -1 50 60 700 80 90 [10]


[       OK ] BASIC_TEST.BasicTest (15 ms)
[----------] 1 test from BASIC_TEST (15 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (16 ms total)
[  PASSED  ] 1 test.
</pre>
# testB.cpp output:
<pre>
<br/><br/><br/><br/>
PS C:\Users\Luu_B\Desktop\CS 008\00_lab_0-Nairbuul\build\bin> ."C:/Users/Luu_B/Desktop/CS 008/00_lab_0-Nairbuul/build/bin/testB.exe" 


----------running testB.cpp---------


[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from TEST_STUB
[ RUN      ] TEST_STUB.TestStub
[       OK ] TEST_STUB.TestStub (0 ms)
[ RUN      ] TEST_STUB.TestNode
testB:: test-sub() entering test_sub

0x1391588  8
Head->[2222]-> <-[1]-> <-[800082]-> <-[2]-> <-[3]-> <-[4]-> <-[5]-> <-[6]-> <-[7]-> <-[11111]-> <-[8]-> <-[8008132]-> <-[9]-> <-[10]-> |||
||| <-[10]-> <-[9]-> <-[8008132]-> <-[8]-> <-[11111]-> <-[7]-> <-[6]-> <-[5]-> <-[4]-> <-[3]-> <-[2]-> <-[800082]-> <-[1]-> <-[2222] <-Head
Head->[a]-> |||
Head->[b]-> |||
[11111]->
8
Head->[2222]-> <-[1]-> <-[800082]-> <-[2]-> <-[3]-> <-[4]-> <-[5]-> <-[6]-> <-[7]-> <-[11111]-> <-[8008132]-> <-[9]-> <-[10]-> |||
||| <-[10]-> <-[9]-> <-[8008132]-> <-[11111]-> <-[7]-> <-[6]-> <-[5]-> <-[4]-> <-[3]-> <-[2]-> <-[800082]-> <-[1]-> <-[2222] <-Head
0x139c290 [10]->
Head->[2222]-> <-[1]-> <-[800082]-> <-[2]-> <-[3]-> <-[4]-> <-[5]-> <-[6]-> <-[7]-> <-[11111]-> <-[8008132]-> <-[9]-> <-[10]-> |||
2[       OK ] TEST_STUB.TestNode (33 ms)
[----------] 2 tests from TEST_STUB (34 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (36 ms total)
[  PASSED  ] 2 tests.
</pre>


