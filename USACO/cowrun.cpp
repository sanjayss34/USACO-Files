#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// typedef struct node
// {
// 	int value = 0;
// 	node* next = NULL;
// }
// node;
// 
// int main(void)
// {
// 	ifstream infile;
// 	infile.open("cowrun.in");
// 	ofstream outfile;
// 	outfile.open("cowrun.out");
// 	int N = 0;
// 	infile >> N;
// 	node* start = (node*) malloc(sizeof(node));
// 	int firstVal = 0;
// 	infile >> firstVal;
// 	start->value = firstVal;
// 	//node* last = (node*) malloc(sizeof(node));
// 	//last->next = start;
// 	int total = max(firstVal, -1*firstVal);
// 	for (int i = 1; i < N; i++)
// 	{
// 		int val = 0;
// 		infile >> val;
// 		node* first = (node*) malloc(sizeof(node));
// 		first = start;
// 		int minAdd = max((val-first->value), -1*(val-first->value));
// 		int minAdd1 = minAdd
// 		node* second = (node*) malloc(sizeof(node));
// 		second = first->next;
// 		while (second != NULL)
// 		{
// 			int toAdd = max((val-first->value), -1*(val-first->value)) + max((val-second->value), -1*(val-second->value)) - max((first->value-second->value), -1*(first->value-second->value));
// 			if (toAdd < minAdd)
// 				minAdd = toAdd;
// 			first = first->next;
// 			second = second->next;
// 		}
// 		node* newNode = (node*) malloc(sizeof(node));
// 		newNode->value = val;
// 		if (max(val-first->value, -1*(val-first->value)) < minAdd)
// 			first->next = newNode;
// 		else if (minAdd == minAdd1)
// 		{
// 			node* save = (node*) malloc(sizeof(node));
// 			start->value = val;
// 			while (curr != NULL)
// 			{
// 				
// 		}

int main(void)
{
	ifstream infile;
	infile.open("cowrun.in");
	ofstream outfile;
	outfile.open("cowrun.out");
	int N = 0;
	infile >> N;
	int* list = (int*) malloc(sizeof(int) * (N+1));
	infile >> list[0];
	int total = max(list[0], -1*list[0]);
	for (int i = 1; i < N; i++)
	{
		cout << "A ";
		int val = 0;
		infile >> val;
		int minAdd = max((val-list[0]), -1*(val-list[0]))+max(val, -1*val) - max(list[0], -1*list[0]);
		int minAdd1 = minAdd;
		cout << list[0] << " ";
		for (int pos = 1; pos < i; pos++)
		{
			cout << list[pos] << " ";
			int toAdd = max(val-list[pos-1], -1*(val-list[pos-1])) + max(val-list[pos], -1*(val-list[pos])) - max(list[pos-1]-list[pos], -1*(list[pos-1]-list[pos]));
			minAdd = min(minAdd, toAdd);
		}
		if (max(val-list[i-1], -1*(val-list[i-1])) < minAdd)
			list[i] = val;
		
		else if (minAdd == minAdd1)
		{
			int save = list[0];
			list[0] = val;
			for (int pos2 = 1; pos2 <= i; pos2++)
			{
				int temp = 1001;
				if (pos2 < i)
					temp = list[pos2];
				list[pos2] = save;
				save = temp;
			}
		}
		
		else
		{
			int flag = 0;
			int store = val;
			for (int j = 1; j <= i; j++)
			{
				if (flag == 0)
				{
					if (max(val-list[j-1], -1*(val-list[j-1])) + max(val-list[j], -1*(val-list[j])) - max(list[j-1]-list[j], -1*(list[j-1]-list[j])) == minAdd)
					{
						store = list[j];
						flag = 1;
						list[j] = val;
					}
				}
				
				else
				{
					int temp2 = 0;
					if (j < i)
						temp2 = list[j];
					list[j] = store;
					store = temp2;
				}
			}
		}
		cout << "\n" << minAdd << "\n";
		total = total + minAdd;
	}
	
	outfile << total << "\n";
	
	return 0;
}