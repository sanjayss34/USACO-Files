#include <iostream>
#include <fstream>

//Information on <cmath> from http://www.cplusplus.com/reference/cmath/
#include <cmath>
using namespace std;

int main(void)
{
	ifstream infile;
	infile.open("combo.in");
	ofstream outfile;
	outfile.open("combo.out");
	int N = 0;
	infile >> N;
	int johnCombo[3] = {0};
	int masterCombo[3] = {0};
	infile >> johnCombo[0] >> johnCombo[1] >> johnCombo[2];
	infile >> masterCombo[0] >> masterCombo[1] >> masterCombo[2];
	/*for (int a = 0; a < 3; a++)
	{
		johnCombo[a]--;
		masterCombo[a]--;
	}*/
	int* tryCombo = (int*) malloc(sizeof(int) * 3);
	int count = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				tryCombo[0] = i;
				tryCombo[1] = j;
				tryCombo[2] = k;
				if (((abs(tryCombo[0]-johnCombo[0]) <= 2) || (abs((tryCombo[0]+N)-johnCombo[0]) <= 2) || (abs(tryCombo[0]-(johnCombo[0]+N)) <= 2)) && ((abs(tryCombo[1]-johnCombo[1]) <= 2) || (abs((tryCombo[1]+N)-johnCombo[1]) <= 2) || (abs(tryCombo[1]-(johnCombo[1]+N)) <= 2)) && ((abs(tryCombo[2]-johnCombo[2]) <= 2) || (abs((tryCombo[2]+N)-johnCombo[2]) <= 2) || (abs(tryCombo[2]-(johnCombo[2]+N)) <= 2)))
					count++;
				else if (((abs(tryCombo[0]-masterCombo[0]) <= 2) || (abs((tryCombo[0]+N)-masterCombo[0]) <= 2) || (abs(tryCombo[0]-(masterCombo[0]+N)) <= 2)) && ((abs(tryCombo[1]-masterCombo[1]) <= 2) || (abs((tryCombo[1]+N)-masterCombo[1]) <= 2) || (abs(tryCombo[1]-(masterCombo[1]+N)) <= 2)) && ((abs(tryCombo[2]-masterCombo[2]) <= 2) || (abs((tryCombo[2]+N)-masterCombo[2]) <= 2) || (abs(tryCombo[2]-(masterCombo[2]+N)) <= 2)))
					count++;
			}
		}
	}
	
	outfile << count << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}