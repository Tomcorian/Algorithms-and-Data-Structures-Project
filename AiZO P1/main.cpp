#include <iostream>
#include <string>

#include "Benchmark.h"
#include "FileTest.h"
#include "Menu.h"

using namespace std;

int main(int argc, char* argv[])
{
	
	if (argc == 1)
	{
		//Print help message, if no arguments are given
		Menu::PrintHelp();
	}
	else if (argc == 2 && !strcmp(argv[1], "--help"))
	{
		//Print help message
		Menu::PrintHelp();
	}
	else if ((argc == 5 || argc == 6) && !strcmp(argv[1],"--file"))
	{
		if (argc == 5)
		{
			//Create FileTest object and start sorting with selected type
			FileTest t( stoi(argv[2]), stoi(argv[3]), argv[4]);
			
			if (stoi(argv[2]) == 0)
			{
				t.RunTest<int>();
			}
			else if (stoi(argv[2]) == 1)
			{
				t.RunTest<float>();
			}
			else if (stoi(argv[2]) == 2)
			{
				t.RunTest<double>();
			}

		}
		else
		{
			//Create FileTest object and start sorting with selected type
			FileTest t(stoi(argv[2]), stoi(argv[3]), argv[4], argv[5]);

			if (stoi(argv[2]) == 0)
			{
				t.RunTest<int>();
			}
			else if (stoi(argv[2]) == 1)
			{
				t.RunTest<float>();
			}
			else if (stoi(argv[2]) == 2)
			{
				t.RunTest<double>();
			}
		}

	}
	else if (argc == 8 && !strcmp(argv[1], "--test"))
	{
		//Create Benchmark object and run benchmark for selected type
		Benchmark b(stoi(argv[2]), stoi(argv[3]), stoi(argv[4]), stoi(argv[5]), argv[6], stoi(argv[7]));

		if (stoi(argv[2]) == 0)
		{
			b.RunBenchmark<int>();
		}
		else if (stoi(argv[2]) == 1)
		{
			b.RunBenchmark<float>();
		}
		else if (stoi(argv[2]) == 2)
		{
			b.RunBenchmark<double>();
		}
	}
	else
	{
		cout << "Unknown command. Use --help to get information.\n";
	}
}