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
	string arr[8];
	for (int i = 0; i < 8; i++) cin >> arr[i];

	int ans = 0;
	for (int i = 0; i < 8; i+= 2) {
		for (int j = 0; j < 8; j+=2) {
			if (arr[i][j] == 'F')ans++;
		}
	}

	for (int i = 1; i < 8; i += 2) {
		for (int j = 1; j < 8; j += 2) {
			if (arr[i][j] == 'F')ans++;
		}
	}
	cout << ans;

	return 0;
}

