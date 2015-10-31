#include <fstream>
#include <iostream>
using namespace std;

int N;
typedef struct node
{
	int val;
	int ind[50000];
	int count;
	node* next;
}
node;

int binSearch(node* list, node* list2, int num, int flag, int* length, int start, int end)
{
	node* n = list;
	node* h = list2;
	for (int k = 0; k < end/2; k++)
	{
		if (k < start)
			h = h->next;
		n = n->next;
	}
	if (end-start == 1)
	{
		if (num == n->val)
		{
			if (flag > 0)
			{
				(*length)++;
				n->ind[flag] = 1;
				return 0;
			}
			return (-1)*num;
		}
		if (flag < 0)
		{
			return -2;
		}
		node* newNode;
		newNode->val = num;
		newNode->count = 1;
		newNode->ind[flag] = 1;
		newNode->next = n;
		h->next = newNode;
		return 1;
	}
	else if (num > n->val)
	{
		return binSearch(n, n, num, flag, length, 0, end);
	}
	
	return binSearch(h, h, num, flag, length, 0, end/2);
}
		

int main(void)
{
	ifstream infile;
	infile.open("3.lines.in");
	ofstream outfile ("3lines.out");
	int N = 0;
	infile >> N;
	int x[N];
	int y[N];
	node* xUsed;
	node* yUsed;
	int lenX = 1;
	int lenY = 1;
	infile >> x[0] >> y[0];
	xUsed->val = x[0];
	yUsed->val = y[0];
	xUsed->ind[0] = 1;
	yUsed->ind[0] = 1;
	
	for (int i = 1; i < N; i++)
	{
		infile >> x[i] >> y[i];
		int xNum = binSearch(xUsed, xUsed, x[i], i, &lenX, 0, lenX);
		if (xNum == 1)
		{
			lenX++;
			int yNum = binSearch(yUsed, yUsed, y[i], i, &lenY, 0, lenX);
			if (yNum == 1)
				lenY++;
		}
	}
	
	node* xNode = xUsed;
	for (int j = 0; j < lenX; j++)
	{
		for (int jj = 0; jj < N; jj++)
		{
			if (xNode->ind[jj] == 1)
			{
				if (binSearch(yUsed, yUsed, y[jj], -1, &lenY, 0, lenY) >= -1)
					lenX--;
			}
		}
		xNode = xNode->next;
	}
	
	if ((lenY+lenX) <= 3)
		outfile << 1 << "\n";
	else
		outfile << 0 << "\n";
	infile.close();
	outfile.close();
	return 0;
}