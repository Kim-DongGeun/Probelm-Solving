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

	int index, ans = 0;
	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int x;
			cin >> x;
			sum += x;
		}
		if (sum > ans) {
			ans = sum;
			index = i + 1;
		}
	}
	cout << index << ' ' << ans << '\n';

	return 0;
}