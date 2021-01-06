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

		//�ʱ�ȭ
		for (int i = 1; i <= N; i++)
		{
			dfs_visited[i].first = false;
			dfs_visited[i].second = 0;
			while (!map[i].empty())
				map[i].pop_back();
		}
		//��
		for (int i = 0; i < M; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			map[u].push_back(v);
			map[v].push_back(u);
		}

		//���� ��ȸ
		for (int i = 1; i <= N; i++)
		{
			if (dfs_visited[i].first == false)
			{
				dfs(i,1);
			}
		}

		//������ִ� �������߿��� �ε����� ������ NO
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