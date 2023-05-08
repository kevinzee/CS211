#include <iostream>
using std::cout;
using std::endl;

int main(){
	char firstName[] = {'K','e','v','i','n'};
	cout << "I am a CS211 student. My first name is ";
	int numLetters = 5;
	for (int i = 0; i < numLetters; i++){
		cout << firstName[i];
	}
	cout << ". Nice to meet you!" << endl;
	return 0;
}
