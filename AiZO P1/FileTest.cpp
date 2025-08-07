#include "FileTest.h"
#include <string.h>

//Constructor
FileTest::FileTest(int dT, int al, const string iF)
{
	dataType = dT;
	
	algorithm = al;
	
	inputFile = iF;
	
	outputFile = "nofile";
}

//Constructor that uses first constructor if there is oF(outputFile) given
FileTest::FileTest(int dT, int al, const string iF, const string oF) : FileTest(dT, al, iF)
{
	outputFile = oF;
}
