#include "HeapSort.h"

//Function to count left son of a node in heap
int HeapSort::Left(int index)
{
	return 2 * index + 1;
}

//Function to count right son of a node in heap
int HeapSort::Right(int index)
{
	return Left(index) + 1;
}