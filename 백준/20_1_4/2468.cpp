#include <iostream>
using namespace std;

int Map[101][101];
bool check[101][101];
int n, low = 101, high = 0;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

void dfs(int y, int x, int height) {
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || check[ny][nx] || Map[ny][nx] <= height) continue;
		check[ny][nx] = true;
		dfs(ny, nx, height);
	}
}

int main() {

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &Map[i][j]);
			low = low > Map[i][j] ? Map[i][j] : low;
			high = high < Map[i][j] ? Map[i][j] : high;
		}
	
	int ans = 0;
	for (int height = low - 1; height < high; height++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) check[i][j] = false;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j] && Map[i][j] > height) {
					check[i][j] = true;
					dfs(i, j, height);
					cnt++;
				}
			}
		}
		ans = ans < cnt ? cnt : ans;
	}
	printf("%d\n", ans);
	return 0;
}