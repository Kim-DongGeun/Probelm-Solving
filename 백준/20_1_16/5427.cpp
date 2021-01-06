#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

struct Pos { int x, y; };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	vector<Pos> fire;
	Pos start;
	int T, w, h;
	int visited[1002][1002];
	char Map[1003][1003];
	string input;
	cin >> T;
	while (T--) {
		fire.clear();
		cin >> w >> h;
		for (int i = 1; i <= h; i++) {
			cin >> input;
			for (int j = 1; j <= w; j++) {
				Map[i][j] = input[j - 1];
				if (input[j - 1] == '@') {
					start.x = j;
					start.y = i;
				}
				else if (input[j - 1] == '*') fire.push_back({ j,i });
			}
		}
		for (int i = 0; i <= h + 1; i++)
			for (int j = 0; j <= w + 1; j++)
				if (!(j > 0 && i > 0 && j <= w && i <= h)) Map[i][j] = '.';

		memset(visited, -1, sizeof(visited));
		queue<Pos> q;
		queue<Pos> nq;
		queue<Pos> Q;
		queue<Pos> nQ;
		Q.push(start);
		visited[start.y][start.x] = 0;
		bool success = false;
		for (int i = 0; i < fire.size(); i++)
			q.push(fire[i]);

		while (true) {
			while (!q.empty()) {
				Pos cur = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = cur.x + dx[i];
					int ny = cur.y + dy[i];

					if (nx <= 0 || ny <= 0 || nx > w || ny > h) continue;
					else if (Map[ny][nx] != '#' && Map[ny][nx] != '*') { // 불과 벽이 아니면
						Map[ny][nx] = '*';
						nq.push({ nx, ny });
					}
				}
			}

			while (!nq.empty()) {
				q.push(nq.front());
				nq.pop();
			}


			while (!Q.empty()) {
				Pos cur = Q.front();
				Q.pop();

				if (!(cur.x > 0 && cur.y > 0 && cur.x <= w && cur.y <= h)) {
					success = true;
					printf("%d\n", visited[cur.y][cur.x]);
					break;
				}

				for (int i = 0; i < 4; i++) {
					int nx = cur.x + dx[i];
					int ny = cur.y + dy[i];

					if (nx <= -1 || ny <= -1 || nx > w + 1 || ny > h + 1 || visited[ny][nx] != -1) continue;
					else if (Map[ny][nx] == '.') {
						visited[ny][nx] = visited[cur.y][cur.x] + 1;
						nQ.push({ nx, ny });
					}
				}
			}
			while (!nQ.empty()) {
				Q.push(nQ.front());
				nQ.pop();
			}

			if (success) break;
			else if (Q.size() == 0 && nQ.size() == 0) {
				printf("IMPOSSIBLE\n");
				break;
			}
		}
	}
}