#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Data {
	int depth;
	pair<int, int> location;
};

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };
int R, C;
char Map[51][51];
pair<int, int> Start;
pair<int, int> End;
vector<pair<int, int>> water;


int main() {
	scanf_s("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf_s("%c", &Map[i][j]);
			if (Map[i][j] == 'D') {
				Start.first = i;
				Start.second = j;
			}
			else if (Map[i][j] == 'S') {
				End.first = i;
				End.second = j;
			}
			else if (Map[i][j] == '*') {
				water.push_back(make_pair(i, j));
			}
		}
	}
	queue<Data> Q;
	queue<Data> q;
	for (auto value : water) {
		Map[value.first][value.second] = '#';
		q.push({ 0,value });
	}
	while (1) {
		while (!q.empty()) {
			Data cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.location.second + dx[i];
				int ny = cur.location.first + dy[i];
				if (nx >= 0 && nx < C && ny >= 0 && ny < R && Map[ny][nx] != 'S' && Map[ny][nx] != 'X') {
					Q.push({ cur.depth + 1, make_pair(ny, nx) });
				}
			}
		}


	}
	

}