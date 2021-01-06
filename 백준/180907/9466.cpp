#include <iostream>
using namespace std;

int map[100001];
int cnt;
bool check[100001];
bool cycle[100001];

void dfs(int cur)
{
	check[cur] = true;
	int next = map[cur];

	if (!check[next]) {
		dfs(next);
	}
	else
	{
		//사이클이면 순회하면서 갯수 체크
		if (!cycle[next]) {
			for (int x = cur; map[x] != cur; x = map[x])
			{
				cnt++;
			}
			cnt++;
		}
	}
	cycle[cur] = true;
}

int main()
{
	int T, N;
	scanf("%d", &T);

	while (T--)
	{
		cnt = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			map[i] = 0;
			check[i] = false;
			cycle[i] = false;
		}

		//맵
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &map[i]);
		}
		//탐색	
		for (int i = 1; i <= N; i++)
		{
			if (!check[i])
				dfs(i);
		}

		printf("%d\n", N - cnt);
	}

	return 0;
}