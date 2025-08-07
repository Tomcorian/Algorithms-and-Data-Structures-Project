#ifndef Timer_h
#define Timer_h

#include <chrono>

using namespace std;

class Timer
{
	public:
		//Initialize and prepare to start.
		Timer(); 
		
		//Reset timer.
		void reset(); 
		
		//Start timer.
		int start(); 
		
		//Stop timer.
		int stop();
		
		//Return elapsed time [ms].
		int result(); 

	private:
		//Start point for measuring time
		chrono::time_point<chrono::high_resolution_clock> startMoment;

		//Stop point for measuring time
		chrono::time_point<chrono::high_resolution_clock> stopMoment;
}; 


#endif