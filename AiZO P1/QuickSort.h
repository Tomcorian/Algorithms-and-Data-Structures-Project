#ifndef QuickSort_h
#define QuickSort_h

#include <random>

using namespace std;

class QuickSort
{
	public:
		//QuickSort function, where pivot parameter decides where pivot will be placed, i.e 
		//pivot = 0 -> pivot is randomly picked
		//pivot = 1 -> pivot is on the left
		//pivot = 2 -> pivot is in the middle
		//pivot = 3 -> pivot is on the right
		//sortOrder if not given, will sort ascending, if value is different than 1, data will be sorted descending
		template<typename T> static void Sort(T* tab, int left, int right, int p, int sortOrder = 1);
	
};

template<typename T> void QuickSort::Sort(T* tab, int left, int right, int p, int sortOrder)
{
	//If left is equal right, end function
	if (left >= right)
	{
		return;
	}

	T pivot;

	//Choose pivot based on p value
	switch (p)
	{
		case 0:
			//Random
			//Used {} to create local block inside case to declare variables to allow generating random numbers.
			{
				random_device rd;
				mt19937 gen(rd());
				uniform_int_distribution<> distrib(0, right);

				pivot = tab[distrib(gen)];
			}
			break;

		case 1:
			//Left
			pivot = tab[left];
			break;

		case 2:
			//Middle
			pivot = tab[(left + right) / 2];
			break;

		case 3:
			//Right
			pivot = tab[right];
			break;

		default:
			//Pick middle as default
			pivot = tab[(left + right) / 2];
			break;
	}
	
	//Set i as left - 1 and j as right - 1, because of while loops
	int i = left - 1;
	int j = right + 1;
	//T variable for swapping values
	T pom;

	while (true)
	{
		//Sort in ascending order
		if (sortOrder == 1)
		{
			//Check if ++i is in bounds and tab[i] is lesser than pivot
			while (++i <= right && pivot > tab[i]);

			//Check if --j is in bounds and tab[j] is greater than pivot
			while (--j >= left && pivot < tab[j]);
		}
		//Sort in descending order
		else
		{
			//Check if ++i is in bounds and tab[i] is greater than pivot
			while (++i <= right && pivot < tab[i]);

			//Check if --j is in bounds and tab[j] is lesser than pivot
			while (--j >= left && pivot > tab[j]);
		}

		//Swap values when found
		if (i <= j)
		{
			pom = tab[i];
			tab[i] = tab[j];
			tab[j] = pom;
		}
		//Leave while loop when i>j
		else
		{
			break;
		}
	}

	//Divide tab into [left,j] array and call QuickSort again
	if (j > left)
	{
		QuickSort::Sort(tab, left, j, p, sortOrder);
	}

	//Divide tab into [i,right] array and call QuickSort again
	if (i < right)
	{
		QuickSort::Sort(tab, i, right, p, sortOrder);
	}

}

#endif