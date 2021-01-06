#include <iostream>
#include <queue>
#include <map>
using namespace std;

bool bfs_visied[201][201][31]; // y x len cnt
int Map[201][201];
int horseX[8] = { 2,1,-1,-2,-2,-1,1,2 };
int horseY[8] = { -1,-2,-2,-1,1,2,2,1 };
int monkeyX[4] = { 1,0,-1,0 };
int monkeyY[4] = { 0,-1,0,1 };

struct Info
{
	int x;
	int y;
	int cnt; // 남은 말 이동 횟수
	int len; // 이동 횟수
};

struct Detail
{
	int x;
	int y;
	int cnt;

	bool operator<(const Detail& o) const{
		return x < o.x || (x == o.x && y < o.y) || (x == o.x && y == o.y && cnt < o.cnt);
	}
};

int main() {
	int K, W, H;
	scanf_s("%d", &K);
	scanf_s("%d %d", &W, &H);
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			scanf_s("%d", &Map[i][j]);
	
	map<Detail, int> duplication;
	queue<Info> q;
	bfs_visied[0][0][K] = true;
	q.push({ 0,0,K, 0});

	while (!q.empty()) {
		Info temp = q.front();
		q.pop();

		if (temp.x == W - 1 && temp.y == H - 1) { // 도착점에 도착했으면
			printf("%d\n", temp.len);
			return 0;
		}

		if (temp.cnt != 0) {
			for (int i = 0; i < 8; i++) {
				int nx = horseX[i] + temp.x;
				int ny = horseY[i] + temp.y;

				if (nx < 0 || nx >= W || ny < 0 || ny >= H || bfs_visied[ny][nx][temp.cnt - 1]) continue; // 방문하거나 맵을 벗어나면
				if (Map[ny][nx] == 0) {
					bfs_visied[ny][nx][temp.cnt - 1] = true;
					q.push({ nx,ny,temp.cnt - 1, temp.len + 1 });
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = monkeyX[i] + temp.x;
			int ny = monkeyY[i] + temp.y;

			if (nx < 0 || nx >= W || ny < 0 || ny >= H || bfs_visied[ny][nx][temp.cnt]) continue; // 방문하거나 맵을 벗어나면
			if (Map[ny][nx] == 0) {
				bfs_visied[ny][nx][temp.cnt] = true;
				q.push({ nx,ny,temp.cnt, temp.len + 1 });
			}
		}
	}
	printf("-1\n");
	return 0;
}