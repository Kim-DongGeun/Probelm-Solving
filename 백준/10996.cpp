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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n + 1) / 2; j++) cout << "* ";
		cout << '\n';
		for (int j = 0; j < n / 2; j++) cout << " *";
		cout << '\n';
	}

	return 0;
}

