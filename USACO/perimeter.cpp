#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 100;
int num = 0;

int main()
{
	int coord[MAX][MAX];
	int minX=MAX, minY=MAX, maxX=0, maxY=0;
	int perimeter = 0;

	ifstream infile;
	infile.open("perimeter.in");
	ofstream outfile("perimeter.out");
	
	char firstIn[10];
	infile.getline(firstIn, 10);
	num = atoi(firstIn);

	for (int i = 0; i < num; i++)
	{
		//cout << "one\n";
		//char instr[10];
		char instr[20];
		infile.getline(instr, 19);
		//cout << instr << "\n";
		int x = atoi(strtok(instr, " ")) - 1;
		int y = atoi(strtok(NULL, " ")) - 1;
		//cout << x << " " << y << "\n";
		//cout << "three\n";
		coord[x][y] = 1;
		if (x < minX) minX = x;
		if (x > maxX) maxX = x;
		if (y < minY) minY = y;
		if (y > maxY) maxY = y;
	}
	//cout << minX << " " << maxX << " " << minY << " " << maxY << "\n";


	//cout << "YYYYYYYYYY\n";
	for (int j = minY; j <= maxY; j++)
	{
		int length = 0;
		int firstK = -1;
		//int row[100];
		for (int k = minX; k <= maxX; k++)
		{
			if (coord[k][j] == 1)
			{
				//row[k] = 1;
				if (firstK == -1)
					firstK = k;
				length = k-firstK+1;
			}
			/*else
				row[k] = 0;*/
		}
		int actualL = length;
		int subtractions = 0;
		for (int k2 = firstK; k2 <= firstK+length-1; k2++)
		{
			if (coord[k2][j] != 1)
			{
				//cout << "62: " << k2 << " " << j <<  " " << firstK+length-1 << " " << firstK << "\n";
				actualL--;
			}
			else
			{
				if ((j < MAX-1) && (coord[k2][j+1] == 1))
				{
					//cout << "67: " << k2 << " " << j << "\n";
					subtractions++;
				}
				if ((j > 0) && (coord[k2][j-1] == 1))
				{
					subtractions++;
					//cout << "72: " << k2 << " " <<  j << "\n";
				}
			}
		}
		perimeter = perimeter + (2*actualL) - subtractions;
		//cout << j << " Length: " << actualL << " " << subtractions << " " << perimeter << "\n";
	}
		
		//cout << "XXXXXXXXXXXX\n";
		for (int j2 = minX; j2 <= maxX; j2++)
		{
			int length2 = 0;
			int firstK2 = -1;
			for (int k3 = minY; k3 <= maxY; k3++)
			{
				if (coord[j2][k3] == 1)
				{
					if (firstK2 == -1)
						firstK2 = k3;
					length2 = k3-firstK2+1;
				}
			}
			int actualL2 = length2;
			int subtractions2 = 0;
			for (int k4 = firstK2; k4 <= firstK2+length2-1; k4++)
			{
				if (coord[j2][k4] != 1)
				{
					//cout << "99: " << j2 << " " << k4 << "\n";
					actualL2--;
				}
				else
				{
					if ((j2 < MAX-1) && (coord[j2+1][k4] == 1))
					{
						subtractions2++;
						//cout << "106: " << j2 << " " << k4 << "\n";
					}
					if ((j2 > 0) && (coord[j2-1][k4] == 1))
					{
						subtractions2++;
						//cout << "111: " << j2 << " " << k4 << "\n";
					}
				}
			}
			perimeter = perimeter + (2*actualL2) - subtractions2;
			//cout << j2 << " Length: " << actualL2 << " " << subtractions2 << " " << perimeter << "\n";
		}
		for (int z = minX+1; z < maxX; z++)
		{
			for (int zz = minY+1; zz < maxY; zz++)
			{
				if (coord[z][zz] != 1)
				{
					if ((coord[z+1][zz] == 1) && (coord[z-1][zz] == 1) && (coord[z][zz+1] == 1) && (coord[z][zz-1] == 1))
						perimeter = perimeter - 4;
				}
			}
		}

	/*for (int j2 = minX; j2 < maxX; j2++)
	{
		for (int k2 = 0; k2 < 100; k2++)
		{
			if ((coord[j2][k2] == 1) && (coord[j2][k2+1] == 1))
				perimeter++;
		}
	}*/
	
	//cout << "two\n";
	/*for (int ii = maxY; ii > minY-1; ii--)
	{
		for (int jj = minX; jj < maxX+1; jj++)
			if (coord[jj][ii] == 1)
			{
				outfile << "1 ";
				cout << jj << " " << ii << "\n";
			}
			else
				outfile << "0 ";
		outfile << "\n";
	}*/

	outfile << perimeter << "\n";
	infile.close();
	outfile.close();

	return 0;
}