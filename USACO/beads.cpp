/*
TASK: beads
LANG: C++
*/

#include <fstream>
//#include <iostream>
using namespace std;

int main(void)
{
	ifstream infile;
	infile.open("beads.in");
	ofstream outfile ("beads.out");
	int N = 0;
	//cin >> N;
	char beadstr[360];
	infile.getline(beadstr, 5);
	N = atoi(beadstr);
	infile.getline(beadstr, 356);
	//cin >> beadstr;
	int max = 0;
	int maxI = N;
	for (int i = 0; i < N; i++)
	{
		//outfile << beadstr[i] << " ";
		/*if (i == N-1)
			cout << "yes\n";*/
		char b = beadstr[i];
		int next = i;
		int count = 0;
		char color = 'c';
		do
		{
			b = beadstr[next];
			if (color == 'c')
			{
				if (b != 'w')
					color = b;
				count++;
				if (next == N-1)
					next = 0;
				else
					next++;
			}
			else
			{
				if ((b == color) || (b == 'w'))
				{
					count++;
					if (next == N-1)
						next = 0;
					else
						next++;
				}
				else
					break;
			}
		} while (next != i);
		
		int stop = next -1;
		if (next == 0)
			stop = N-1;
		if (i == 0)
			next = N-1;
		else
			next = i-1;
		color = 'c';
		while (next != stop)
		{
			b = beadstr[next];
			if (color == 'c')
			{
				if (b != 'w')
					color = b;
				count++;
				if (next == 0)
					next = N-1;
				else
					next--;
			}
			else
			{
				if ((b == color) || (b == 'w'))
				{
					count++;
					if (next == 0)
						next = N-1;
					else
						next--;
				}
				else
					break;
			}
		}
		/*if ((i == 29) || (i == 30))
			outfile << count << "\n";*/
		if (count > max)
		{
			max = count;
			maxI = i;
			if (max == N)
				break;
		}
	}
	//cout << max << "\n";
	outfile << max << "\n";

	infile.close();
	outfile.close();

	return 0;
}