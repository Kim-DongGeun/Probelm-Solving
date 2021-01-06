/*
	idea : 백트래킹 + dfs
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

char arr[22][22];
bool check[26] = { false };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int ans = 0;
int R, C;

void dfs(int x, int y, int cnt)
{
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx <= 0 || nx > C || ny <= 0 || ny > R) continue;

		if (check[arr[ny][nx] - 'A'] == false)
		{
			check[arr[ny][nx] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			check[arr[ny][nx] - 'A'] = false;
		}
	}
}

int main()
{
	scanf("%d %d", &R, &C);

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			scanf(" %c", &arr[i][j]);

	check[arr[1][1] - 'A'] = true;
	dfs(1, 1, 1);
	printf("%d\n", ans);
	return 0;
}