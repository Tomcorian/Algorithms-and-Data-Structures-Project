#ifndef InsertSort_h
#define InsertSort_h

class InsertSort
{
	public:
		//Function to sort tab array
		template<typename T> static void Sort(T* tab, int length, bool binary = false);
};

template<typename T> static void InsertSort::Sort(T* tab, int length, bool binary)
{
	//T variable used for remembering values
	T pom;
	
	//Use normal variant of insert sort
	if (binary == false)
	{
		//j - index
		int j;

		//Start sorting from second element
		for (int i = 1; i < length; i++)
		{
			//Save tab[i] value
			pom = tab[i];
			j = i - 1;

			//Check previous elements before tab[i] and move them to the right
			while (j >= 0 && pom < tab[j])
			{
				tab[j + 1] = tab[j];
				j--;
			}
			//Assign remembered value
			tab[j + 1] = pom;

		}
	}
	//Use binary search variant of insert sort
	else
	{
		//jp - beginning of binary search, jk - ending of binary search, j - index
		int jp, jk, j;

		//We start from the second last element
		for (int i = length - 2; i >= 0; i--)
		{
			//Save tab[i] values
			pom = tab[i];
			
			//Assign beginning and end of binary search
			jp = i;
			jk = length;

			//Check if subtraction of jk and jp is greater than 1
			while (jk - jp > 1)
			{
				//Assign j by dividng sum of jp and jk
				j = (jp + jk) / 2;
				//If remembered value is greater or equal, assign j to jk
				if (pom <= tab[j])
				{
					jk = j;
				}
				//If otherwise, assign j to jp
				else
				{
					jp = j;
				}
			}
			//Move values to the right
			for (j = i; j < jp; j++)
			{
				tab[j] = tab[j + 1];
			}
			//Assign remebered values
			tab[jp] = pom;

		}
	}

	
}

#endif