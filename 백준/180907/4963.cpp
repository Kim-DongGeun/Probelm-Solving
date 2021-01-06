#include <iostream>
#include <algorithm>
using namespace std;

int map[52][52];
int check[52][52];
int index;
int N, M;

int dx[8] = { 1,0,-1,0, 1, -1, -1, 1 };
int dy[8] = { 0,1,0,-1, 1,1,-1,-1 };

void dfs(int curR, int curC)
{
	check[curR][curC] = index;

	for (int i = 0; i < 8; i++)
	{
		int nextR = curR + dy[i];
		int nextC = curC + dx[i];
		if (nextR > 0 && nextR <= M && nextC > 0 && nextC <= N && !check[nextR][nextC] && map[nextR][nextC])
		{
			dfs(nextR, nextC);
		}
	}
}

int main()
{
	while (scanf("%d %d", &N, &M) == 2)
	{
		index = 0;
		if (N == 0 && M == 0)break;

		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				map[i][j] = 0;
				check[i][j] = 0;
			}
		}

		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (!check[i][j] && map[i][j])
				{
					++index;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", index);
	}
	return 0;
}