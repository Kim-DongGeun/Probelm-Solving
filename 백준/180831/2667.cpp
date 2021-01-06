#include <iostream>
#include <set>
using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,-1,0,1 };

int N, index = 0;

int map[27][27];
int check[26][26] = { 0 };

void dfs(int curR, int curC)
{
	check[curR][curC] = index;

	for (int i = 0; i < 4; i++)
	{
		int dr = curR + dy[i];
		int dc = curC + dx[i];
		if (dr > 0 && dr <= N && dc > 0 && dc <= N && map[dr][dc] == 1 && check[dr][dc] == 0)
		{
			dfs(dr, dc);
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


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (check[i][j] == 0 && map[i][j] == 1)
			{
				index++;
				dfs(i, j);
			}
		}
	}
	multiset<int> ans;
	printf("%d\n", index);
	for (int k = 1; k <= index; k++) {
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[i][j] == k)
					sum++;
			}
		}
		ans.insert(sum);
	}

	for (int x : ans)
		printf("%d\n", x);

	return 0;
}