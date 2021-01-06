#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <set>
using namespace std;

struct Pos { 
	int x, y; 
	bool operator<(Pos a) const {
		if (y == a.y) return x < a.x;
		else return y < a.y;
	}
	bool operator==(Pos b) {
		return x == b.x && y == b.y;
	}
};

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
	vector<Pos> water;
	Pos start;
	Pos home;
	int w, h;
	int visited[51][51];
	char Map[52][52];
	string input;

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> input;
		for (int j = 0; j < w; j++) {
			Map[i][j] = input[j];
			if (input[j] == 'S') {
				start.x = j;
				start.y = i;
			}
			else if (input[j] == '*') {
				water.push_back({ j,i });
			}
			else if (input[j] == 'D') {
				home.x = j;
				home.y = i;
			}
		}
	}

	memset(visited, -1, sizeof(visited));
	set<Pos> s;
	queue<Pos> q; // water
	queue<Pos> nq;
	queue<Pos> Q; // gosmdochi
	queue<Pos> nQ;
	Q.push(start);
	visited[start.y][start.x] = 0;
	bool success = false;
	for(int i = 0 ; i < water.size(); i++)
		q.push(water[i]);

	while (true) {
		while (!q.empty()) {
			Pos cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];

				if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
				else if (Map[ny][nx] != 'X' && Map[ny][nx] != 'D' && Map[ny][nx] != '*') { // 집과 벽이 아니면
					Map[ny][nx] = '*';
					nq.push({ nx, ny });
				}
			}
		}

		s.clear();
		while (!nq.empty()) {
			s.insert(nq.front());
			nq.pop();
		}
		for (auto iter = s.begin(); iter != s.end(); iter++)
			q.push((*iter));


		while (!Q.empty()) {
			Pos cur = Q.front();
			Q.pop();

			if (cur.x == home.x && cur.y == home.y) {
				success = true;
				printf("%d\n", visited[cur.y][cur.x]);
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];

				if (nx < 0 || ny < 0 || nx >= w || ny >= h || visited[ny][nx] != -1) continue;
				else if (Map[ny][nx] == '.' || Map[ny][nx] == 'D') {
					visited[ny][nx] = visited[cur.y][cur.x] + 1;
					nQ.push({ nx, ny });
				}
			}
		}

		s.clear();
		while (!nQ.empty()) {
			s.insert(nQ.front());
			nQ.pop();
		}
		for (auto iter = s.begin(); iter != s.end(); iter++)
			Q.push((*iter));

		if (Q.size() == 0 && nQ.size() == 0) {
			printf("KAKTUS\n");
			break;
		}
	}

		
	return 0;
}