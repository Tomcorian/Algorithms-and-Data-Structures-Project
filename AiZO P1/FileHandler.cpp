#include "FileHandler.h"

//Function to write time results from benchmark to given file
void FileHandler::WriteBenchamrkResultsToFile(const string filePath, int* tab, int length)
{
	std::ofstream file(filePath);

	for (int i = 0; i < length; i++)
	{
		file << tab[i] << "\n";
	}

}