#include <iostream>
#include <vector>
using namespace std;

vector<int>map[1001];
bool dfs_visited[1001] = { false };

void dfs(int cur)
{
	dfs_visited[cur] = true;

	for (int i = 0; i < map[cur].size(); i++)
	{
		int next = map[cur][i];
		if (dfs_visited[next] == false)
			dfs(next);
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		
		map[u].push_back(v);
		map[v].push_back(u);
	}


	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dfs_visited[i] == false)
		{
			dfs(i);
			ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}