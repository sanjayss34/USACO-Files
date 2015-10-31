#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
int minutes1 = (11 * 60) + 11;
int minutes2 = 0;

ifstream input;
input.open("ctiming.in");
ofstream output;
output.open("ctiming.out");

int D, H, M;
char thing;
char full = ""
while (input.get(thing) != " ") {
	full = full + thing;
	}
D = static_cast<int> full;
full = "";
while (input.get(thing) != " ") {
	char full = "";
	full = full + thing;
	}
full = "";
H = static_cast<int> full;
while (input.get(thing) != " ") {
	char full = "";
	full = full + thing;
	}
M = static_cast<int> full;

minutes2 = minutes2 + ((D-11)*(24*60));
minutes2 = minutes2 + (H*60);
minutes2 = minutes2 + M;

if (minutes2 >= minutes1) output << (minutes2 - minutes1);
else output << "-1";

input.close();
output.close();

return 0;
}