#ifndef SortingManager_h
#define SortingManager_h

#include "HeapSort.h"
#include "InsertSort.h"
#include "QuickSort.h"

class SortingManager
{
	public:
		//Function to choose algorithm to sort tab array.
		template<typename T>static void SortWithAlgorithm(T* tab, int length, int algorithm);
		
		//Simple function to check if sorting was done succesfully.
		template<typename T>static bool CheckSorting(T* tab, int length);
};

template<typename T> bool SortingManager::CheckSorting(T* tab, int length)
{
	for (int i = 0; i < length - 1; i++)
	{		
		//If array is not sorted ascending return false	
		if (tab[i] > tab[i + 1])
		{
			return false;
		}	
	}
	//Return true if array is sorted ascending or descending depending on sortOrder value
	return true;
}

template<typename T> void SortingManager::SortWithAlgorithm(T* tab, int length, int algorithm)
{
	//Choose algorithm to sort tab array
	switch (algorithm)
	{
	//Insert Sort
	case 0:
		InsertSort::Sort<T>(tab, length, false);
		break;

	//Insert Binary Sort
	case 1:
		InsertSort::Sort<T>(tab, length, true);
		break;

	//Heap Sort
	case 2:
		HeapSort::Sort<T>(tab, length);
		break;

	//Quick Sort
	case 3:
		QuickSort::Sort<T>(tab, 0, length - 1, 2);
		break;
	}

}

#endif