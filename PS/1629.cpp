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

long long cal(long long a, long long b, long long c) {
	if (b == 0) return 1;

	if (b & 1) return a * cal(a, b - 1, c) % c;
	else {
		long long A = cal(a, b / 2, c);
		return ((A % c) * (A % c)) % c;
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	long long a, b, c;
	cin >> a >> b >> c;

	cout << cal(a, b, c);

	return 0;
}