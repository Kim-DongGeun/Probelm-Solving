#include <iostream>
using namespace std;

int map[1001][1001]{ 0 };
bool check[1001]{ false };

int N, M;
int a, b;


int dfs(int v)
{
	check[v] = true;

	for (int i = 1; i <= N; i++)
	{
		if (map[v][i] == 1 && !check[i])
			dfs(i);
	}
	return 0;
}


int main()
{

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = map[b][a] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!check[i])
		{
			ans++;
			dfs(i);
		}
	}

	printf("%d\n", ans);

	return 0;
}