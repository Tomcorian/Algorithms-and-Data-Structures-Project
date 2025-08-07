#include "Benchmark.h"
#include "Timer.h"

//Constructor
Benchmark::Benchmark(int dT, int iS, int al, int nOI, const string oF, int dO)
{
	instanceSize = iS;
	dataType = dT;
	algorithm = al;

	outputFile = oF;

	numberOfIterations = nOI;
	dataOrder = dO;
}