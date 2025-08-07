#ifndef FileTest_h
#define FileTest_h

#include "FileHandler.h"
#include "SortingManager.h"
#include "Timer.h"
#include <iostream>

class FileTest
{
	private:
		//Data type of an array
		int dataType;
		
		//Algorithm we want to use for sorting
		int algorithm;

		//File from which we will read data
		string inputFile;

		//File to which we will save sorted data
		string outputFile;

	public:
		//Constructor for 3 given arguments
		FileTest(int dT, int al, const string iF);
		
		//Constructor for 4 given arguments
		FileTest(int dT, int al, const string iF, const string oF);

		//Function that runs sorting
		template<typename T> void RunTest();
};

template<typename T> void FileTest::RunTest()
{
	int length = 0;
	
	//Get data from given file and overwrite length variable
	T* tab = FileHandler::GetDataFromFile<T>(inputFile, length);

	//Create Timer object
	Timer t;

	//Start counting time
	t.start();

	//Sort with selected algorithm
	SortingManager::SortWithAlgorithm<T>(tab, length, algorithm);
	
	//Stop counting time
	t.stop();

	//Sort Check and write sorting time
	cout << "Ended sorting within " << t.result() << " ms. " << (SortingManager::CheckSorting<T>(tab, length) == 1 ? "Sorted\n" : "Not sorted\n");

	//Write data to file, if outputFile was given
	if (outputFile != "nofile")
	{
		FileHandler::WriteDataToFile<T>(outputFile, tab, length);
	}

	//Delete tab
	delete[] tab;
}


#endif FileTest_h