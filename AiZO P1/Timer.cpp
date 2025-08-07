#include "Timer.h"

//Constructor
Timer::Timer()
{

}

//Function to set start point
int Timer::start()
{
	startMoment = chrono::high_resolution_clock::now();
	return 0;
}

//Function to set stop point
int Timer::stop()
{
	stopMoment = chrono::high_resolution_clock::now();
	return 0;
}

//Function to calculate time between start and stop point and return this value in miliseconds
int Timer::result()
{
	auto duration = stopMoment - startMoment;
	auto ms = chrono::duration_cast<chrono::milliseconds>(duration).count();
	return (int) ms;
}