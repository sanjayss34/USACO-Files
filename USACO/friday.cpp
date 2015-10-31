/*
ID: sanjay_4
PROB: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
ifstream fin ("friday.in");
ofstream fout ("friday.out");

int n;
fin >> n;

int yr = 1900;
int start = 2;
int sun = 0;
int mon = 0;
int tue = 0;
int wed = 0;
int thu = 0;
int fri = 0;
int sat = 0;
int mStart = start;

for(int i = 0; i < n; i++) {
yr = 1900 + i;
//start = (start + (2* ((i-1)/4)) + i-1 - ((i-1)/4)) % 7;
start = mStart;
if (start == 0) start = 7;

mStart = start;
for(int month = 1; month <= 12; month++) {
switch ((mStart + (12%7)) % 7)
{
	case 1:
	sun++;
	break;
	case 2:
	mon++;
	break;
	case 3:
	tue++;
	break;
	case 4:
	wed++;
	break;
	case 5:
	thu++;
	break;
	case 6:
	fri++;
	break;
	case 0:
	sat++;
	break;
}

switch (month)
{
	case 1:
	mStart = (mStart + (31%7)) % 7;
	break;
	case 2:
	if(((1900+i) % 100) == 0) {
		if(((1900+i) % 400) == 0) mStart = (mStart + (29%7)) % 7;
		else mStart = (mStart + (28%7)) % 7;
}
	else if((i%4) == 0) mStart = (mStart + (29%7)) % 7;
	else mStart = (mStart + (28%7)) % 7;
	break;
	case 3:
	mStart = (mStart + (31%7)) % 7;
	break;
	case 4:
	mStart = (mStart + (30%7)) % 7;
	break;
	case 5:
	mStart = (mStart + (31%7)) % 7;
	break;
	case 6:
	mStart = (mStart + (30%7)) % 7;
	break;
	case 7:
	mStart = (mStart + (31%7)) % 7;
	break;
	case 8:
	mStart = (mStart + (31%7)) % 7;
	break;
	case 9:
	mStart = (mStart + (30%7)) % 7;
	break;
	case 10:
	mStart = (mStart + (31%7)) % 7;
	break;
	case 11:
	mStart = (mStart + (30%7)) % 7;
	break;
	case 12:
	mStart = (mStart + (31%7)) % 7;
	break;
}
if (mStart == 0) mStart = 7;

//fout << month << " " << yr << "\n";
//fout << sat << " " << sun << " " << mon << " " << tue << " " << wed << " " << thu << " " << fri << endl;

}

}

fout << sat << " " << sun << " " << mon << " " << tue << " " << wed << " " << thu << " " << fri << endl;

return 0;
}