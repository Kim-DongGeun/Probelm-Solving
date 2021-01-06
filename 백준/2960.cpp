#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, k, t = 0;
bool arr[1001];


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (!arr[j]) {
				t++;
				arr[j] = true;
			}

			if (t == k) {
				cout << j;
				return 0;
			}
		}
	}

	return 0;
}