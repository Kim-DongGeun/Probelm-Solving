#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = n; i > 0; i--) {
		for (int j = 0; j < n - i; j++) cout << ' ';
		for (int j = 2 * i - 1; j >= 1; j--) cout << '*';
		cout << '\n';
	}

	return 0;
}

