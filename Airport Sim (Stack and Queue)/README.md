
# Work Report
- Ran on a macbook. (Windows failure rate was much higher due to same reason not sure why.)
  - 10,000 simulation time. 
    - (≈ 40% rate of successfully simulating.)
    - (60% failure due to malloc: *** error for object 0x7fd426709d40: pointer being freed was not allocated.)
    - Succesful runs(#2,4,7,9)
    - Failed runs(#1,3,5,6,8,10)

  - 1440 simulation time. 
    - (≈80-90% rate of successfully simulating.)
    - (10% failure due to due to malloc: *** error for object 0x7fd426709d40: pointer being freed was not allocated.)
    - Successful runs(#1,2,3,4,5,6,7, 8, 9, 10)
    - Failed runs(#7)
    
  - 200 simulation time.
    - (≈80-90% rate of successfully simulating.)
    - Failure due to malloc: *** error for object 0x7fd426709d40: pointer being freed was not allocated.
    - Succesful runs(#1,2,3,5,6,8,9,10)
    - Failed runs(#4, 7)

  - 150 simulation time.
    - (≈90% rate of succesfull simulating. (Definetly not 100%))
    - Successful runs(#1,2,3,4,5,6,7,8,9,10)
    - Failed runs()
  
  Work Report:
- I noticed the reason of failure was always due to a malloc pointer. Sometimes there will be 20-30 straight successful runs and other times there will be about 10 failed    runs in a row. Failure and success rates increases and decreases respectively with sample size. There is also an issue that'll randomly appears with the Queue.pop() function.I can't replicate the error and it seems to occasionally appear when the function Averager recieves a queue that is looped less then 200 times or randomly if the simulation time is large enough. (I can't figure out the pattern.) Designing this simulation was fun and occassionally irritating because the program would run and in the next five minutes it wouldn't. I believe it's probably due to the amount of actions I'm telling the computer to do. So now I'm brainstorming on a way to more efficently run the program. 

  Results Observation:
- Regaurdless of simulation time there is never any planes left in landing queue. Planes landed is always about 50-60% more then the planes landed. The average wait time increases as the simulation time increase.

## Name: <ins> Brian Luu </ins>

## Features:

- Not Implemented:
  - I'm thinking of breaking the simulate function up into more class function to maybe reduce the load on the computer and hopefully the success rate will incresase.
    - Ex.) Maybe initializing a queue with the probability function and giving it to the simulation program.
      - Ex. issue) Have not yet thought of a way to match the time so it will do work as intended.

<br><br>

- Implemented:
  - Linked lists 
  - Stack & Queue libraries
  - Simulation (Can only run one time need to keep running basic_test/testB/main)
    - Function averager to average a non-empty queue. 
    - Probability function to initialize a queue. 
    - Output function to print results.
    - Simulate function to simulate results with given variables.

<br><br>

- Partly implemented:
  - Debugs comments are all commented out because they return a lot of junk and may freeze pc.
<br><br>

- Bugs
  - Sometimes the simulation fails due to a miss allocation.
  - Sometimes Averager function in simulation refuses to return a value if the sample size is less then 200.
  - Even though I'm not printing the popped numbers they still appear in the terminal.
<br><br>

# Reflections:

- Need to ask about this.
  - basic_test(32376,0x10e6ca600) malloc: *** error for object 0x7fa796904360: pointer being freed was not allocated
  - basic_test(32376,0x10e6ca600) malloc: *** set a breakpoint in malloc_error_break to debug

# **output**
<pre>
<br/><br/><br/><br/>
Output: (Run#1)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 150

. . . . . . . . . . . . . . . . . . . . . . . 
15 landed
7 took off
0 crashed. 
Average waiting time to land: 2
Average waiting time to take off: 10
Planes in landing queue : 0
Planes in take off queue : 0
============================================
dexterddjoey@Brians-MBP bin % 

Output: (Run#2)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 150

. . . . . . . . . . . . . . . . . . . . . . . 
14 landed
10 took off
0 crashed. 
Average waiting time to land: 3
Average waiting time to take off: 30
Planes in landing queue : 0
Planes in take off queue : 4
============================================
dexterddjoey@Brians-MBP bin % 

Output: (Run#3)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 150

. . . . . . . . . . . . . . . . . . . . . . . 
11 landed
9 took off
0 crashed. 
Average waiting time to land: 2
Average waiting time to take off: 12
Planes in landing queue : 0
Planes in take off queue : 2
============================================
dexterddjoey@Brians-MBP bin % 

Output: (Run#4)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 150

. . . . . . . . . . . . . . . . . . . . . . . 
14 landed
10 took off
0 crashed. 
Average waiting time to land: 4
Average waiting time to take off: 51
Planes in landing queue : 0
Planes in take off queue : 6
============================================
dexterddjoey@Brians-MBP bin % 

Output: (Run#5)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 150

. . . . . . . . . . . . . . . . . . . . . . . 
10 landed
6 took off
0 crashed. 
Average waiting time to land: 3
Average waiting time to take off: 5
Planes in landing queue : 1
Planes in take off queue : 0
============================================
dexterddjoey@Brians-MBP bin % 
</pre>


<br/><br/>

# basic_test.cpp output:
<pre>
<br/><br/><br/><br/>
    This will be showing results with sample size 10,000.
    - Output: (Run #2 sample size 10,000)
      ============================================
      time to take off      : 15
      time to land:         : 5
      probability of landing: 0.1
      probability of takeoff: 0.08
      fuel: time to crash   : 20
      total simulation time : 10000

      . . . . . . . . . . . . . . . . . . . . . . . 
      1013 landed
      623 took off
      12 crashed. 
      Average waiting time to land: 3
      Average waiting time to take off: 1075
      Planes in landing queue : 0
      Planes in take off queue : 195
      ============================================
      dexterddjoey@Brians-MBP bin % 

    - Output: (Run #4 sample size 10,000)
      ============================================
      time to take off      : 15
      time to land:         : 5
      probability of landing: 0.1
      probability of takeoff: 0.08
      fuel: time to crash   : 20
      total simulation time : 10000

      . . . . . . . . . . . . . . . . . . . . . . . 
      980 landed
      625 took off
      20 crashed. 
      Average waiting time to land: 9
      Average waiting time to take off: 1302
      Planes in landing queue : 0
      Planes in take off queue : 182
      ============================================
      dexterddjoey@Brians-MBP bin % 

  - Output: (Run #7 sample size: 10,000)
      ============================================
      time to take off      : 15
      time to land:         : 5
      probability of landing: 0.1
      probability of takeoff: 0.08
      fuel: time to crash   : 20
      total simulation time : 10000

      . . . . . . . . . . . . . . . . . . . . . . . 
      1005 landed
      620 took off
      17 crashed. 
      Average waiting time to land: 3
      Average waiting time to take off: 1433
      Planes in landing queue : 0
      Planes in take off queue : 202
      ============================================
      dexterddjoey@Brians-MBP bin % 

  Output: (Run #9 sample size: 10, 000)
    ============================================
    time to take off      : 15
    time to land:         : 5
    probability of landing: 0.1
    probability of takeoff: 0.08
    fuel: time to crash   : 20
    total simulation time : 10000

    . . . . . . . . . . . . . . . . . . . . . . . 
    991 landed
    625 took off
    10 crashed. 
    Average waiting time to land: 3
    Average waiting time to take off: 898
    Planes in landing queue : 0
    Planes in take off queue : 158
    ============================================
    dexterddjoey@Brians-MBP bin % 
</pre>
# testB.cpp output:
<pre>
<br/><br/><br/><br/>
  Output:(Run #1 sample size 1440)
  ============================================
  time to take off      : 15
  time to land:         : 5
  probability of landing: 0.1
  probability of takeoff: 0.08
  fuel: time to crash   : 20
  total simulation time : 1440

  . . . . . . . . . . . . . . . . . . . . . . . 
  142 landed
  85 took off
  0 crashed. 
  Average waiting time to land: 2
  Average waiting time to take off: 131
  Planes in landing queue : 0
  Planes in take off queue : 26
  ============================================
  dexterddjoey@Brians-MBP bin %     

  Output: (Run #2)
  ============================================
  time to take off      : 15
  time to land:         : 5
  probability of landing: 0.1
  probability of takeoff: 0.08
  fuel: time to crash   : 20
  total simulation time : 1440

  . . . . . . . . . . . . . . . . . . . . . . . 
  155 landed
  90 took off
  6 crashed. 
  Average waiting time to land: 4
  Average waiting time to take off: 110
  Planes in landing queue : 0
  Planes in take off queue : 13
  ============================================
  dexterddjoey@Brians-MBP bin % 

Output: (Run #3)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440

. . . . . . . . . . . . . . . . . . . . . . . 
169 landed
90 took off
0 crashed. 
Average waiting time to land: 4
Average waiting time to take off: 113
Planes in landing queue : 0
Planes in take off queue : 6
============================================
dexterddjoey@Brians-MBP bin % 

Output: (Run #4)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440

. . . . . . . . . . . . . . . . . . . . . . . 
150 landed
86 took off
1 crashed. 
Average waiting time to land: 3
Average waiting time to take off: 86
Planes in landing queue : 0
Planes in take off queue : 15
============================================
dexterddjoey@Brians-MBP bin % 

Output: (Run#5)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440

. . . . . . . . . . . . . . . . . . . . . . . 
154 landed
89 took off
7 crashed. 
Average waiting time to land: 5
Average waiting time to take off: 112
Planes in landing queue : 0
Planes in take off queue : 18
============================================
dexterddjoey@Brians-MBP bin % 

Output: (Run #6)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440

. . . . . . . . . . . . . . . . . . . . . . . 
138 landed
86 took off
0 crashed. 
Average waiting time to land: 2
Average waiting time to take off: 107
Planes in landing queue : 0
Planes in take off queue : 17
============================================
dexterddjoey@Brians-MBP bin % 

Output: (Run #8)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440

. . . . . . . . . . . . . . . . . . . . . . . 
138 landed
90 took off
0 crashed. 
Average waiting time to land: 2
Average waiting time to take off: 218
Planes in landing queue : 0
Planes in take off queue : 54
============================================
dexterddjoey@Brians-MBP bin %    

Output: (Run#9)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440

. . . . . . . . . . . . . . . . . . . . . . . 
132 landed
90 took off
0 crashed. 
Average waiting time to land: 2
Average waiting time to take off: 136
Planes in landing queue : 0
Planes in take off queue : 22
============================================
dexterddjoey@Brians-MBP bin % 

Output: (Run#10)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440

. . . . . . . . . . . . . . . . . . . . . . . 
143 landed
90 took off
2 crashed. 
Average waiting time to land: 2
Average waiting time to take off: 194
Planes in landing queue : 0
Planes in take off queue : 39
============================================
dexterddjoey@Brians-MBP bin % 

Output: (Run #11)
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440

. . . . . . . . . . . . . . . . . . . . . . . 
134 landed
90 took off
4 crashed. 
Average waiting time to land: 3
Average waiting time to take off: 246
Planes in landing queue : 2
Planes in take off queue : 39
============================================
dexterddjoey@Brians-MBP bin % 
</pre>


