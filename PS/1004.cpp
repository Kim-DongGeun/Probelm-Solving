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
int sx, sy, ex, ey;

bool check(int cx, int cy, int r) {
	if ((cx - sx)* (cx - sx) + (cy - sy)* (cy - sy) < r * r && (cx - ex)* (cx - ex) + (cy - ey)* (cy - ey) < r*r) return false;
	else if ((cx - sx) * (cx - sx) + (cy - sy) * (cy - sy) < r * r) return true;
	else if ((cx - ex) * (cx - ex) + (cy - ey) * (cy - ey) < r * r) return true;
	else return false;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> sx >> sy >> ex >> ey;
		int n;
		cin >> n;
		
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int cx, cy, r;
			cin >> cx >> cy >> r;

			if (check(cx, cy, r)) ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}

