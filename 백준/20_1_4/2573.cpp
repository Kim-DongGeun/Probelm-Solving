#include <iostream>
#include <vector>
using namespace std;

int N, M;
struct Data { int x, y; };
vector<Data> arr;
int Map[301][301];
bool check[301][301] = { false };
bool dfs_visited[301][301] = { false };

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (Map[ny][nx] != 0 && !dfs_visited[ny][nx]) {
			dfs_visited[ny][nx] = true;
			dfs(nx, ny);
		}
	}
}

bool mapCheck() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (check[i][j]) return false;
	return true;
}

void reCheck() {
	for (int i = 0; i < arr.size(); i++) {
		if (Map[arr[i].y][arr[i].x] <= 0) {
			check[arr[i].y][arr[i].x] = false;
		}
	}
	for (auto iter = arr.begin(); iter != arr.end();) {
		if (Map[(*iter).y][(*iter).x] <= 0) {
			iter = arr.erase(iter);
		}
		else {
			iter++;
		}
	}
}

int main() {

	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &Map[i][j]);
			if (Map[i][j] != 0) {
				arr.push_back({ j, i });
				check[i][j] = true;
			}
		}
	int ans = 0;
	while (true) {
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 0; j < 4; j++) {
				int nx = arr[i].x + dx[j];
				int ny = arr[i].y + dy[j];

				if (!check[ny][nx]) {
					Map[arr[i].y][arr[i].x]--;
				}
			}
		}
		reCheck();
		ans++;

		if (mapCheck()) {
			ans = 0;
			break;
		}

		for (int i = 0; i < arr.size(); i++)
			dfs_visited[arr[i].y][arr[i].x] = false;

		dfs_visited[arr[0].y][arr[0].x] = true;
		dfs(arr[0].x, arr[0].y);
		
		bool out = false;
		for (int i = 0; i < arr.size(); i++)
			if (!dfs_visited[arr[i].y][arr[i].x] && check[arr[i].y][arr[i].x]) {
				out = true;
				break;
			}
		if (out) break;

	}
	printf("%d\n", ans);
	return 0;
}