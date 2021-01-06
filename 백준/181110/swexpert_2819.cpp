/*
	어디가 틀린지 모르겟다
*/
#include <iostream>
#include <set>
using namespace std;

int map[4][4];
set<int> ans;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

void dfs(int x, int y, int count, int num) {
	if (count == 7) {
		ans.insert(num); return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;

		dfs(nx, ny, count + 1, num * 10 + map[ny][nx]);
	}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		ans.clear();
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				scanf("%d", &map[i][j]);

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				dfs(j, i, 1, map[i][j]);

		printf("#%d %d\n", t, ans.size());
	}
	return 0;
}