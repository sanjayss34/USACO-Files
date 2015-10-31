#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAXN 50000

typedef struct cow
{
	int height;
	int pos;
}
cow;

int N, D;

bool compareH(cow const& l, cow const& r)
{
	return l.height < r.height;
}

bool compareP(cow const& l, cow const& r)
{
	return l.pos < r.pos;
}

int find(cow* list, int index)
{
	int lower = index+1;
	int higher = N-1;
	int mid = (higher+lower)/2;
	while (higher-lower > 1)
	{
		if (2*list[index].height <= list[mid].height)
		{
			higher = mid;
			mid = (higher+lower)/2;
		}
		else
		{
			lower = mid;
			mid = (higher+lower)/2;
		}
		//cout << list[mid].height << "\n";
	}
	if (list[mid].height < 2*list[index].height)
		return mid+1;
	return mid;
}
			

int main(void)
{
	ifstream infile ("crowded.in");
	ofstream outfile ("crowded.out");
	infile >> N >> D;
	cow* c1 = (cow*) malloc(sizeof(cow) * N);
	//cow* c2 = (cow*) malloc(sizeof(cow) * N);
	
	for (int i = 0; i < N; i++)
	{
		c1[i] = cow();
		infile >> c1[i].pos >> c1[i].height;
		/*c2[i] = cow();
		c2[i].pos = c1[i].pos;
		c2[i].height = c2[i].height;*/
		
	}
	
	//cout << "one\n";
	
	sort(c1, c1+N, &compareH);
	
	//cout << c1[0].height << c1[1].height << "\n";
	
	int count = 0;
	//cout << "three\n";
	for (int j = 0; j < N; j++)
	{
		int ind = find(c1, j);
		if (c1[ind].height < 2*c1[j].height)
			continue;
		int flag1 = 0;
		int flag2 = 0;
		
		//cout << "two\n";
		
		while ((flag1+flag2 < 2) && (ind < N))
		{
			if ((c1[ind].pos <= c1[j].pos+D) && (c1[ind].pos > c1[j].pos))
				flag1 = 1;
			else if ((c1[ind].pos >= c1[j].pos-D) && (c1[ind].pos < c1[j].pos))
				flag2 = 1;
			ind++;
		}
		
		if (flag1 + flag2 == 2)
			count++;
	}
	
	outfile << count << "\n";
	
	return 0;
}