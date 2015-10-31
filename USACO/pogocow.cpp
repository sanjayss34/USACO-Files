#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N;
int maxScore;

typedef struct Cow
{
	int loc;
	int points;
}
Cow;

bool compareL(Cow const& c1, Cow const& c2)
{
	return c1.loc < c2.loc;
}

void move(Cow* c, int index, int distance, int score, int dir, int prevLoc)
{
	if ((index == N-1) && (dir == 1))
	{
		if (abs(c[index].loc - prevLoc) >= distance)
			score = score + c[index].points;
		maxScore = max(score, maxScore);
		return;
	}
	else if ((index == 0) && (dir == -1))
	{
		if (abs(c[index].loc - prevLoc) >= distance)
			score = score + c[index].points;
		maxScore = max(score, maxScore);
		return;
	}
	move(c, index+dir, distance, score, dir, prevLoc);
	if (prevLoc != -1)
	{
		if (abs(c[index].loc - prevLoc) >= distance)
		{
			if ((index + dir >= 0) && (index + dir < N))
			{
				move(c, index+dir, max(distance, abs(c[index].loc-prevLoc)), score + c[index].points, dir, c[index].loc);
			}
			score = score + c[index].points;
		}
	}
	else
		move(c, index+dir, distance, score+c[index].points, dir, c[index].loc);
	
}
int main(void)
{
	ifstream infile ("pogocow.in");
	ofstream outfile ("pogocow.out");
	
	infile >> N;
	Cow* cows = (Cow*) malloc(sizeof(Cow) * N);
	for (int i = 0; i < N; i++)
	{
		cows[i] = Cow();
		infile >> cows[i].loc >> cows[i].points;
	}
	sort(cows, cows+N, &compareL);
	
	move(cows, 0, 0, 0, 1, -1);
	move(cows, 0, 0, 0, -1, -1);
	
	outfile << maxScore << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}