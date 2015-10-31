/*
General Idea: Use a double dimensional array (x, y) of integers that is N x 10. Index 0, 0
should contain the units digit of weight_0, index 0, 1 the corresponding tens
digit, etc. Then use a recursive function that will start at x = 0 and go to x = N-1
and will first have the digit as out of the particular subset of weights and call
itself with the next index and then will add the digit to the particular subset passed
to it, will check if the condition is violated (with a special function), and if
the addition is valid, will call itself with the next index. Arguments for this
recursive function: double dimensional array of weights, pointer of subset of weights,
index of the weight to be handled. Function should be void, should modify a global size
variable if an element is added to the subset. In this way, all 2^N subsets of the N
weights will be considered (including the empty/null set). Special function for
checking condition: the double dimensional array of weights can be passed, and the
pointer to the recursive function can contain the indices of weights in the subset;
this pointer can also be passed; the index in consideration should also be passed;
the the function can loop through each digit until all germane digits are covered;
for each digit, the function should check whether the sum of the digit at the index
in consideration and the corresponding digit in the subset's total weight is greater
than or equal to 10. The function can return a boolean value.
*/

#include <iostream>
#include <fstream>
using namespace std;

int maxWeight = 0;
int N = 0;

//bool isValid(int ww[][10], int inds2[20], int Ind2, int place2)
inline bool isValid(int ww[][10], int Ind2, int ss[10])
{
	/*int p = 0;
	while (p >= 0)
	{
		int sum = 0;
		int flag = 1;
		for (int k = 0; k < place2; k++)
		{
			if (ww[k][p] != -1)
			{
				flag = 0;
				sum = sum + ww[k][p];
			}
		}
		if (flag == 1)
			p = -1;
		else
		{
			sum = sum + ww[Ind2][p];
			if (sum >= 10)
				return false;
			else
				p++;
		}
	}
	
	return true;*/
	//cout << ww[Ind2] << " " << ww[Ind2][0] << "\n";
	for (int kk = 0; kk < ww[Ind2][0]; kk++)
	{
		if (ss[kk]+ww[Ind2][kk+1] >= 10)
			return false;
	}
	return true;
	
}

void calcMax(int w[][10], int inds[20], int Ind, int place, int sum[10])
{
	if (Ind < N)
	{
		calcMax(w, inds, Ind+1, place, sum);
		if (isValid(w, Ind, sum))
		{
			int newInds[20] = {0};
			for (int j = 0; j < place; j++)
			{
				newInds[j] = inds[j];
			}
			int newSum[10] = {0};
			for (int jj = 0; jj < max(place, w[Ind][0]); jj++)
			{
				if (jj < place)
					newSum[jj] = newSum[jj] + sum[jj];
				if (jj < w[Ind][0])
					newSum[jj] = newSum[jj] + w[Ind][jj+1];
			}
			newInds[place] = Ind;
			if (place+1 > maxWeight)
			{
				maxWeight = place+1;
				for (int jjj = 0; jjj < place+1; jjj++)
				{
					for (int j4 = 0; j4 < w[inds[jjj]][0]; j4++)
						cout << w[inds[jjj]][j4+1];
					cout << " ";
				}
				cout << "\n";
			}
			calcMax(w, newInds, Ind+1, place+1, newSum);
		}
	}
}

int main(void)
{
	ifstream infile;
	infile.open("escape.in");
	ofstream outfile ("escape.out");
	//int N = 0;
	infile >> N;
	int weights[N][10];
	for (int i = 0; i < N; i++)
	{
		char* weightIn = (char*) malloc(sizeof(char) * 10);
		infile >> weightIn;
		int inLen = strlen(weightIn);
		weights[i][0] = inLen;
		for (int ii = inLen-1; ii >= 0; ii--)
		{
			weights[i][inLen-ii] = ((int) weightIn[ii]) - 48;
		}
		/*for (int iii = inLen+1; iii < 10; iii++)
		{
			weights[i][iii] = -1;
		}*/
	}
	
	//int* indices = (int*) malloc(sizeof(int) * N);
	int indices[20] = {0};
	int s[10] = {0};
	calcMax(weights, indices, 0, 0, s);
	
	outfile << maxWeight << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}