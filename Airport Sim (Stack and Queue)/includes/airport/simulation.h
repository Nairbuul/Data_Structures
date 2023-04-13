#ifndef SIMULATION_H
#define SIMULATION_H

// unsigned int takeoff_time,      //how long it takes for a take off once plane 
//                                 //    is on the runway 
// double takeoff_probability,     //probability of arrival of a plane into the 
//                                 //    take off line 
// unsigned int landing_time,      //how long it takes for a plane to land on the 
//                                 //    runway in each second
// double landing_probability,     //probability of arrival of planes for landing 
//                                 //     in each second
// unsigned int fuel_limit,        //maximum amount of time a plan can stay in 
//                                 //      landing queue without crashing
// unsigned int total_time;        //total time you will run the simulation.

#include <iostream>
#include <iomanip>
#include <assert.h>
#include <cstdlib>

#include "../queue/MyQueue.h"

using namespace std;
/*Output:
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
145 landed
48 took off
2 planes crashed. :(
Average waiting time to land: 9
Average waiting time to take off: 457.271
planes in landing queue : 0
planes in take off queue: 72
============================================  */

/* What we want to know.
    -#Planes landed                                                 - landing success (Planes successfully popped from initialized queue)
    -#Planes taken off                                              - takeoff success. (Planes successfully popped from initialized queue)
    -#Planes crashed                                                - If the waiting time to land is longer then fuel_time then the plane will crash.
    -Waiting time to land                                           - Calculated by getting timestamp after landing  - current time if landing available.
    -Waiting time to take off                                       - Calculated by getting timestamp after take off - current time if take off is available.
    -planes in landing queue                                        - #of planes in the landing queue after the simulation.
    -planes in take off queue.                                      - #of planes in the take off queue after the simulation.
*/
/*
    Steps: 
    1.) Created and tested a probability function. Double checked the math.
    2.) Created and  tested an average function that takes queue.
    3.) Create a method that'll allow planes to take offs or landing only after the previous plane has recieved enough time to do so itself. 
*/
class Simulation{
public:
    Simulation(bool debug);                                                 //Ctor that'll also simulate the results using default values.
    Simulation(unsigned int takeoff_time, unsigned int landing_time,        //Ctor that'll alow you to change the default values.
                unsigned int fuel_limit, unsigned int total_time,
                double landing_probability, double takeoff_probability); 
    void simulate();                                                        //Function that is calculating the results with the given values.
    double averager(Queue<int> list);                                       //Function that'll return an average when given a non-empty queue.
    bool probability(double prob);                                          //Function that'll return true if number generated is <= to the default probability.
    void print();                                                           //Print function.  

private:
    bool _debug;                                                            //If true it'll print out all debug statements in program.
    unsigned int _takeoff_time = 15;      
    unsigned int _landing_time = 5;  
    double _takeoff_probability = 0.08;    
    double _landing_probability = 0.1;     
    unsigned int _fuel_limit = 20;      
    unsigned int _total_time = 1440;     
                                                                            //Variables taht are given to the print functions before simulation ends.
    int _landed = 0;                                                        
    int _took_off = 0;                                                      
    int _crashed = 0;                                                       
    double _landing_averageTime = 0;                                        
    double _takeoff_averageTime = 0;                                        
    int _landing_remaining = 0;                                             
    int _takeoff_remaining = 0;                                            
};

#endif