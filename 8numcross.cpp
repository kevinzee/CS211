#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
	static int adj[8][5] = { {-1},                // 0  Neighbor list for each square
				{0, -1},             // 1
                            	{0, 1, -1},          // 2  The cross with the squares labeled:
                            	{0, 2, -1},          // 3                  1 4
                            	{1, 2, -1},          // 4                0 2 5 7
                            	{1, 2, 3, 4, -1},    // 5                  3 6
                            	{2, 3, 5, -1},       // 6
                            	{4, 5, 6, -1}     }; // 7
	for (int i = 0; i < c; i++)
		if (q[i] == q[c])
			return false;
	for (int i = 0; adj[c][i] != -1; i++) 
		if (abs(q[c] - q[adj[c][i]]) == 1) 
         		return false;
	return true;
}

void print(int q[]) {
   	static int solution = 0;
   	cout << "Solution #" << ++solution << endl;
   	cout << " "  << q[1] << q[4] << endl;
   	cout << q[0] << q[2] << q[5] << q[7] << endl;
   	cout << " "  << q[3] << q[6] << endl << endl;
}

int main() {
	int q[8] = {0};
   	int c = 0;
	while (c >= 0) {
		++q[c];
		if (q[c] > 8) {
			--c;
		} else {
			if (ok(q, c)) {
				if (c == 7) {
					print(q);
				} else {
					++c;
					q[c] = 0;
				}
			}
		}
	} 
	return 0;
}
