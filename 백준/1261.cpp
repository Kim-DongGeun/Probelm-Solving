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

int n, m;
int arr[101][101];
bool visited[101][101] = { false, };

struct info {
	int x, y, cnt;
};
struct compare {
	bool operator()(info& a, info& b) {
		return a.cnt > b.cnt;
	}
};


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		for (int j = 0; j < m; j++) {
			arr[i][j] = x[j] - '0';
		}
	}

	priority_queue<info, vector<info>, compare> pq;
	pq.push({ 0,0,0 });
	while (!pq.empty()) {
		int curX = pq.top().x;
		int curY = pq.top().y;
		int cnt = pq.top().cnt;
		pq.pop();

		if (visited[curY][curX]) continue;
		visited[curY][curX] = true;

		if (curX == m - 1 && curY == n - 1) {
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			pq.push({ nx, ny, arr[ny][nx] ? cnt + 1 : cnt });
		}
	}


	return 0;
}