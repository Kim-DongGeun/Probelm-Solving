#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int arr[101];
		bool p[101];
		memset(p, false, sizeof(p));
		int n, m, a;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		for (int i = 1; i <= m; i++) {
			cin >> a;
			p[a] = true;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (arr[j] > arr[j + 1]) {
					if (p[j]) {
						swap(arr[j], arr[j + 1]);
					}
				}
			}
		}

		bool out = false;
		for (int i = 1; i < n; i++) {
			if (arr[i] > arr[i + 1]) {
				out = true;
				break;
			}
		}

		if (out) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}