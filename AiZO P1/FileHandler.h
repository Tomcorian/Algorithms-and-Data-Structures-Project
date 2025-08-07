#ifndef FileHandler_h
#define FileHandler_h

#include <iostream>
#include <fstream>
#include <string.h>

using std::cout;
using std::string;


class FileHandler
{
	public:
		//Get data from file
		template<typename T> static T* GetDataFromFile(const string filePath, int& length);
		
		//Write sorted data to file
		template<typename T> static void WriteDataToFile(const string filePath, T* tab,int length);
		
		//Write benchmark times to data
		static void WriteBenchamrkResultsToFile(const string filePath, int* tab, int length);

};

template<typename T> T* FileHandler::GetDataFromFile(const string filePath, int& length)
{
	std::ifstream file;
	file.open(filePath);

	//If file exists and opens, get data from file
	if (file.is_open())
	{

		file >> length;

		T* tab = new T[length];
		int i = 0;

		while (i < length)
		{
			file >> tab[i];
			i++;
		}

		return tab;
	}
	//Otherwise, return nullptr
	else
	{
		return nullptr;
	}

}

template<typename T> void FileHandler::WriteDataToFile(const string filePath, T* tab , int length)
{
	std::ofstream file(filePath);

	//Write length and data to file

	file << length;
	file << "\n";

	for (int i = 0; i < length; i++)
	{
		file << tab[i] << "\n";
	}

	file.close();
}


#endif