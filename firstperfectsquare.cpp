#include <iostream>
using namespace std;

int main(){
	int i = 1;
	while (true){
		int ps = i * i;
		if (ps % 2 == 1 && (ps / 10) % 2 == 1){
			cout << "The first perfect square is: " << ps << endl;
		break;
		}
		i++;
	}
	return 0;
}
