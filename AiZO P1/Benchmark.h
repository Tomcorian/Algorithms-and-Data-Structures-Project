#ifndef Benchmark_h
#define Benchamrk_h

#include <iostream>
#include <limits>
#include <random>
#include <string.h>
#include "Timer.h"
#include "FileHandler.h"
#include "SortingManager.h"

using namespace std;

class Benchmark
{
	private:
		//Size of an array
		int instanceSize;
		
		//Data type of an array
		int dataType;

		//Algorithm that we want to use to sort data in array
		int algorithm;

		//File where benchmark time result will be saved
		string outputFile;

		//Number of iterations in for loop. Is equal 1 by default
		int numberOfIterations;

		//In which order should be data before sorting
		//dataOrder = 0 -> random
		//dataOrder = 1 -> descending
		//dataOrder = 2 -> ascending
		//dataOrder = 3 -> ascending by 33%
		//dataOrder = 4 -> ascending by 66%
		int dataOrder = 0;

		//Randomize data to an array and return pointer to it
		template<typename T> T* RandomizeData(int length);


	public:
		//Constructor
		Benchmark(int dT, int iS, int al, int nOI, const string oF, int dO);
		
		//Function to run benchmark
		template<typename T> void RunBenchmark();
};

template<typename T> T* Benchmark::RandomizeData(int length)
{
	//Make a new array
	T* tab = new T[length];

	//Initialize random number generator
	random_device rd;
	mt19937 gen(rd());

	//Check T type
	//If T is int generate random integer
	if (typeid(T) == typeid(int))
	{
		//Random int between minimum int value and maximum int value
		uniform_int_distribution<> distrib(numeric_limits<int>::min(), numeric_limits<int>::max());

		for (int i = 0; i < length; i++)
		{
			//Generate random int and assign it to an array
			//Static_cast needed so there are no warnings related to casting
			tab[i] = static_cast<T>(distrib(gen));
		}
	}
	//If T is real type generate random real number
	else if (typeid(T) == typeid(float) || typeid(T) == typeid(double))
	{

		//Random float or double between minimum and maximum values of T type
		uniform_real_distribution<> distrib(numeric_limits<T>::min(), numeric_limits<T>::max());
		for (int i = 0; i < length; i++)
		{
			//Generate random real number and assign it to an array
			//Static_cast needed so there are no warnings related to casting
			tab[i] = static_cast<T>(distrib(gen));
		}
		
	}

	return tab;
}


template<typename T> void Benchmark::RunBenchmark()
{	
	//Create new array for time results
	int* timeTab = new int[numberOfIterations];
	
	//Create Timer object
	Timer t;

	//Run sorting in for loop
	for (int i = 0; i < numberOfIterations; i++)
	{
		//Create T array and randomize data to it
		T* tab = Benchmark::RandomizeData<T>(instanceSize);

		//Set data order before sorting
		switch (dataOrder)
		{
		case 1:
			//Descending order
			QuickSort::Sort(tab, 0, instanceSize - 1, 2, -1);
			break;

		case 2:
			//Ascending order
			QuickSort::Sort(tab, 0, instanceSize - 1, 2);
			break;

		case 3:
			//Ascending by 33%
			QuickSort::Sort(tab, 0, int(instanceSize * 0.33), 2);
			break;

		case 4:
			//Ascending by 66%
			QuickSort::Sort(tab, 0, int(instanceSize * 0.66), 2);
			break;

		default:
			break;
		}

		//Start counting time
		t.start();

		//Sort with selected algorithm
		SortingManager::SortWithAlgorithm(tab, instanceSize, algorithm);

		//Stop counting time
		t.stop();

		//Get time in milliseconds
		int time = t.result();
		
		//Save time in array
		timeTab[i] = time;

		//Sorting check and print time
		cout << (i + 1) << ". " << " Ended sorting within " << time << " ms. " << (SortingManager::CheckSorting<T>(tab, instanceSize) == 1 ? "Sorted\n" : "NotSorted\n") << endl;

		//Delete tab array
		delete[] tab;
	}

	//Write time results to outputFile
	FileHandler::WriteBenchamrkResultsToFile(outputFile, timeTab, numberOfIterations);

	//Delete timeTab array
	delete[] timeTab;
}



#endif