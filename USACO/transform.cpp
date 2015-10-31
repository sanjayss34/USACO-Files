/*
PROB: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int* convert(int len, int* coords, int option)
{
	int* newCoords = (int*) malloc(sizeof(int) * 2);
	switch (option)
	{
		case 1:
			newCoords[0] = coords[1];
			newCoords[1] = (len-1) - coords[0];
			break;
		case 2:
			/*newCoords[0] = (len-1) - coords[0];
			newCoords[0] = (len-1) - coords[1];*/
			newCoords = convert(len, convert(len, coords, 1), 1);
			break;
		case 3:
			newCoords = convert(len, convert(len, coords, 2), 1);
			break;
		case 4:
			newCoords[0] = coords[0];
			newCoords[1] = (len-1) - coords[1];
			break;
	}
	
	return newCoords;
}

int main(void)
{
	ifstream infile;
	infile.open("transform.in");
	ofstream outfile ("transform.out");
	int N = 0;
	infile >> N;
	char grid1[N][N];
	char grid2[N][N];
	int flags[6] = {0};
	for (int i = 0; i < N; i++)
	{
		for (int ii = 0; ii < N; ii++)
		{
			infile >> grid1[i][ii];
			//cout << grid1[i][ii];
		}
		//cout << "\n";
	}
	//cout << "\n\n";
	for (int j = 0; j < N; j++)
	{
		for (int jj = 0; jj < N; jj++)
		{
			infile >> grid2[j][jj];
			//cout << grid2[j][jj];
		}
		//cout << "\n";
	}
	//cout << "\n\n";
	
	for (int k = 0; k < N; k++)
	{
		for (int kk = 0; kk < N; kk++)
		{
			//int combFlag = 1;
			//cout << "here1\n";
			for (int f = 0; f < 3; f++)
			{
				if (flags[f] == 0)
				{
					int pair[2];
					pair[0] = k;
					pair[1] = kk;
					int* newPair = (int*) malloc(sizeof(int)*2);
					//cout << "here2\n";
					newPair = convert(N, pair, f+1);
					//cout << newPair[0] << " " << newPair[1] << "\n";
					if (grid1[k][kk] != grid2[newPair[0]][newPair[1]])
						flags[f] = 1;
				}
				/*if ((flags[4] == 0) && (combFlag == 1))
				{
					int couple[2];
					couple[0] = k;
					couple[1] = kk;
					int* newCouple = (int*) malloc(sizeof(int) * 2);
					newCouple = convert(N, couple, 4);
					int* thirdCouple = (int*) malloc(sizeof(int) * 2);
					thirdCouple = convert(N, newCouple, f+1);
					if (grid1[k][kk] == grid2[thirdCouple[0]][thirdCouple[1]])
						combFlag = 0;
				}*/
			}
			
			/*if (flags[4] == 0)
			{
				flags[4] = combFlag;
			}*/
			
			if (flags[3] == 0)
			{
				int startTwo[2];
				startTwo[0] = k;
				startTwo[1] = kk;
				int* endTwo = (int*) malloc(sizeof(int) * 2);
				endTwo = convert(N, startTwo, 4);
				if (grid1[k][kk] != grid2[endTwo[0]][endTwo[1]])
					flags[3] = 1;
			}
			
			if (flags[5] == 0)
			{
				if (grid1[k][kk] != grid2[k][kk])
					flags[5] = 1;
			}
		}
	}
	
	int invalid = 0;
	for (int fl = 0; fl < 6; fl++)
	{
		if (fl == 4)
		{
			for (int rot = 0; rot < 3; rot++)
			{
				bool success = true;
				for (int m = 0; m < N; m++)
				{
					for (int mm = 0; mm < N; mm++)
					{
						int couple[2];
						couple[0] = m;
						couple[1] = mm;
						int* newCouple = (int*) malloc(sizeof(int) * 2);
						newCouple = convert(N, couple, 4);
						int* thirdCouple = (int*) malloc(sizeof(int) * 2);
						thirdCouple = convert(N, newCouple, rot+1);
						if (grid1[m][mm] != grid2[thirdCouple[0]][thirdCouple[1]])
						{
							success = false;
							break;
						}
					}
				}
				if (success)
				{
					outfile << "5\n";
					invalid = 1;
					break;
				}
			}
		}
		else if (flags[fl] == 0)
		{
			outfile << fl+1 << "\n";
			invalid = 1;
			break;
		}
	}
	
	if (invalid == 0)
		outfile << "7\n";
	
	infile.close();
	outfile.close();
	
	
	return 0;
}