#include <iostream>
using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;

	int ans = 0;
	int height = 0;

	for (int i = V - A; i >= 0; i--) {
		if (i % (A - B) == 0) {
			ans = i / (A - B);
			height = i;
			break;
		}
	}

	while (true) {
		ans++;
		if (height + A >= V)break;
		height += (A - B);
	}
	cout << ans << '\n';
	return 0;
}
