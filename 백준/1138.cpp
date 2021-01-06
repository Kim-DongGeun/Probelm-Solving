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

int arr[1000][1000];

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int c = n * n;
	int x = 0, y = 0, d = 3, tx, ty;

	while (true) {
		arr[y][x] = c--;
		if (arr[y][x] == m) { tx = x; ty = y; }

		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[ny][nx]) {
			d = (d + 1) % 4;
			nx = x + dx[d];
			ny = y + dy[d];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || arr[ny][nx]) break;
		}
		x = nx;
		y = ny;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ty + 1 << ' ' << tx + 1;

	return 0;
}