#include <iostream>
using namespace std;

int main() {

	int m, n;
	cin >> m >> n;


	int first = 0;
	int sum = 0;
	for (int i = m; i <= n; i++) {
		if (i == 1) continue;
		bool c = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				c = false;
				break;
			}
		}
		if (c) {
			if (first == 0) first = i;
			sum += i;
		}
	}
	if (first == 0) cout << -1;
	else {
		cout << sum << '\n' << first;
	}
	return 0;
}