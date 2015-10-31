#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef struct Gift
{
	int P;
	int S;
	double ratio;
};

bool gift_compare(Gift g1, Gift g2)
{
	//return g1.ratio < g2.ratio;
	return (g1.P+g1.S) < (g2.P+g2.S);
};

bool gift_compare2(Gift g1, Gift g2)
{
	return g1.P < g2.P;
}

int main(void)
{
	ifstream infile;
	infile.open("gifts.in");
	ofstream outfile;
	outfile.open("gifts.out");
	int N = 0;
	infile >> N;
	int B = 0;
	infile >> B;
	/*int* P = (int*) malloc(sizeof(int) * N);
	int* S = (int*) malloc(sizeof(int) * N);
	double* ratios = (double*) malloc(sizeof(int) * N);*/
	Gift* gifts = (Gift*) malloc(sizeof(Gift) * N);
	for (int i = 0; i < N; i++)
	{
		infile >> gifts[i].P >> gifts[i].S;
		gifts[i].ratio = ((double) gifts[i].P)/((double) gifts[i].P+gifts[i].S);
	}
	
	sort(gifts, gifts+N, &gift_compare);
	int totCost = 0;
	int numGifts = 0;
	//int index = 0;
	//cout << gifts[0].P << " " << gifts[0].S << "\n";
	Gift* chosenGifts = (Gift*) malloc(sizeof(Gift) * N);
	while ((totCost < B) && (numGifts < N))
	{
		if (totCost + gifts[numGifts].P + gifts[numGifts].S > B)
			break;
		totCost += gifts[numGifts].P + gifts[numGifts].S;
		chosenGifts[numGifts].P = gifts[numGifts].P;
		chosenGifts[numGifts].S = gifts[numGifts].S;
		chosenGifts[numGifts].ratio = gifts[numGifts].ratio;
		cout << gifts[numGifts].P << " " << gifts[numGifts].S << "\n";
		cout << totCost << "\n";
		numGifts++;
		//index++;
	}
	
	sort(chosenGifts, chosenGifts+numGifts, &gift_compare2);
	
	totCost -= chosenGifts[numGifts-1].P/2;
	cout << totCost << "\n";
	
	while ((totCost < B) && (numGifts < N))
	{
		if (totCost + gifts[numGifts].P + gifts[numGifts].S > B)
			break;
		totCost += gifts[numGifts].P + gifts[numGifts].S;
		cout << gifts[numGifts].P << " " << gifts[numGifts].S << "\n";
		numGifts++;
	}
	
	outfile << numGifts << "\n";
	
	return 0;
}