#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> map[20001];
vector<int> check(20000, 0);

int N, M, T;
int a, b;

void dfs(int v, int index)
{
	check[v] = index;

	for (int x : map[v])
	{
		if (check[x] == 0)
			dfs(x, 3 - index);
	}
}

int main()
{
	scanf("%d", &T);

	for (int k = 1; k <= T; k++)
	{
		bool ok = false;

		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++)
		{
			map[i].clear();
			check[i] = 0;
		}

		for (int i = 0; i < M; i++) {
			scanf("%d %d", &a, &b);
			map[a].push_back(b);
			map[b].push_back(a);
		}

		for (int i = 1; i <= N; i++)
		{
			if (check[i] == 0)
				dfs(i, 1);
		}

		for (int i = 1; i <= N; i++)
		{
			for (int x : map[i])
			{
				if (check[i] == check[x])
				{
					ok = true;
					break;
				}
			}
			if (ok)break;
		}
		if (!ok)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}