#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <math.h>
using namespace std;

int index = 0, N;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int map[102][102];
int check[102][102] = { 0 };

queue<tuple<int, int, int>> q;

void dfs(int curR, int curC)
{
	check[curR][curC] = index;

	for (int i = 0; i < 4; i++)
	{
		int nextR = curR + dy[i];
		int nextC = curC + dx[i];

		if (nextR > 0 && nextR <= N && nextC > 0 && nextC <= N && !check[nextR][nextC] && map[nextR][nextC] == 1)
		{
			dfs(nextR, nextC);
			q.push({ nextR, nextC, index });
		}
	}
}

int main()
{
	scanf("%d", &N);

	//맵
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
			if (map[i][j] == 1 && !check[i][j])
			{
				++index;
				dfs(i, j);
				q.push({ i, j, index });
			}
		}
	}

	int ans = INT32_MAX;
	//섬 전부를 순회하면서 최단거리를 찾음
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

			//같은 섬이면 continue
			if (num == Num) continue;

			ans = min(ans, (abs(y - Y) + abs(x - X)));
		}
	}

	printf("%d\n", ans - 1);
	return 0;
}