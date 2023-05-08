#include <iostream>
#include <vector>

using namespace std;

int main (){
	vector<int> t[3]; // 3 towers A, B, & C represented as an array of 3 vectors
	int n, candidate, to, from, move = 0; //move counts move #

	cout << "Please enter a number of rings to move: ";
	cin >> n;
	cout << endl;

	//initialize the three towers where n is the # of rings. We do n + 1 b/c in that case there will never be an empty tower as when the ring moves there will always be a larger value there.
	for (int i = n + 1; i >= 1; i--)
		t[0].push_back(i);
	t[1].push_back(n + 1);
	t[2].push_back(n + 1);

	// initialize towers and if it's odd or even
	from = 0;
	if (n % 2 == 1)
		to = 1;
	else
		to = 2;
	candidate = 1;

	while (t[1].size()< n + 1){ // there are still rings to transfer to tower B = t[1]
		t[to].push_back(t[from].back()); //place ring in 'to'
		t[from].pop_back(); // take ring from 'from'
		 cout << "Move Number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
		 // the while loop will output " Move Number _: Transfer ring from tower _ to tower _"
	
	if (n % 2 == 1){ // if there are an odd # of rings
		if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back())
			from = (to + 1) % 3;
		else 
			from = (to + 2) % 3;
		// get next 'to tower'
		if (t[(from)].back() < t[(from + 1) % 3].back())
			to = (from + 1) % 3;
		else
			to = (from + 2) % 3;
		candidate = (t[from].back());
	} else { //if there are an even # of rings
		if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back())
			from = (to + 1) % 3;
		else 
			from = (to + 2) % 3;
		if (t[(from)].back() < t[(from + 2) % 3].back())
			to = (from + 2) % 3;
		else 
			to = (from + 1) % 3;
		candidate = (t[from].back());
	}
	}
	return 0;
}

