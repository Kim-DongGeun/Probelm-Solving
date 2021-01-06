#include <iostream>
#include <vector>
using namespace std;

int N, ans = 0;
vector<vector<int>> Map(21, vector<int>(21, 0));

void move(int direction) {
	switch (direction) {
	case 0: // R
		for (int y = 0; y < N; y++) {
			bool check[21] = { false, };
			for (int x = N - 2; x >= 0; x--) {
				if (Map[y][x] == 0) continue;
				int nx = x + 1;
				while (Map[y][nx] == 0 && nx < N) {
					swap(Map[y][nx], Map[y][nx - 1]);
					nx++;
				}
				if (Map[y][nx] == Map[y][nx - 1] && !check[nx]) {
					Map[y][nx] *= 2;
					Map[y][nx - 1] = 0;
					check[nx] = true;
				}
			}
		}
		break;
	case 1: // U
		for (int x = 0; x < N; x++) {
			bool check[21] = { false, };
			for (int y = 1; y < N; y++) {
				if (Map[y][x] == 0) continue;
				int ny = y - 1;
				while (Map[ny][x] == 0 && ny >= 0) {
					swap(Map[ny][x], Map[ny + 1][x]);
					if (ny != 0)
						ny--;
				}
				if (Map[ny][x] == Map[ny + 1][x] && !check[ny]) {
					Map[ny][x] *= 2;
					Map[ny + 1][x] = 0;
					check[ny] = true;
				}
			}
		}
		break;
	case 2: // L
		for (int y = 0; y < N; y++) {
			bool check[21] = { false, };
			for (int x = 1; x < N; x++) {
				if (Map[y][x] == 0) continue;
				int nx = x - 1;
				while (Map[y][nx] == 0 && nx >= 0) {
					swap(Map[y][nx], Map[y][nx + 1]);
					if (nx != 0)
						nx--;
				}
				if (Map[y][nx] == Map[y][nx + 1] && !check[nx]) {
					Map[y][nx] *= 2;
					Map[y][nx + 1] = 0;
					check[nx] = true;
				}
			}
		}
		break;
	case 3: // D
		for (int x = 0; x < N; x++) {
			bool check[21] = { false, };
			for (int y = N - 2; y >= 0; y--) {
				if (Map[y][x] == 0) continue;
				int ny = y + 1;
				while (Map[ny][x] == 0 && ny < N) {
					swap(Map[ny][x], Map[ny - 1][x]);
					ny++;
				}
				if (Map[ny][x] == Map[ny - 1][x] && !check[ny]) {
					Map[ny][x] *= 2;
					Map[ny - 1][x] = 0;
					check[ny] = true;
				}
			}
		}
		break;
	}
}

void dfs(int depth) {
	if (depth == 5) {
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				ans = ans < Map[i][j] ? Map[i][j] : ans;

		return;
	}

	vector<vector<int>> preMap(21, vector<int>(21, 0));
	preMap = Map;

	for (int i = 0; i < 4; i++) {
		move(i);
		dfs(depth + 1);
		Map = preMap;
	}
}

int main() {
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf_s("%d", &Map[i][j]);

	dfs(0);

	printf("%d\n", ans);
	return 0;
}