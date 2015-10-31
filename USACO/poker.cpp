#include <fstream>
//#include <iostream>
using namespace std;

int cards[100000] = {0};
int N = 100;
int numZ = 0;

int count (int start, int end)
{
	/*if ((numZ == N) || (start == end))
	{
		cout << "say\n";
		return 0;
	}*/
	int result = 0;
	int flag = 0;
	point1:
		for (int i = start; i <= end; i++)
		{
			/*if (numZ == N)
				return result;*/
			if ((cards[i] == 0) && (flag != 0))
			{
				numZ++;
				if (i != start)
				{
					//cout << "hello1\n";
					result++;
					//cout << start << " " << i-1 << " " << end << "\n";
					if (numZ == N)
						return result;
					if ((i-1) == start)
					{
						result += cards[i-1];
						cards[i-1] = 0;
					}
					else
						result += count(start, i-1);
					if ((i+1) == end)
					{
						result += cards[i+1];
						cards[i+1] = 0;
					}
					else
						result += count(i+1, end);
					//return result;
					//cout << "hello2\n";
					//flag = 0;
					//goto point1;
					return result + count(start, end);
				}
				else
					start++;
			}
			else if (cards[i] != 0)
			{
				//cout << "hello3\n";
				cards[i]--;
				flag++;
			}
			else
			{
				numZ++;
				if (numZ == N)
					return result;
			}
		}
		if (flag > 0)
		{
			result++;
			/*if (numZ == N)
				return result;*/
			flag = 0;
			goto point1;
			//return result + count(start, end);
		}
	//cout << cards[0] << " " << cards[1] << " " << cards[2] << " " << cards[3] << " " << cards[4] << "\n";
	//cout << result << "\n";
	return result;
}

int main(void)
{
	ifstream infile;
	infile.open("poker.in");
	ofstream outfile ("poker.out");
	infile >> N;
	//cout << N << "\n";
	for (int j = 0; j < N; j++)
	{
		infile >> cards[j];
		//cout << cards[j] << "\n";
	}
	
	/*int moves = 0;
	int flag2 = 0;
	
	//point2:
	while (numZ < N)
	{
		point2:
		for (int k = 0; k < N; k++)
		{
			if (cards[k] == 0)
			{
				numZ++;
				if (flag2 == 1)
				{
					moves++;
					flag2 = 0;
					goto point2;
				}
			}
			else
			{
				cards[k]--;
				flag2 = 1;
			}
		}
		if (flag2 != 0)
		{
			flag2 = 0;
			moves++;
			goto point2;
		}
	}*/
	
	outfile << count(0, N-1) << "\n";
	
	return 0;
}