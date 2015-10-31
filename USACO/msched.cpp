#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int N;

typedef struct Cow
{
	int deadline;
	int amount;
}
Cow;

typedef struct Deadline
{
	//bool active;
	int maxAmount;
}
Deadline;

bool compareRatio(Cow const& c1, Cow const& c2)
{
	return (c1.amount/c1.deadline) > (c2.amount/c2.deadline);
}

bool compareA(Cow const& c1, Cow const& c2)
{
	return c1.amount > c2.amount;
}

int main(void)
{
	ifstream infile ("msched.in");
	ofstream outfile ("msched.out");
	infile >> N;
	Cow* cows = (Cow*) malloc(sizeof(Cow) * N);
	int maxD = 0;
	for (int i = 0; i < N; i++)
	{
		cows[i] = Cow();
		infile >> cows[i].amount >> cows[i].deadline;
		if (cows[i].deadline > maxD)
			maxD = cows[i].deadline;
	}
	
	sort(cows, cows+N, &compareA);
	/*Deadline* dList = (Deadline*) malloc(sizeof(Deadline) * 10000);
	for (int j = 0; j < 10000; j++)
	{
		dList[j] = Deadline();
		//dList[j].active = false;
		dList[j].maxAmount = 0;
	}*/
	
	int milked[10000] = {0};
	int total = 0;
	for (int j2 = 0; j2 < N; j2++)
	{
		/*if (cows[j2].amount > dList[cows[j2].deadline].maxAmount)
			dList[cows[j2].deadline].maxAmount = cows[j2].amount;*/
		int ind = cows[j2].deadline-1;
		while ((milked[ind] == 1) && (ind >= 0))
			ind--;
		if (ind >= 0)
		{
			total = total + cows[j2].amount;
			milked[ind] = 1;
		}
	}
	
	/*int total = 0;
	for (int k = 0; k < 10000; k++)
	{
		total = total + dList[k].maxAmount;
	}*/
	
	outfile << total << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}