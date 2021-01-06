#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		cout << (char)((input[i] - 'A' + 23) % 26 + 'A');
	}
	return 0;
}