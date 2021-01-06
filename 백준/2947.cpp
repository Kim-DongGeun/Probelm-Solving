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

	vector<int> v;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	while (true) {
		int c = 0;
		for (int i = 0; i < 4; i++) {
			if (v[i] > v[i + 1]) {
				c = 1;
				swap(v[i], v[i + 1]);
				for (int i = 0; i < 5; i++) {
					cout << v[i] << ' ';
				}
				cout << '\n';
			}
		}
		if(c == 0) break;

	}

	return 0;
}