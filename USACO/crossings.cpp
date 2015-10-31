#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	ifstream infile;
	char whichFile[30];
	cin.getline(whichFile, 29);
	infile.open(whichFile);
	ofstream outfile ("crossings.out");
	char nstr[10];
	infile.getline(nstr, 9);
	const int N = atoi(nstr);
	double x0[N+1];
	double x1[N+1];
	
	//cout << N << "\n";
	for (int i = 0; i < N; i++)
	{
		char inputAB[18];
		infile.getline(inputAB, 17);
		x0[i] = atof(strtok(inputAB, " "));
		x1[i] = atof(strtok(NULL, " "));
	}
	
	/*for (int ii = 0; ii < N; ii++)
	{
		cout << x0[ii] << " " << x1[ii] << "\n";
	}*/
	int notSafe = 0;
	int notCheck[N];
	for (int j = 0; j < N; j++)
	{
		if (notCheck[j] == -1)
			continue;
		else
		{
		//int flag = 0;
			for (int k = 0; k < N; k++)
			{
				if (k == j)
					continue;
				//Help on equation of a line / with programming from Stack Overflow
				//y = y1 + ((y2-y1)/(x2-x1))*(x-x1)
				if (x0[j] == x1[j])
				{
					//cout << j << " Choice 1\n";
					if (x1[k] != x0[k])
					{
						int val = (double) ((1-0)/(x1[k]-x0[k]))*(x0[j]-x0[k]);
						if ((val > 0) && (val < 1))
						{
							if (notCheck[k] == -1)
								notSafe++;
							else
								notSafe += 2;
							notCheck[k] = -1;
							notCheck[j] = -1;
							//flag = 1;
							break;
						}
						/*else
							continue;*/
					}
				}
			
				else if ((1/(x1[j]-x0[j])) == (1/(x1[k]-x0[k])))
					continue;
				//y1+((y2-y1)/(x2-x1))*(x-x1) = y3 + ((y4-y3)/(x4-x3))*(x-x3)
				//Let y1=y3=0
				//Let y2=y4=1
				//Equation of j line: y = (1/(x1[j]-x0[j])) * (x-x0[j])
				//(x/(x1[j]-x0[j]))-(x0[j]/(x1[j]-x0[j])) = (x/(x1[k]-x0[k])) - (x0[k]/(x1[k]-x0[k]))
				//(x) * ( (1 / (x1[j]-x0[j])) - (1 / (x1[k]-x0[k])) ) = (x0[j]/(x1[j]-x0[j])) - (x0[k]/(x1[k]-x0[k]))
				else
				{
					double xVal = (double) ( (x0[j]/(x1[j]-x0[j])) - (x0[k]/(x1[k]-x0[k])) ) / ( (1.0 / (x1[j]-x0[j])) - (1.0 / (x1[k]-x0[k])) );
					double yVal = (double) 1 + ((1.0/(x1[j]-x0[j])) * (xVal-x1[j]));
					//cout << j << " " << k << " " << xVal << " " << yVal << "\n";
					if ((yVal > 0.0) && (yVal < 1.0))
					{
						//cout << j << " " << xVal << " " << yVal << " " << k << " Choice 3\n";
						if (notCheck[k] == -1)
							notSafe++;
						else
							notSafe += 2;
						notCheck[k] = -1;
						notCheck[j] = -1;
						//flag = 1;
						break;
					}
				}
			}
		}
	}
	
	outfile << N - notSafe << "\n";
	
	return 0;
}