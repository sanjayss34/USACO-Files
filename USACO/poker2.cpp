#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
typedef struct Suit
{
	int a;
	int num;
}
Suit;

//DIVIDE AND CONQUER

int count (vector <Suit> vs)
{
	int minNum = 1000000;
	for (int a = 0; a < vs.size(); a++)
		minNum = min(minNum, vs[a].num);
	int sum = minNum;
	for (int a2 = 0; a2 < vs.size(); a2++)
		vs[a2].num -= minNum;
	//cout << "Suit: " << vs[0].a << ", " << "Size: " << vs.size() << ", " << minNum << "\n";
	vector <Suit> vNew;
	int b = 0;
	/*if (vs[b].a == 1)
		cout << vs[b].num << "\n";*/
	while (b < vs.size())
	{
		vNew.clear();
		while ((vs[b].num == 0) && (b < vs.size()))
			b++;
		while ((vs[b].num > 0) && (b < vs.size()))
		{
			vNew.push_back(vs[b]);
			b++;
		}
		if (vNew.size() > 0)
			sum += count(vNew);
	}
		/*if ((b < N) && (vs[b].num > 0))
		{
			vNew.clear();
			vNew.push_back(vs[b]);
			int b2 = b+1;
			while ((vs[b2].num > 0) && (b2 < N))
			{
				vNew.push_back(vs[b2]);
				b2++;
			}
			sum += count(vNew);
			b = b2;
			goto flag1;
		}*/
		
	return sum;
}

int main(void)
{
	ifstream infile ("poker.in");
	ofstream outfile ("poker.out");
	
	infile >> N;
	
	vector <Suit> sVec;
	Suit* sP = (Suit*) malloc(sizeof(Suit) * N);
	for (int i = 0; i < N; i++)
	{
		sP[i] = Suit();
		sP[i].a = i;
		infile >> sP[i].num;
	}
	for (int j = 0; j < N; j++)
		sVec.push_back(sP[j]);
	
	outfile << count(sVec) << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}