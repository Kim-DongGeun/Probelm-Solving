#include <iostream>
using namespace std;

int map[1001];
bool check[1001];
int ans;

void dfs(int cur, int start)
{
	check[cur] = true;

	int next = map[cur];
	
	if (next == start)
	{
		ans++;
	}
	else if (check[next] == false)
		dfs(next, start);
}

int main()
{
	int T, N;
	scanf("%d", &T);

	while (T--)
	{
		ans = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			check[i] = false;

		//¸Ê
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &map[i]);
		}
		//Å½»ö	
		for (int i = 1; i <= N; i++)
		{
			if (check[i] == false)
				dfs(i, i);
		}

		printf("%d\n", ans);
	}

	return 0;
}