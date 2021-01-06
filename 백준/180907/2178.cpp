#include <iostream>
#include <queue>
using namespace std;

int map[102][102];
int check[102][102] = { 0 };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	int R, C, num = 1;

	scanf("%d %d", &R, &C);

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push({ 1,1 });
	check[1][1] = 1;

	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextR = y + dy[i];
			int nextC = x + dx[i];

			if (nextR > 0 && nextR <= R && nextC > 0 && nextC <= C && !check[nextR][nextC] && map[nextR][nextC])
			{
				q.push({ nextR, nextC });
				check[nextR][nextC] = check[y][x] + 1;
			}
		}
	}

	printf("%d\n", check[R][C]);
	return 0;
}