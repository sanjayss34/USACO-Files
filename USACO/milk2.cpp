/*
PROB: milk2
LANG: C++
*/

#include <fstream>
#include <iostream>
using namespace std;

int calcIdle(int* starts, int* ends, int iS, int iE, int ind, int lim)
{
	if ((starts[ind] < iE) && (ends[ind] > iS))
	{
		return max(calcIdle(starts, ends, ends[ind], iE, 0, lim), calcIdle(starts, ends, iS, starts[ind], 0, lim));
	}
	
	if (ind < lim-1)
		return calcIdle(starts, ends, iS, iE, ++ind, lim);
	
	return iE-iS;
}
	/*int result = iE-iS;
	for (int jj = 0; jj < lim; jj++)
	{
		if ((starts[jj] < iE) && (ends[jj] > iS))
		{
			int opt1 = calcIdle(starts, ends, ends[jj], iE, lim);
			int opt2 = calcIdle(starts, ends, iS, starts[jj], lim);
			if (opt1 > opt2)
			{
				result = opt1;
				iS = ends[jj];
			}
			else
			{
				result = opt2;
				iE = starts[jj];
			}
			if (iE-(ends[jj]) > (starts[jj])-iS)
				iS = ends[jj];
			else
				iE = starts[jj];
		}
	}
	return result;
}*/

int main(void)
{
	ifstream infile;
	infile.open("milk2.in");
	ofstream outfile ("milk2.out");
	int start = 1000000, end = 0;
	int N = 0;
	infile >> N;
	int sTimes[N];
	int eTimes[N];
	//cout << N << " " << max(1,2) << "\n";
	int len = N;
	//cout << "a\n";
	//int lastI = 0;
	for (int i = 0; i < N; i++)
	{
		infile >> sTimes[i] >> eTimes[i];
		int flag = 0;
		/*for (int ii = 0; ii < i; ii++)
		{
			if ((sTimes[i] < sTimes[ii]) && (eTimes[i] >= sTimes[ii]))
			{
				sTimes[ii] = sTimes[i];
				eTimes[ii] = max(eTimes[ii], eTimes[i]);
				//cout << "one\n";
				flag = 1;
			}
			if ((sTimes[i] <= eTimes[ii]) && (eTimes[i] > eTimes[ii]))
			{
				eTimes[ii] = eTimes[i];
				sTimes[ii] = min(sTimes[ii], sTimes[i]);
				//cout << "two\n";
				flag = 1;
			}
		}*/
		if (eTimes[i]-sTimes[i] == 912)
			cout << "Yes!!\n";
		/*if (i == N-1)
			cout << sTimes[i] << " " << eTimes[i];*/
		start = min(sTimes[i], start);
		end = max(eTimes[i], end);
		/*if (i > lastI)
		{
			len++;
			lastI = i;
		}*/
		/*if (flag == 1)
		{
			//cout << "one\n";
			i--;
		}
		else
			len++;*/
	}
	
	for (int k = 0; k < N; k++)
	{
		for (int kk = 0; kk < N; kk++)
		{
			if ((sTimes[k] < sTimes[kk]) && (eTimes[k] >= sTimes[kk]))
			{
				sTimes[kk] = sTimes[k];
				eTimes[kk] = max(eTimes[kk], eTimes[k]);
				//cout << "one\n";
				//flag = 1;
			}
			if ((sTimes[k] <= eTimes[kk]) && (eTimes[k] > eTimes[kk]))
			{
				eTimes[kk] = eTimes[k];
				sTimes[kk] = min(sTimes[kk], sTimes[k]);
				//cout << "two\n";
				//flag = 1;
			}
		}
	}
	//cout << len << "\n";
	/*for (int k = 0; k < N; k++)
	{
		if ((eTimes[k] - sTimes[k]) > (end-start))
		{
			start = sTimes[k];
			end = eTimes[k];
		}
	}*/
	int milking = 0;
	int idle = 0;
	for (int j = 0; j < len; j++)
	{
		//cout << ": " << sTimes[j] << " " << eTimes[j] << "\n";
		//cout << milking << ": " << sTimes[j] << " " << eTimes[j] << "\n";
		//milking = max(milking, eTimes[j]-sTimes[j]);
		if (eTimes[j]-sTimes[j] > milking)
		{
			milking = eTimes[j]-sTimes[j];
			//cout << sTimes[j] << " " << eTimes[j] << " " << milking << "\n";
		}
		//cout << milking << ": " << sTimes[j] << " " << eTimes[j] << "\n";
		//if (eTimes[j] - sTimes[j] == 912)
			//cout << "1\n";
		//cout << milking << " " << j << "\n";
		int iStart = eTimes[j];
		int iEnd = end;
		
		/*for (int jj = 0; jj < N; jj++)
		{
			if (j == jj)
				continue;
			if ((sTimes[jj] <= iEnd) && (eTimes[jj] >= iStart))
			{
				if (iEnd-(eTimes[jj]) > (sTimes[jj])-iStart)
					iStart = eTimes[jj];
				else
					iEnd = sTimes[jj];
			}
		}*/
		idle = max(idle, calcIdle(sTimes, eTimes, iStart, iEnd, 0, N));
		//cout << j << "\n";
		//cout << iStart << " " << iEnd << "\n";
	}
	
	outfile << milking << " " << idle << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}
	// for (int s = 0; s < N; s++)
// 	{
// 		int mStart = sTimes[s];
// 		int mEnd = eTimes[s];
// 		for (int j = 0; j < N; j++)
// 		{
// 			if (j == s)
// 				continue;
// 			if ((sTimes[j] >= mStart) && (sTimes[j] <= mEnd))
// 				mEnd = max(mEnd, eTimes[j]);
// 			if ((eTimes[j] <= mEnd) && (eTimes[j] >= mStart))
// 				mStart = min(mStart, sTimes[j]);
// 		}
		
		