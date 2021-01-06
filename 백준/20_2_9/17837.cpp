#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pos { int x, y, dir, height; };
struct info { int cnt, dir, height; };

const int dx[5] = { 0, 1, -1 ,0, 0 };
const int dy[5] = { 0, 0, 0, -1, 1 };

int N, K;
int Map[13][13];
vector<info> visited[13][13];
pos horse[11];

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> Map[i][j];

	for (int i = 0; i < K; i++) {
		cin >> horse[i].y >> horse[i].x >> horse[i].dir;
		visited[horse[i].y][horse[i].x].push_back({ i,  horse[i].dir, 0 });
	}
}

void solve() {
	for (int time = 1; time <= 1000; time++) {
		for (int i = 0; i < K; i++) {
			int x = horse[i].x;
			int y = horse[i].y;
			int nx = horse[i].x + dx[horse[i].dir];
			int ny = horse[i].y + dy[horse[i].dir];

			if (nx <= 0 || ny <= 0 || nx > N || ny > N || Map[ny][nx] == 2) { // 파란색 일때
				if (horse[i].dir <= 2) horse[i].dir = 3 - horse[i].dir;
				else horse[i].dir = 7 - horse[i].dir;
				nx = horse[i].x + dx[horse[i].dir];
				ny = horse[i].y + dy[horse[i].dir];
				if (nx <= 0 || ny <= 0 || nx > N || ny > N || Map[ny][nx] == 2) { // 방향바꿨는데 파란색일 떄
					auto iter = visited[y][x].begin() + horse[i].height;
					if ((*iter).dir <= 2) (*iter).dir = 3 - (*iter).dir;
					else (*iter).dir = 7 - (*iter).dir;
					
				}
				else if(Map[ny][nx] == 0) { // 방향바꿨는데 흰색일 때
					auto iter = visited[y][x].begin() + horse[i].height;
					for (; iter != visited[y][x].end();) {
						(*iter).height = visited[ny][nx].size();

						if ((*iter).height == 3) {
							printf("%d\n", time);
							exit(0);
						}

						int temp = (*iter).cnt;
						visited[ny][nx].push_back((*iter));
						horse[temp].height = (*iter).height;
						iter = visited[y][x].erase(iter);
						horse[temp].x = nx;
						horse[temp].y = ny;
					}
					
				}
				else if (Map[ny][nx] == 1) { // 방향바꿨는데 빨간색 일 때
					reverse(visited[y][x].begin() + horse[i].height, visited[y][x].end());
					auto iter = visited[y][x].begin() + horse[i].height;
					for (; iter != visited[y][x].end();) {
						(*iter).height = visited[ny][nx].size();

						if ((*iter).height == 3) {
							printf("%d\n", time);
							exit(0);
						}

						int temp = (*iter).cnt;
						visited[ny][nx].push_back((*iter));
						horse[temp].height = (*iter).height;
						iter = visited[y][x].erase(iter);
						horse[temp].x = nx;
						horse[temp].y = ny;
					}
				}
			}
			else if (Map[ny][nx] == 1) { // 빨간색 일떄
				reverse(visited[y][x].begin() + horse[i].height, visited[y][x].end());
				auto iter = visited[y][x].begin() + horse[i].height;
				for (; iter != visited[y][x].end();) {
					(*iter).height = visited[ny][nx].size();

					if ((*iter).height == 3) {
						printf("%d\n", time);
						exit(0);
					}

					int temp = (*iter).cnt;
					visited[ny][nx].push_back((*iter));
					horse[temp].height = (*iter).height;
					iter = visited[y][x].erase(iter);
					horse[temp].x = nx;
					horse[temp].y = ny;
				}
			}
			else if (Map[ny][nx] == 0) { // 흰색 일때
				auto iter = visited[y][x].begin() + horse[i].height;
				for (; iter != visited[y][x].end();) {
					(*iter).height = visited[ny][nx].size();

					if ((*iter).height == 3) {
						printf("%d\n", time);
						exit(0);
					}

					int temp = (*iter).cnt;
					visited[ny][nx].push_back((*iter));
					horse[temp].height = (*iter).height;
					iter = visited[y][x].erase(iter);
					horse[temp].x = nx;
					horse[temp].y = ny;
				}
			}
		}
	}
	printf("-1\n");
}

int main() {
	input();
	solve();
	return 0;
}