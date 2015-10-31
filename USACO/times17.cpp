#include <fstream>
#include <cstring>
using namespace std;

int result[2000] = {0};


char* mySubStr(char* str, int beg, int end)
{
	char newStr[1000] = {0};
	for (int i = beg; i <= end; i++)
	{
		newStr[i-beg] = str[i];
	}
	return newStr;
}

int multiply(char* num1, char* num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	char* first1 = mySubStr(num1, 0, len1/2)
	char* second1 = mySubStr(num1, (len1/2)+1, len1-1);
	char* first2 = mySubStr(num2, 0, len2/2)
	char* second2 = mySubStr(num2, (len2/2)+1, len2-1);
	
	

int main(void)
{
	