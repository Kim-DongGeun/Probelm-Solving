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

vector<pair<int, int>> v; // ½ÃÀÛ, µµÂø


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	int ans = 0;
	int l = v[0].first;
	int r = v[0].second;
	int len = v.size();

	for (int i = 1; i < len; i++) {
		if (v[i].first <= r && r < v[i].second) {
			r = v[i].second;
		}
		else if (r < v[i].first) {
			ans += r - l;
			l = v[i].first;
			r = v[i].second;
		}
	}

	cout << ans + r - l;

	return 0;
}
