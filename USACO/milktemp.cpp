#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//This comparison function is modeled on an example for qsort() from http://www.cplusplus.com/reference/cstdlib/qsort/.
int comp(const void* num1, const void* num2)
{
	return *(int*) num2 - *(int*) num1;
}

int main(void)
{
	ifstream infile;
	infile.open("milktemp.in");
	ofstream outfile;
	outfile.open("milktemp.out");
	int N = 0;
	int X = 0;
	int Y = 0;
	int Z = 0;
	infile >> N >> X >> Y >> Z;
	int* starts = (int*) malloc(sizeof(int) * N);
	int* ends = (int*) malloc(sizeof(int) * N);
	int minA = 1000000000;
	int maxB = 0;
	for (int i = 0; i < N; i++)
	{
		infile >> starts[i] >> ends[i];
		if (starts[i] < minA)
			minA = starts[i];
		if (ends[i] > maxB)
			maxB = ends[i];
	}
	int* values = (int*) malloc(sizeof(int) * (maxB-minA+1));
	for (int a = 0; a < maxB-minA+1; a++)
		values[a] = 0;
	for (int j = minA; j <= maxB; j++)
	{
		for (int k = 0; k < N; k++)
		{
			if (starts[k] > j)
				values[j] = values[j] + X;
			else if (ends[k] < j)
				values[j] = values[j] + Z;
			else
				values[j] = values[j] + Y;
		}
	}
	
	//Information on qsort() from http://www.cplusplus.com/reference/cstdlib/qsort/
	qsort(values, maxB-minA+1, sizeof(int), comp);
	
	outfile << values[0] << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}