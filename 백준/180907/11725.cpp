#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check[100001];
int line[100000];
int parent[100000];
vector<int> map[100001];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i < N; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		map[u].push_back(v);
		map[v].push_back(u);
	}

	queue<int> q;
	q.push(1);
	check[1] = true;

	//루트부터 내려오면서 부모노드를 찾음
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int a : map[x])
		{
			if (!check[a]) {
				q.push(a);
				parent[a] = x;
				check[a] = true;
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		printf("%d\n", parent[i]);
	}
	return 0;
}