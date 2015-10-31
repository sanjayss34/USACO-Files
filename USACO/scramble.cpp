#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	/*char nums[27];
	int count = 0;
	for (int i = 121; i >= 96; i--)
	{
		nums[count] = (char) i;
		count++;
	}
	cout << nums << "\n";
	vector <char> vNums (nums, nums+26);
	sort(vNums.begin(), vNums.end());
	
	for (vector <char> :: iterator j = vNums.begin(); j < vNums.end(); j++)
		cout << *j;
	cout << "\n";
	return 0;*/
	
	/*int test2[3] = {0, 1, 2};
	int test3[3] = {3,4,5};
	vector <int> v4[2];
	for (int y = 0; y < 2; y++)
	{
		if (y == 0)
		{
			vector <int> vTemp (test2, test2+3);
			v4[y] = vTemp;
		}
		else
		{
			vector <int> vTemp (test3, test2+3);
			v4[y] = vTemp;
		}
	}
	sort(v4.begin(), v4.end());
	for (vector <int> :: iterator jj = v4.begin(); jj < v4.end(); jj++)
		cout << *jj;*/
		
	char* one = "aba";
	char* two = "abb";
	char* arr[2];
	arr[0] = one;
	arr[1] = two;
	vector <char*> another (arr, arr+2);
	sort(another.begin(), another.end());
	for (vector <char*> :: iterator jjj = another.begin(); jjj < another.end(); jjj++)
		cout << *jjj;
	cout << "\n";

	return 0;
	
	/*ifstream infile;
	infile.open("scramble*/
}