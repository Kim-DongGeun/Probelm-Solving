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
		long long a, b;
		cin >> a >> b;
		a %= 10;
		if (a == 0) cout << 10 << '\n';
		else cout << ((int)pow(a, (b % 4 == 0 ? 4 : b % 4)) % 10) << '\n';
	}
	return 0;
}

