#include <iostream>
#include <queue>
#include <tuple>
#include <math.h>
#include <algorithm>
using namespace std;

int map[102][102];
int check[101][101];
int bfs_visited[101][101];


const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int N, index = 0, ans = 10000;
queue<tuple<int, int, int>> q;

void dfs(int curR, int curC)
{
	check[curR][curC] = index;

	for (int i = 0; i < 4; i++)
	{
		int dr = curR + dy[i];
		int dc = curC + dx[i];

		if (dr > 0 && dr <= N && dc > 0 && dc <= N && map[dr][dc] == 1 && check[dr][dc] == 0) {
			q.push(make_tuple(dr, dc, index));
			dfs(dr, dc);
		}
	}
}

int main()
{
	scanf("%d", &N);

	//¸Ê
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//dfs
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 1 && check[i][j] == 0)
			{
				++index;
				q.push(make_tuple(i, j, index));
				dfs(i, j);
			}
		}
	}

	//bfs
	while (!q.empty())
	{
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		int num = get<2>(q.front());

		q.pop();

		queue<tuple<int, int, int>> Q;
		Q = q;

		while (!Q.empty())
		{
			int Y = get<0>(Q.front());
			int X = get<1>(Q.front());
			int Num = get<2>(Q.front());

			Q.pop();

			if (num == Num) continue;

			ans = min(ans, (abs(y - Y) + abs(x - X)));
		}
		
	}

	printf("%d\n", ans-1);
	return 0;
}