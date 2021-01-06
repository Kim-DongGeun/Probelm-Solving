#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, d;
		int arr[101];
		cin >> n >> d;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int index = 1;
		while (d > 0 && index < n) {
			if (arr[index]) {
				if (d < index) break;
				d -= index;
				arr[index]--;
				arr[0]++;
			}
			else index++;
		}
		cout << arr[0] << '\n';
	}
	return 0;
}