#include <iostream>
using namespace std;

int  map[100001];
int check[100001];
bool finished[100001];
int T, N, input, cnt;


void dfs(int v)
{
	check[v] = 1;
	int next = map[v];

	if (!check[next])
		dfs(next);
	else
	{
		if (!finished[next])
		{
			for (int x = v; map[x] != v; x = map[x]) {
				cnt++;
			}
			cnt++;
		}
	}
	finished[v] = true;
}

int main()
{

	scanf("%d", &T);

	while (T--)
	{
		cnt = 0;
		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
		{
			map[i] = 0;
			check[i] = 0;
			finished[i] = false;
		}

		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &input);
			map[i] = input;
		}

		for (int i = 1; i <= N; i++) {
			if(!check[i])
				dfs(i);
		}
		printf("%d\n", N - cnt);
	}
	return 0;
}