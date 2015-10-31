#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void)
{
	ifstream infile;
	infile.open("slowdown.in");
	ofstream outfile;
	outfile.open("slowdown.out");
	int N = 0;
	infile >> N;
	int T_size = 0;
	int D_size = 0;
	
	//cout << "three\n";
	
	double* T_events = (double*) malloc(sizeof(double) * N);
	double* D_events = (double*) malloc(sizeof(double) * N);
	for (int i = 0; i < N; i++)
	{
		char type;
		double val;
		infile >> type >> val;
		if (type == 'T')
		{
			T_events[T_size] = val;
			T_size++;
		}
		else
		{
			D_events[D_size] = val;
			D_size++;
		}
	}
	
	//cout << T_events[0] << D_events[0] << "\n";
	
	double time = 0.0;
	double dist = 0.0;
	double rate = 1.0;
	
	//cout << "two\n";
	
	sort(T_events, T_events + T_size);
	sort(D_events, D_events + D_size);
	
	//cout << "four\n";
	
	int t_place = 0;
	int d_place = 0;
	
	while ((t_place < T_size) || (d_place < D_size))
	{
		if (((((D_events[d_place]-dist)/rate) <= T_events[t_place]) && d_place < D_size) || (t_place >= T_size))
		{
			time = time + ((D_events[d_place]-dist)/rate);
			dist = D_events[d_place];
			rate = 1.0/((1.0/rate)+1);
			d_place++;
			/*cout << "STATUS\n";
			cout << "time: " << time << ", dist: " << dist << ", rate: " << rate << "\n";
			cout << "t_place: " << t_place << ", d_place: " << d_place << "\n";*/
		}
		else
		{
			dist = dist + ((T_events[t_place] - time) * rate);
			time = T_events[t_place];
			rate = 1.0/((1.0/rate)+1);
			t_place++;
			/*cout << "STATUS\n";
			cout << "time: " << time << ", dist: " << dist << ", rate: " << rate << "\n";
			cout << "t_place: " << t_place << ", d_place: " << d_place << "\n";*/
		}
	}
	
	time = time + ((1000.0-dist)/rate);
	
	//cout << "one\n";
	
	int intTime = (int) time;
	if (time > ((double) intTime) + 0.5)
		intTime++;
	
	outfile << intTime << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}