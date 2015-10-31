#include <fstream>
using namespace std;

int main(void)
{
	ifstream infile;
	infile.open("cowrow.in");
	ofstream outfile ("cowrow.out");
	int N = 0;
	infile >> N;
	int ids[N];
	for (int i = 0; i < N; i++)
	{
		infile >> ids[i];
	}
	
	int greatest = 0;
	for (int j = 0; j < N; j++)
	{
		int val = ids[j];
		int skip = -1;
		int count = 1;
		for (int k = j+1; k < N; k++)
		{
			if (ids[k] == val)
				count++;
			else if (skip == -1)
				skip = ids[k];
			else if (ids[k] != skip)
				break;
		}
		if (count > greatest)
			greatest = count;
	}
	
	outfile << greatest << "\n";
	infile.close();
	outfile.close();
	
	return 0;
}