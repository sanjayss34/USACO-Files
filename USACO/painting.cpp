#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

typedef struct Enc
{
	int x1;
	int x2;
	int y1;
	int y2;
	long long int area;
}
Enc;

int N;

bool compareA(Enc const& e1, Enc const& e2)
{
	return e1.area < e2.area;
}

int main(void)
{
	ifstream infile ("painting.in");
	ofstream outfile ("painting.out");
	infile >> N;
	Enc* eList = (Enc*) malloc(sizeof(Enc) * N);
	for (int i = 0; i < N; i++)
	{
		eList[i] = Enc();
		infile >> eList[i].x1 >> eList[i].y1 >> eList[i].x2 >> eList[i].y2;
		eList[i].area = (long long) (eList[i].x2-eList[i].x1)*(eList[i].y2-eList[i].y1);
	}
	
	sort(eList, eList+N, &compareA);
	//cout << eList[0].area << " " << eList[N-1].area << "\n";
	
	int contained = 0;
	int finished[50000] = {0};
	for (int j = N-1; j >= 0; j--)
	{
		if (finished[j] == 1)
			continue;
		for (int k = j-1; k >= 0; k--)
		{
			if ((eList[k].x1 > eList[j].x1) && (eList[k].x2 < eList[j].x2))
			{
				if ((eList[k].y1 > eList[j].y1) && (eList[k].y2 < eList[j].y2))
				{
					contained++;
					finished[k] = 1;
				}
			}
		}
	}
	
	outfile << N - contained << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}