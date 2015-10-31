#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

typedef struct Rel
{
	int v1;
	int v2;
	int type;
}
Rel;

int main(void)
{
	ifstream infile;
	infile.open("assign.in");
	ofstream outfile("assign.out");
	int N;
	infile >> N;
	int K;
	infile >> K;
	Rel* relations = (Rel*) malloc(sizeof(Rel) * K);
	int* breeds = (int*) malloc(sizeof(int) * N);
	for (int i = 0; i < K; i++)
	{
		if (i < N)
			breeds[i] = 0;
		relations[i] = Rel();
		infile >> relations[i].v1 >> relations[i].v2;
		relations[i].v1--;
		relations[i].v2--;
		char typ = 'A';
		infile >> typ;
		if (typ == 'S')
			relations[i].type = 1;
		else
			relations[i].type = -1;
	}
	int index = 0;
	while ((index >= 0) && (index < N))
	{
		breeds[index]++;
		if (breeds[index] > 3)
		{
			breeds[index] = 0;
			index--;
		}
		int flag = 0;
		for (int j = 0; j < K; j++)
		{
			if ((relations[j].v1 == index) || (relations[j].v2 == index))
			{
				if ((relations[j].v1 <= index) && (relations[j].v2 <= index))
				{
					if (relations[j].type = 1)
					{
						if (breeds[relations[j].v1] != breeds[relations[j].v2])
						{
							flag = 1;
							break;
						}
					}
					else
					{
						if (breeds[relations[j].v1] == breeds[relations[j].v2])
						{
							flag = 1;
							break;
						}
					}
				}
			}
		}
		