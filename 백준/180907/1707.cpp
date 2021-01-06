#include <iostream>
#include <vector>
using namespace std;

vector<int>map[20001];
pair<bool, int> dfs_visited[20001];

void dfs(int cur, int index)
{
	dfs_visited[cur].first = true;
	dfs_visited[cur].second = index;

	for (int next : map[cur])
	{
		if (dfs_visited[next].first == false)
			dfs(next, 3 - index);
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int N, M;
		scanf("%d %d", &N, &M);

		//초기화
		for (int i = 1; i <= N; i++)
		{
			dfs_visited[i].first = false;
			dfs_visited[i].second = 0;
			while (!map[i].empty())
				map[i].pop_back();
		}
		//맵
		for (int i = 0; i < M; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			map[u].push_back(v);
			map[v].push_back(u);
		}

		//전부 순회
		for (int i = 1; i <= N; i++)
		{
			if (dfs_visited[i].first == false)
			{
				dfs(i,1);
			}
		}

		//연결되있는 정점들중에서 인덱스가 같으면 NO
		bool ok = true;
		for (int i = 1; i <= N; i++)
		{
			for (int next : map[i])
			{
				if (dfs_visited[i].second == dfs_visited[next].second)
				{
					ok = false;
					break;
				}
			}
			if (!ok)break;
		}

		if (ok)	printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}