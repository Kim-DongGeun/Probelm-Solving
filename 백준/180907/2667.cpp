#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[27][27];
int check[27][27];
int index = 0;
int num, N;
vector<int> ans;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void dfs(int curR, int curC)
{
	check[curR][curC] = index;

	for (int i = 0; i < 4; i++)
	{
		int nextR = curR + dy[i];
		int nextC = curC + dx[i];
		if (nextR > 0 && nextR <= N && nextC > 0 && nextC <= N && !check[nextR][nextC] && map[nextR][nextC])
		{
			++num;
			dfs(nextR, nextC);
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!check[i][j] && map[i][j])
			{
				num = 1;
				++index;
				dfs(i, j);
				ans.push_back(num);
			}
		}
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int x : ans)
		printf("%d\n", x);

	return 0;
}