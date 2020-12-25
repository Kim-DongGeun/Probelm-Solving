#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <cmath>

using namespace std;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

long long s;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> s;

	
	cout << (int)(-0.5 + sqrt(1 + 8 * s) / 2);
	

	return 0;
}