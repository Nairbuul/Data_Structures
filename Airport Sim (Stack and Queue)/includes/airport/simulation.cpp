#include "simulation.h"
Simulation::Simulation(bool debug){ //Creates a simulation and runs/print it.
    _debug = debug;
}
Simulation::Simulation(unsigned int takeoff_time, unsigned int landing_time, unsigned int fuel_limit, unsigned int total_time, double landing_probability, double takeoff_probability){
    //Allows the default variable to be changed.
    _takeoff_time = takeoff_time;
    _landing_time = landing_time;
    _fuel_limit = fuel_limit;
    _total_time = total_time;
    _landing_probability = landing_probability;
    _takeoff_probability = takeoff_probability;

    simulate();
} 

double Simulation::averager(Queue<int> list){   //Function that recieves a queue and averages it.
    assert(!list.empty());
    Queue<int> t = list;                        //Copies the list so we can alter it.
    int denominator = t.size();                 //Sets the size as the denominator.
    int numerator = t.pop();                    //Initialize the numerator as the first element.
    while(!t.empty()){
        numerator += t.pop();                   //Continually update the numerator until the queue is empty.
    }
    return numerator/denominator;               //Return the results.
}
bool Simulation::probability(double prob){ //Returns true everytime rand is less then the greatest number that can be generated by rand * the probability.
    return rand() < prob*RAND_MAX; 
}

void Simulation::print(){
    cout<< "Output: " << endl
        << "============================================" << endl
        << "time to take off      : " << _takeoff_time << endl
        << "time to land:         : " << _landing_time << endl
        << "probability of landing: " << _landing_probability << endl
        << "probability of takeoff: " << _takeoff_probability << endl
        << "fuel: time to crash   : " << _fuel_limit << endl
        << "total simulation time : " << _total_time << endl << endl;
    cout<< ". . . . . . . . . . . . . . . . . . . . . . . " << endl
        << _landed << " landed" << endl
        << _took_off << " took off" << endl
        << _crashed << " crashed. " << endl
        << "Average waiting time to land: " << _landing_averageTime << endl
        << "Average waiting time to take off: " << _takeoff_averageTime << endl
        << "Planes in landing queue : " << _landing_remaining << endl 
        << "Planes in take off queue : " << _takeoff_remaining << endl
        << "============================================" << endl;
}

void Simulation::simulate(){
    Queue<int> queue;                                                                       //Creating a queue that'll be initialized when the probability of takeoff returns true. (Planes to arrive and be ready to take off)
    Queue<int> waitTime_average;                                                            //Queue that'll store the wait time for takeoff. Will also eventually be sent off to averager().
    bool lock = false;                                                                      //Lock: Prevents planes from taking off until the take off queue is ready.
    bool lock2 = false;                                                                     //Lock2: Prevents planes from taking off until the landing queue is ready.
    int key = 0;                                                                            //Key(2) that'll let the lock know the take_off/landing queue is ready.
    int key2 = 0;
    // if(_debug){
    //     int c = 0;
    //     int _c = 0;
    // }
    for(int current_time = 0; current_time <= _total_time; current_time++){                 //The simulation is basically a for loop. 
        if(probability(_takeoff_probability)){                                              //Initializes queue everytime the probability function returns true.                         
            queue.push(current_time);   
            // c++;
        }
        if(!queue.empty()){                                                                 //Makes sure that the queue we're altering is not empty.
            if(!lock){                                                                      //Makes sure that the queue is ready for take off and not busy.
                lock = true;                                                                //Changes the take off queue to busy.
                key = current_time + _takeoff_time;                                         //Sets the timer for when the take off queue is no longer busy.
                waitTime_average.push(current_time - queue.pop());                          //Give the wait_time to queue to hold.
                _took_off++;                                                                //Record that a plane has taken off.
            }
        }
        if(current_time == key){                                                            //Until this time is met the take off queue will remain busy.
                lock = false;                                                               //take off queue is now free.
        }    
        // if(_debug){cout << current_time << " <-CT->" << endl;}
    }
    Queue<int> landing_Queue;                                                               //Created another queue for landing to be initialized. (Planes to arrive and land)
    Queue<int> average_waitTime;                                                            //Another queue to hold all the wait times for a plane to land.
    for(int current_time = 0; current_time <= _total_time; current_time++){                 //Created two seperate for loops to ease the load for the pc.
        if(probability(_landing_probability)){                                              //Everytime this function returns true a plane is ready for landing.
            landing_Queue.push(current_time);
            // _c++;                                                                        //Debug statement that'll show how many times planes have arrived and are ready to land.
        }
        if(!landing_Queue.empty()){                                                         //Ensures that we're not altering an empty queue.
            if(!lock2){                                                                     //Tells the pit crew that landing is not available yet.
                lock2 = true;
                key2 = current_time + _landing_time;                                        //Time for when landing is available.
                int time_stamp = landing_Queue.pop();
                int wait_time = current_time - time_stamp;
                // if(_debug){
                //     cout << landing_Queue.size() << " landing_Queue size " << endl; 
                //     cout << wait_time << " wait time" <<endl;
                // }
                if(wait_time < _fuel_limit){                                                //If the plane ran out of fuel before it lands it'll crash.
                    average_waitTime.push(wait_time);
                    _landed++;
                }
                else{
                    _crashed++;
                }
            }
        }
        // if(_debug){cout << "Landing Simulation current_time:  " << current_time << endl;}
        if(current_time == key2){                                                           //Notifier that landing is now avaiable.
                lock2 = false; 
                // if(debug){cout << __LINE__ << endl;}
        }    
    }
    _landing_remaining = landing_Queue.size();                                              //This will tell us how many planes are left in the landing queue after the simulation ends.
    _takeoff_remaining = queue.size();                                                      //This will tell us how many planes are left in the take off queue after the simulation ends.
    _takeoff_averageTime = averager(waitTime_average);                                      //This will give us our average wait titme to take off.
    _landing_averageTime = averager(average_waitTime);                                      //This will give us our average wait titme to land.
    
    print();                                                                                //Print our results.
    
    //if(_debug){cout << End of simulate.;}

    exit(0);                                                                                //If this isn't here it'll always give us a malloc error.
}   
