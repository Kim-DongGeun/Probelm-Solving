#include <iostream>
using namespace std;

int map[100][100];
int visit[100][100];
bool ans = false;
pair<int, int> Start, End;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

void dfs(pair<int, int> cur)
{
	if (cur == End) ans = true;

	for (int d = 0; d < 4; d++)
	{
		int ny = cur.first + dy[d];
		int nx = cur.second + dx[d];

		if (ny <= 0 || ny >= 98 || nx <= 0 || nx >= 98 || visit[ny][nx] || map[ny][nx] == 1) continue;

		visit[ny][nx] = 1;
		dfs({ ny, nx });
		visit[ny][nx] = 0;
	}
}

int main()
{
	int test_case;
	for(int t = 1; t <= 10; t++) {
		scanf("%d", &test_case);
		ans = false;

		for(int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
			{
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) Start = { i,j };
				else if (map[i][j] == 3) End = { i,j };
				visit[i][j] = 0;
			}

		dfs(Start);
		if (ans) printf("#%d 1\n", t);
		else printf("#%d 0\n", t);
	}
	return 0;
}