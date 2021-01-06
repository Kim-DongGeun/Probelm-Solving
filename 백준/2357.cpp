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

unsigned long long arr[9000001];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	arr[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]);
	}
	cout << arr[n];

	return 0;
}