#include <iostream>
#include <queue>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int map[102][102];
int check[101][101];
queue<pair<int, int>> q;

int M, N;

int main()
{
	scanf("%d %d", &N, &M);

	// ¸Ê
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	q.push(make_pair(1, 1));
	check[1][1] = 1;


	while (!q.empty())
	{
		int nextY = q.front().first;
		int nextX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dr = nextY + dy[i];
			int dc = nextX + dx[i];

			if (dr > 0 && dr <= N && dc > 0 && dc <= M && map[dr][dc] == 1 && check[dr][dc] == 0)
			{
				check[dr][dc] = check[nextY][nextX] + 1;
				q.push(make_pair(dr, dc));
			}
		}
	}

	printf("%d\n", check[N][M]);
	return 0;
}