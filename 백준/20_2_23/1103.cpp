#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int N, M;
string Map[51];
bool visited[51][51];
int dp[51][51];
int ans = 0;
bool inf = false;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

void dfs(int x, int y, int cnt) {
	if (inf) return;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * (Map[y][x] - '0');
		int ny = y + dy[i] * (Map[y][x] - '0');

		if (nx < 0 || ny < 0 || nx >= M || ny >= N || Map[ny][nx] == 'H') {
			ans = ans < cnt ? cnt : ans;
		}
		else if (visited[ny][nx]) {
			ans = -1;
			inf = true;
			return;
		}
		else {
			if (dp[ny][nx] < cnt + 1) {
				visited[ny][nx] = true;
				dp[ny][nx] = cnt + 1;
				dfs(nx, ny, cnt + 1);
				if (inf) return;
				visited[ny][nx] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> Map[i];

	memset(dp, 0, sizeof(dp));
	memset(visited, false, sizeof(visited));

	visited[0][0] = true;
	dp[0][0] = 1;
	dfs(0, 0, 1);

	cout << ans << '\n';

	return 0;
}