#include <iostream>
#include <cmath>
using namespace std;

bool ok (int q[], int c) {
	for (int i = 0; i < c; i++)
		if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
			return false;
	return true;
}

int nqueens (int n) {
	int* q = new int[n]; // dynamically allocates an array of n integers and assigns the memory address of the first element of the array to the pointer variable q. This means that q now points to the first element of an array of n integers
	q[0] = 0; // sets the position of the first queen on the first row of the first column
	int c = 0, numSolutions = 0; // start on first column (c = 0)
	while (c >= 0) { //end the loop if you backtrack from the first column
		if (c == n - 1) { //if you are in the last column, the # of solutions goes up and you backtrack
			++numSolutions;
			--c;
		}
		else // otherwise, move to the one before the first row of the next column
			q[++c] = -1;
		while (c >= 0) {
			++q[c]; //move to next row
			if (q[c] == n) //if you have passed the end of the column, backtrack
				--c;
			else if (ok(q, c)) // otherwise, if the queen is ok, break (go back 2 beginning of the outer loop)
				break;
		}
	}
	delete[] q; // deallocates the memory that was allocated for q, releasing the memory back to the system
	return numSolutions;
}

int main () {
	int n = 8;
	for (int i = 1; i <= n; ++i)
		cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem." << endl;
	return 0;
}
