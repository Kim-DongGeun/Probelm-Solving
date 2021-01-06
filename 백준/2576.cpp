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
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int m = INT32_MAX;
	int sum = 0;
	for (int i = 0; i < 7; i++) {
		int x;
		cin >> x;
		if (x & 1) {
			sum += x;
			m = min(m, x);
		}
	}
	if (m == INT32_MAX) cout << -1;
	else  cout << sum << '\n' << m;


	return 0;
}

