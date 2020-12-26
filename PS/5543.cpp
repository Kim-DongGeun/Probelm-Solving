#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };



int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	cout << min({ a,b,c }) + min(d, e) - 50;

	return 0;
}