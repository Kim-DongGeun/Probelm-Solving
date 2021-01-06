#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		//int arr[100001];
		int input;
		int ans = INT32_MAX;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> input;
			if (x % input == 0) {
				ans = min(ans, x / input);
			}
			else {
				ans = min(ans, x / input + (x / input == 0 ? 2 : 1));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}