#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int arr[20][20];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> a(n / 2, 0);
	vector<int> b(n / 2, 1);
	a.insert(a.end(), b.begin(), b.end());

	int ans = 1e9;
	do {
		int sumZero = 0, sumOne = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i] == a[j]) {
					if (a[i] == 0) sumZero += arr[i][j];
					else sumOne += arr[i][j];
				}
			}
		}
		ans = min(ans, abs(sumOne - sumZero));
	} while (next_permutation(a.begin(), a.end()));

	cout << ans;

	return 0;
}

