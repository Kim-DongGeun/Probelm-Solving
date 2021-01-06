#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct Pos {
	int x, y;
	bool operator==(Pos a) {
		return x == a.x && y == a.y;
	}
};

int N;
int Map[21][21];
int visited[21][21];
vector<Pos> fishes[7];
vector<Pos> minList;
vector<Pos> fishList;
Pos shark;
int sharkSize;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

bool cmp(Pos a, Pos b) {
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int main() {
	int ans = 0;
	int eatCnt = 0;
	sharkSize = 2;

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 9) {
				shark.x = j;
				shark.y = i;
			}
			else if (Map[i][j] != 0) fishes[Map[i][j]].push_back({ j, i });
		}


	while (true) {
		if (eatCnt == sharkSize && sharkSize != 7) {
			sharkSize++;
			eatCnt = 0;
		}
		memset(visited, -1, sizeof(visited));
		fishList.clear();
		minList.clear();
		queue<Pos> q;
		int minDist = 401;
		int eatSize = 7;
		bool out = true;
		for (int i = 1; i < sharkSize; i++) 
			for (auto iter = fishes[i].begin(); iter != fishes[i].end(); iter++) 
				fishList.push_back((*iter));

		q.push(shark);
		visited[shark.y][shark.x] = 0;
		while (!q.empty()) {
			Pos cur = q.front();
			q.pop();


			if (find(fishList.begin(), fishList.end(), cur) != fishList.end()) {
				if (minDist > visited[cur.y][cur.x]) {
					minDist = visited[cur.y][cur.x];
					minList.clear();
					minList.push_back(cur);
					out = false;
					eatSize = Map[cur.y][cur.x];
				}
				else if (minDist == visited[cur.y][cur.x]) minList.push_back(cur);
				continue;
			}

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				else if (visited[ny][nx] == -1 && visited[cur.y][cur.x] < minDist && Map[ny][nx] <= sharkSize) {
					visited[ny][nx] = visited[cur.y][cur.x] + 1;
					q.push({ nx, ny });
				}
			}
		
			
		}
		if (out) break; // not found
		else { // found
			sort(minList.begin(), minList.end(), cmp);
			eatCnt++;
			ans += minDist;
			Map[shark.y][shark.x] = 0;
			shark = minList[0];
			fishes[Map[shark.y][shark.x]].erase(find(fishes[Map[shark.y][shark.x]].begin(), fishes[Map[shark.y][shark.x]].end(), shark));
			Map[shark.y][shark.x] = 9;
			bool check = true;
			for (int i = 1; i <= 6; i++)
				if (fishes[i].size() != 0) check = false;
			if (check) break;
		}
	}
	printf("%d\n", ans);
	return 0;
}