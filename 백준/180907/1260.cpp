#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


vector<int> map[1001];
bool dfs_visited[1001] = { false };
bool bfs_visited[1001] = { false };

void dfs(int cur)
{
	printf("%d ", cur);
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
	int N, M, start;

	scanf("%d %d %d", &N, &M, &start);

	for(int i = 0 ; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		map[a].push_back(b);
		map[b].push_back(a);
	}

	//�迭�� ��� ������������ Ž���ؼ� ��������� ���ʹ� ������ 
	//�������� �ʾƼ� ������ ������Ѵ�.
	for (int i = 1; i <= N; i++)
		sort(map[i].begin(), map[i].end());

	dfs(start);
	printf("\n");

	queue<int> q;
	q.push(start);
	bfs_visited[start] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		printf("%d ", cur);

		for (int i = 0; i < map[cur].size(); i++)
		{
			int next = map[cur][i];
			if (bfs_visited[next] == false)
			{
				bfs_visited[next] = true;
				q.push(next);
			}
		}
	}

	return 0;
}