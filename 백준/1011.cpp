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
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if ((y - x) <= 3) cout << y - x << '\n';
		else {
			int value = (int)sqrt(y - x);
			if ((y - x) == (value * value)) cout << value * 2 - 1 << '\n';
			else {
				if (value * value < (y - x) && (y - x) <= (value * value + value)) cout << 2 * value << '\n';
				else cout << 2 * value + 1 << '\n';
			}
		}
	}
	return 0;
}

