#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int n, m, t, ans;
int arr[102][102] = { 0, };


const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) t++;
		}
	}

	while (true) {
		queue<pair<int, int>> q;
		bool visited[101][101];
		int check[101][101];
		memset(visited, false, sizeof(visited));
		memset(check, 0, sizeof(check));
		q.push({ 0,0 });
		visited[0][0] = true;
		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.second + dx[i];
				int ny = cur.first + dy[i];

				if (nx < 0 || ny < 0 || nx >= m || ny >= n || (visited[ny][nx] && !arr[ny][nx])) continue;

				visited[ny][nx] = true;
				if (arr[ny][nx] == 1) {
					check[ny][nx]++;
					continue;
				}
				q.push({ ny, nx });
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[i][j] >= 2) {
					arr[i][j] = 0;
					t--;
				}
			}
		}
		ans++;
		if (t == 0) break;
	}
	cout << ans;

	return 0;
}