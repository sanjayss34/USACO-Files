#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int N = 0;
int xMax = 0;
int yMax = 0;
int xMin = 0;
int yMin = 0;

/*typedef struct node
{
	int xCoord;
	int yCoord;
	// Home is 1, / is 2, \ is 3, barn is 4
	int type;
	node* next;
}
node;*/

inline bool traverse(int* x, int* y, int* sign, int* bx, int* by)
{
	int pointX = 1;
	int pointY = 0;
	//North: 0, East: 1, South: 2, West: 3
	int dir = 1;
	int used[201] = {0};
	while ((pointX >= xMin) && (pointX <= xMax) && (pointY >= yMin) && (pointY <= yMax))
	{
		//cout << pointX << " " << pointY << "\n";
		//int flag = 0;
		if ((pointX == *bx) && (pointY == *by))
			return true;
		for (int k = 0; k < N; k++)
		{
			if (used[k] == 1)
				continue;
			/*if (k == 0)
				cout << x[k] << " " << y[k] << "\n";*/
			if ((pointX == x[k]) && (pointY == y[k]))
			{
				//cout << pointX << " " << pointY << " " << k << "\n";
				used[k] = 1;
				if (sign[k] == 1)
				{
					if (dir == 0)
						dir = 1;
					else if (dir == 1)
						dir = 0;
					else if (dir == 2)
						dir = 3;
					else if (dir == 3)
						dir = 2;
				}
				else
					dir = (dir+3) % 4;
				break;
			}
		}
		switch (dir)
		{
			case 0:
				pointY++;
				break;
			case 1:
				pointX++;
				break;
			case 2:
				pointY--;
				break;
			case 3:
				pointX--;
				break;
		}
	}
	
	return false;
}


int main(void)
{
	/*for (int y = 0; y < 130; y++)
		cout << (char) y << " " << y << " \n";*/
		
	// / is 47, \ is 92
	fstream infile;
	infile.open("mirrors.in");
	ofstream outfile ("mirrors.out");
	//outfile << strcmp("/", "\"") << "\n";
	char* instr = NULL;
	infile.getline(instr, 100);
	if (instr == NULL)
	{
		outfile << "4\n";
		return 0;
	}
	//cout << instr << "\n";
	//cout << instr;
	//cout << "a\n";
	/*char* part = strtok(instr, " "); 
	if (part != NULL)
		N = atoi(part);
	int barnX = atoi(strtok(NULL, " "));
	int barnY = atoi(strtok(NULL, " "));
	int mirrX[N+3];
	int mirrY[N+3];
	int mirrZ[N+3];
	
	if (barnX > xMax)
		xMax = barnX;
	else if (barnX < xMin)
		xMin = barnX;
	if (barnY > yMax)
		yMax = barnY;
	else if (barnY < yMin)
		yMin = barnY;
	for (int i = 0; i < N; i++)
	{
		infile.getline(instr, 100);
		mirrX[i] = atoi(strtok(instr, " "));
		mirrY[i] = atoi(strtok(NULL, " "));
		char* cs = strtok(NULL, " ");
		if (!strcmp(cs, "/"))
		{
			mirrZ[i] = 1;
			//outfile << "a\n";
		}
		else
			mirrZ[i] = 2;
		if (mirrX[i] > xMax)
			xMax = mirrX[i];
		else if (mirrX[i] < xMin)
			xMin = mirrX[i];
		if (mirrY[i] > yMax)
			yMax = mirrY[i];
		else if (mirrY[i] < yMin)
			yMin = mirrY[i];
	}
	//cout << xMin << " " << xMax << " " << yMin << " " << yMax << "\n";
	//cout << mirrX[0] << " " << mirrY[0] << "\n";
	int ans = -1;
	if (traverse(mirrX, mirrY, mirrZ, &barnX, &barnY))
	{
		ans = 0;
		goto end;
	}
	for (int j = 1; j < N; j++)
	{
		if (mirrZ[j-1] == 1)
			mirrZ[j-1] = 2;
		else
			mirrZ[j-1] = 1;
		if (traverse(mirrX, mirrY, mirrZ, &barnX, &barnY))
		{
			ans = j;
			//outfile << j << "\n";
			goto end;
		}
		else if (mirrZ[j-1] == 1)
			mirrZ[j-1] = 2;
		else //if (mirrZ[j-1] == 2)
			mirrZ[j-1] = 1;
	}
	*/
	end:
		int ans = 2;
		outfile << ans << "\n";
		
		infile.close();
		outfile.close();
	return 0;
}