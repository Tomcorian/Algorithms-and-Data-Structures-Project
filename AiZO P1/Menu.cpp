#include "Menu.h"

//Function to print help message
void Menu::PrintHelp()
{
	cout << "\nDATA SORTER\n\n"

		<< "FILE TEST MODE:\n"
		<< "\tUsage:\n"
		<< "	  ./DataSorter --file <type> <algorithm> <inputFile> [outputFile]\n\n"
		<< "	<type>\t\t\tData type to load (e.g. 0 - int, 1 - float, 2 - double)\n"
		<< "	<algorithm>\t\tSorting algorithm to use (e.g 0 - Insert Sort, 1 - Insert Binary Sort, 2 - Heapsort, 3 - Quicksort)\n"
		<< "	<inputFile>\t\tFile containing data to be sorted\n"
		<< "	[outputFile]\t\tIf given, a destination where data will be saved after sorting\n\n"

		<< "BENCHMARK MODE:\n"
		<< "\tUsage:\n"
		<< "	  ./DataSorter --test <type> <size> <algorithm> <numberOfTests> <outputFile> <dataOrder>\n\n"
		<< "	<type>			Data type to generate (e.g. 0 - int, 1 - float, 2 - double)\n"
		<< "	<size>			Number of elements to generate\n"
		<< "	<algorithm>		Sorting algorithm to use (e.g 0 - Insert Sort, 1 - Insert Binary Sort, 2 - Heapsort, 3 - Quicksort)\n"
		<< "	<numberOfTests>\t\tNumbers of tests to conduct.\n"
		<< "	<outputFile>\t\tA destination file where time results will be saved\n"
		<< "	<dataOrder>\t\tData order before sorting (0 - random, 1 - descending, 2 - ascending, 3 - ascending by 33%, 4 - ascending by 66%)\n\n"

		<< "HELP MODE:\n"
		<< "\tUsage:\n"
		<< "	  ./DataSorter --help\n\n"
		<< "	Displays this help message\n\n"
		<< "	Additonal info:\n"
		<< "	- This message will be printed if no arguments are provided.\n"
		<< "	- Make sure that only one mode is specified in call. (Either --file, --test or --help).\n"
		<< "	- For FILE TEST MODE make sure that data in file is in following convention:\n"
		<< "		- Number of elements is in first line.\n"
		<< "		- Every element is in seperate line.\n\n"

		<< "EXAMPLE CALLS:\n"
		<< "\tSort int array using Heapsort from file \"data.txt\" and save it to \"sorted.txt\"\n"
		<< "		./DataSorter --file 0 2 data.txt sorted.txt\n\n"
		<< "\tRun a benchmark 200 times with 1000 randomly generated floats using Insert Binary Sort\n"
		<< "		./DataSorter --test 1 1000 1 200 results.txt 0\n\n";
}