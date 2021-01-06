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

	int n;
	cin >> n;
	int ans = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		ans = max(ans, v[i] * ((int)v.size() - i));
	}
	cout << ans;
	return 0;
}

