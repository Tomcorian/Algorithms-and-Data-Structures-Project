#ifndef HeapSort_h
#define HeapSort_h

#include <iostream>
#include <cmath>

class HeapSort
{
	private:
		//Restore HeapMAX property
		template<typename T> static void Heapify(T* tab, int length, int index);
		//Build heap
		template<typename T> static void BuildHeap(T* tab, int length);
		//Get left son of a node
		static int Left(int index);
		//Get right son of a node
		static int Right(int index);
	public:
		//Function to sort tab array
		template<typename T> static void Sort(T* tab, int length);

};


template<typename T> void HeapSort::Heapify(T* tab, int length, int index)
{
	//Assign left and right index
	int left = HeapSort::Left(index);
	int right = HeapSort::Right(index);

	int largest;

	//Look for largest value in node and assign it
	if (left < length && tab[left] > tab[index])
	{
		largest = left;
	}
	else
	{
		largest = index;
	}

	if (right < length && tab[right] > tab[largest])
	{
		largest = right;
	}

	//If largest value is not in tab[index] swap values and call Heapify for largest node 
	if (largest != index)
	{
		T pom = tab[index];
		tab[index] = tab[largest];
		tab[largest] = pom;

		HeapSort::Heapify<T>(tab, length, largest);
	}
}


template<typename T> void HeapSort::BuildHeap(T* tab, int length)
{	
	//For every not-leaf, do Heapify for i node
	for (int i = (int) (length / 2); i > -1; i--)
	{
		HeapSort::Heapify<T>(tab, length, i);
	}
}

template<typename T> void HeapSort::Sort(T* tab, int length)
{
	//Build heap
	HeapSort::BuildHeap<T>(tab, length);

	for (int i = 1; i < length; i++)
	{
		//Swap last leaf and root values, and call Heapify for root node
		T pom = tab[length - i];
		tab[length - i] = tab[0];
		tab[0] = pom;
		HeapSort::Heapify<T>(tab, length - i, 0);
	}
}

#endif