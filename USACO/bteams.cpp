#include <iostream>
#include <fstream>
using namespace std;

int minDiff;
//int matchups[12][12][12];
int counter;
//int arrangement[12];

void findMin(int* sk, int* assign, int* taken, int ind, int* arrangement)
{
	if (ind == 12)
	{
		counter++;
		//matchups[assign[9]][assign[10]][assign[11]] = 1;
		int* groupSkills = (int*) malloc(sizeof(int) * 4);
		for (int a = 0; a < 12; a++)
		{
			if (a < 3)
				groupSkills[0] = groupSkills[0] + sk[assign[a]];
			else if (a < 6)
				groupSkills[1] = groupSkills[1] + sk[assign[a]];
			else if (a < 9)
				groupSkills[2] = groupSkills[2] + sk[assign[a]];
			else if (a < 12)
				groupSkills[3] = groupSkills[3] + sk[assign[a]];
		}
		sort(groupSkills, groupSkills + 4);
		if (groupSkills[3]-groupSkills[0] < minDiff)
		{
			minDiff = groupSkills[3] - groupSkills[0];
			//for (int x = 0; x < 12; x++)
				//arrangement[x] = assign[x];
		}
	}
	else
	{
		if (ind % 3 == 0)
		{
			//cout << "two\n";
			for (int c = 0; c < 12; c++)
			{
				if (taken[c] == 0)
				{
					assign[ind] = c;
					taken[c] = 1;
					findMin(sk, assign, taken, ind+1, arrangement);
					taken[c] = 0;
					//if (ind != 0)
						//break;
				}
			}
			//cout << "three\n";
		}
		else
		{
			//cout << "four\n";
			for (int b = assign[ind-1]+1; b < 12; b++)
			{
				if (taken[b] == 0)
				{
					//if ((ind % 3 != 2) || ((ind % 3 == 2) && (matchups[assign[ind-2][ind-1][b]] == 0)
					assign[ind] = b;
					taken[b] = 1;
					findMin(sk, assign, taken, ind+1, arrangement);
					taken[b] = 0;
				}
			}
			//cout << "five\n";
		}
	}
}

int main(void)
{
	ifstream infile;
	infile.open("bteams.in");
	ofstream outfile;
	outfile.open("bteams.out");
	int* skills = (int*) malloc(sizeof(int) * 12);
	for (int i = 0; i < 12; i++)
	{
		infile >> skills[i];
	}
	
	minDiff = 1000000000;
	counter = 0;
	int arrangement[12] = {0};
	//matchups = {0};
	//cout << "one\n";
	int* assignments = (int*) malloc(sizeof(int) * 12);
	int cowsTaken[12] = {0};
	findMin(skills, assignments, cowsTaken, 0, arrangement);
	//cout << counter << "\n";
	//for (int xx = 0; xx < 12; xx++)
		//cout << arrangement[xx] <<  " ";
	//cout << "\n";
	
	outfile << minDiff << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}