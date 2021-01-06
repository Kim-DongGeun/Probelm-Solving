#include <iostream>
#include <string.h>
using namespace std;

int h, w, Map[51][51];
int visited[51][51];
int roomCnt = 0, maxRoom = 0, maxSize = 0;
int roomsize;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void dfs(int x, int y, int depth) {
	bool out = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
		else if (!(Map[y][x] & (1 << i)) && visited[ny][nx] < visited[y][x]) {
			visited[ny][nx] = roomCnt;
			out = false;
			dfs(nx, ny, depth + 1);
		}
	}
}

int main() {
	cin >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> Map[i][j];

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			if (!visited[i][j]) {
				visited[i][j] = ++roomCnt;
				dfs(j, i, 0);
				//visited[i][j] = 0;
			}
		}

	for (int k = 1; k <= roomCnt; k++) {
		int cnt = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (visited[i][j] == k) cnt++;
		maxRoom = maxRoom < cnt ? cnt : maxRoom;
	}
	printf("%d\n%d\n", roomCnt, maxRoom);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			for (int k = 0; k < 4; k++) {
				if (Map[i][j] & (1 << k)) {

					Map[i][j] &= ~(1 << k);
					roomCnt = 0;
					memset(visited, 0, sizeof(visited));
					visited[i][j] = ++roomCnt;
					dfs(j, i, 0);


					int cnt = 0;
					for (int a = 0; a < h; a++)
						for (int b = 0; b < w; b++)
							if (visited[a][b] == 1) cnt++;
					maxSize = maxSize < cnt ? cnt : maxSize;

					Map[i][j] |= (1 << k);
				}
			}
		}
		
	}
	printf("%d\n", maxSize);
	return 0;
}