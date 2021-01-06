#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct Pos { 
	int x, y;
	bool operator==(Pos a) const {
		return x == a.x && y == a.y;
	}

};
int dx[9] = { 0,1,1,0,-1,-1,-1,0,1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };

bool cmp(Pos a, Pos b) {
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y > b.y;
}

int main() {
	char Map[10][10];
	int visited[10][10][1000];
	vector<Pos> walls;
	Pos start;
	string input;

	for (int i = 0; i < 8; i++) {
		cin >> input;
		for (int j = 0; j < 8; j++) {
			Map[i][j] = input[j];
			if (Map[i][j] == '#') walls.push_back({ j,i });
		}
	}

	sort(walls.begin(), walls.end(), cmp);

	start.x = 0;
	start.y = 7;

	memset(visited, 0, sizeof(visited));
	queue<Pos> q;
	vector<Pos> nq;
	q.push(start);
	visited[7][0][0] = 1;

	for(int cnt = 1; cnt < 1000; cnt++) {
		while (!q.empty()) {
			Pos cur = q.front();
			q.pop();


			for (int i = 0; i < 9; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];

				if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || visited[ny][nx][cnt]) continue;
				else if (Map[ny][nx] == '.') {
					visited[ny][nx][cnt] = 1;
					nq.push_back({ nx, ny });
				}
			}
		}

		for (auto iter = walls.begin(); iter != walls.end();) {
			int nx = (*iter).x;
			int ny = (*iter).y + 1;
			(*iter).y++;

			if (ny >= 8) {
				Map[ny - 1][nx] = '.';
				iter = walls.erase(iter);
			}
			else {
				if(find(nq.begin(), nq.end(), *iter) != nq.end())
					nq.erase(find(nq.begin(), nq.end(), *iter));
				iter++;
				swap(Map[ny - 1][nx], Map[ny][nx]);
			}
		}

		for (int i = 0; i < nq.size(); i++)
			q.push(nq[i]);
		nq.clear();
		if (q.size() == 0) {
			printf("0\n");
			return 0;
		}
		else if (walls.size() == 0) {
			printf("1\n");
			return 0;
		}
	}
	return 0;
}