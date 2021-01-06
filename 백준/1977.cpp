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

int main() {
	int m, n;
	cin >> m >> n;

	int sum = 0;
	int Min = INT32_MAX;
	for (int i = m; i <= n; i++) {
		int t = (int)sqrt(i);

		if (t * t == i) {
			sum += i;
			Min = min(Min, i);
		}
	}

	if (Min == INT32_MAX) cout << -1;
	else {
		cout << sum << '\n' << Min;
	}

	return 0;
}

