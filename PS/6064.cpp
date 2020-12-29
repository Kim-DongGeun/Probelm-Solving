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
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		
		while (true) {
			if (x > m*n) {
				cout << -1 << '\n';
				break;
			}

			if ((x - y) % n == 0) {
				cout << x << '\n';
				break;
			}
			x += m;
		}

	}
	return 0;
}

