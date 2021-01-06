#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		if (a == b) cout << "0\n";
		else if (a % 2 == 0 && b % 2 == 0) { // e e
			if (a > b) {
				cout << "1\n";
			}
			else {
				cout << "2\n";
			}
		}
		else if (a % 2 == 1 && b % 2 == 1) { // o o
			if (a > b) {
				cout << "1\n";
			}
			else {
				cout << "2\n";
			}
		}
		else if (a % 2 == 1 && b % 2 == 0) {
			if (a < b) {
				cout << "1\n";
			}
			else {
				cout << "2\n";
			}
		}
		else if (a % 2 == 0 && b % 2 == 1) {
			if (a < b) {
				cout << "1\n";
			}
			else {
				cout << "2\n";
			}
		}
	}
	return 0;
}
