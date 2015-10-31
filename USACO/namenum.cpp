/*
PROB: namenum
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstdlib>
//#include <ios>
#include <cstring>
using namespace std;

ofstream outfile ("namenum.out");
//char* dictionary[5000] = (char*) malloc(sizeof(char) * 60000);
//char** dictionary = (char**) malloc(sizeof(char) * 32000);
char dictionary[5000][13];
int flag;
int c;

bool bin_search(char* str, int start, int end)
{
	/*if (strcmp("INDEPENDENCE", str) == 0)
	{
		cout << "I - " << start << " " << end << "\n";
	}*/
	int mid = (int) ((start+end)/2);
	if (end-start <= 2)
	{
		// if ((strcmp(str, dictionary[start]) == 0) || (strcmp(str, dictionary[end]) == 0) || (strcmp(str, dictionary[mid]) == 0))
// 			return true;
		for (int i = start; i <= end; i++)
		{
			/*if (strcmp("INDEPENDENCE", str) == 0)
				cout << i << " " << dictionary[i] << "\n";*/
			if (strcmp(str, dictionary[i]) == 0)
				return true;
		}
	}
	else if (strcmp(str, dictionary[mid]) == 0)
	{
		return true;
	}
	else if (strcmp(str, dictionary[mid]) > 0)
	{
		return bin_search(str, mid+1, end);
	}
	else if (strcmp(str, dictionary[mid]) < 0)
	{
		return bin_search(str, start, mid-1);
	}
	
	return false;
}

void generate(char* serial, char* nombre, int index, int iter)
{
	char* add = (char*) malloc(sizeof(char));
	switch(serial[index])
	{
		case '2':
			if (iter == 0)
				add = "A";
			else if (iter == 1)
				add = "B";
			else if (iter == 2)
				add = "C";
			break;
		case '3':
			if (iter == 0)
				add = "D";
			else if (iter == 1)
				add = "E";
			else if (iter == 2)
				add = "F";
			break;
		case '4':
			if (iter == 0)
				add = "G";
			else if (iter == 1)
				add = "H";
			else if (iter == 2)
				add = "I";
			break;
		case '5':
			if (iter == 0)
				add = "J";
			else if (iter == 1)
				add = "K";
			else if (iter == 2)
				add = "L";
			break;
		case '6':
			if (iter == 0)
				add = "M";
			else if (iter == 1)
				add = "N";
			else if (iter == 2)
				add = "O";
			break;
		case '7':
			if (iter == 0)
				add = "P";
			else if (iter == 1)
				add = "R";
			else if (iter == 2)
				add = "S";
			break;
		case '8':
			if (iter == 0)
				add = "T";
			else if (iter == 1)
				add = "U";
			else if (iter == 2)
				add = "V";
			break;
		case '9':
			if (iter == 0)
				add = "W";
			else if (iter == 1)
				add = "X";
			else if (iter == 2)
				add = "Y";
			break;
	}
	char* pass = (char*) malloc(sizeof(char) * 13);
	strcpy(pass, nombre);
	strcat(pass, add);
	if (index < (strlen(serial)-1))
		generate(serial, pass, index+1, 0);
	else
	{
		/*if (strcmp(pass, "INDEPENDENCE") == 0)
			cout << "made\n";*/
		if (bin_search(pass, 0, c-1))
		{
			outfile << pass << "\n";
			flag = 1;
		}
	}
	if (iter < 2)
	{
		generate(serial, nombre, index, iter+1);
	}
}

int main(void)
{
	//cout << "hi\n";
	ifstream dictFile;
	dictFile.open("dict.txt");
	ifstream infile;
	infile.open("namenum.in");
	//cout << "hi2\n";
	char* ser = (char*) malloc(sizeof(char) * 13);
	infile >> ser;
	c = 0;
	flag = 0;
	//cout << ser << "\n";
	//while (!(dictFile.eof()))
	while (c < 4718)
	{
		dictFile >> dictionary[c];
		//cout << dictionary[c];
		c++;
	}
	
	//cout << "hello\n";
	
	//cout << dictionary[1863] << "\n";
	
	generate(ser, "", 0, 0);
	//cout << flag << "\n";
	if (flag == 0)
	{
		//cout << "here\n";
		outfile << "NONE\n";
	}
	
	infile.close();
	outfile.close();
	
	return 0;
}