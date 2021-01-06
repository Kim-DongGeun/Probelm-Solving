#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct Pos { int x, y, cnt;
bool operator<(Pos a) const {
	if (x == a.x) return y < a.y;
	else return x < a.x;
}
};
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int Map[1001][51][51] = { 0, };
vector<Pos> aircleaner;
vector<Pos> dust;
set<Pos> s;

int main() {
	int R, C, T;
	cin >> R >> C >> T;
	for(int i = 0 ; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> Map[0][i][j];
			if (Map[0][i][j] == -1) aircleaner.push_back({ j,i,0 });
			else if (Map[0][i][j] != 0) dust.push_back({ j,i,0 });
		}


	queue<Pos> q;
	queue<Pos> Q;
	for (Pos x : dust) q.push(x);

	for(int t = 0 ; t < T; t++){
		Map[t][aircleaner[0].y][aircleaner[0].x] = -1;
		Map[t][aircleaner[1].y][aircleaner[1].x] = -1;

		while (!q.empty()) {
			Pos cur = q.front();
			q.pop();

			if (Map[cur.cnt][cur.y][cur.x] >= 5) {
				int count = 0;
				for (int i = 0; i < 4; i++) {
					int nx = dx[i] + cur.x;
					int ny = dy[i] + cur.y;
					if (nx < 0 || ny < 0 || nx >= C || ny >= R || Map[cur.cnt][ny][nx] == -1) continue;

					Map[cur.cnt + 1][ny][nx] += Map[cur.cnt][cur.y][cur.x] / 5;
					if ((Map[cur.cnt][cur.y][cur.x] / 5) != 0) {
						count++;
						Q.push({ nx, ny, cur.cnt + 1 });
					}
				}
				Map[cur.cnt + 1][cur.y][cur.x] += Map[cur.cnt][cur.y][cur.x] - (count * (Map[cur.cnt][cur.y][cur.x] / 5));
			}
			else
				Map[cur.cnt + 1][cur.y][cur.x] += Map[cur.cnt][cur.y][cur.x];
			Q.push({ cur.x,cur.y,cur.cnt + 1 });
		}

		for (int i = aircleaner[0].y - 2; i >= 0; i--) Map[t + 1][i + 1][0] = Map[t + 1][i][0];
		for (int i = 1; i < C; i++) Map[t + 1][0][i - 1] = Map[t + 1][0][i];
		for (int i = 1; i <= aircleaner[0].y; i++) Map[t + 1][i - 1][C - 1] = Map[t + 1][i][C - 1];
		for (int i = C - 2; i >= 1; i--) Map[t + 1][aircleaner[0].y][i + 1] = Map[t + 1][aircleaner[0].y][i];
		Map[t + 1][aircleaner[0].y][1] = 0;

		for (int i = aircleaner[1].y + 2; i < R; i++) Map[t + 1][i - 1][0] = Map[t + 1][i][0];
		for (int i = 1; i < C; i++) Map[t + 1][R - 1][i - 1] = Map[t + 1][R - 1][i];
		for (int i = R - 2; i >= aircleaner[1].y; i--)Map[t + 1][i + 1][C - 1] = Map[t + 1][i][C - 1];
		for (int i = C - 2; i >= 1; i--)Map[t + 1][aircleaner[1].y][i + 1] = Map[t + 1][aircleaner[1].y][i];
		Map[t + 1][aircleaner[1].y][1] = 0;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) {
				if (aircleaner[0].y == i && aircleaner[0].x == j) continue;
				if (aircleaner[1].y == i && aircleaner[1].x == j) continue;
				if (Map[t + 1][i][j] != 0)
					q.push({ j,i,t + 1 });

			}
	}

	int ans = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) ans += Map[T][i][j];
	cout << ans << '\n';
	return 0;
}