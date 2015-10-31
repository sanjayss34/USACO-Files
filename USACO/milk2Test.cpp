#include <fstream>
#include <iostream>
using namespace std;

int main(void)
{
	ifstream mIn;
	mIn.open("milk2.in");
	for (int i = 0; i < 2000; i++)
	{
		int var = 0;
		mIn >> var;
		ifstream mIn2;
		mIn2.open("milk2.in");
		for (int j = 0; j < 2000; j++)
		{
			int var2 = 0;
			mIn2 >> var2;
			if ((abs(var2-var) == 912) && (i%2 != j%2))
				cout << var << " " << var2 << "\n";
		}
	}
	
	mIn.close();
	
	return 0;
}