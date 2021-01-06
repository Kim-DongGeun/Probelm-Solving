#include <iostream>
#include <vector>
using namespace std;

vector<int> map[1001];
int check[1001];
int T, N, input;


void dfs(int v)
{
	check[v] = 1;
	for(int x : map[v])
	{
		if (check[x] == 0)
			dfs(x);
	}
}

int main()
{
	

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
		{
			map[i].clear();
			check[i] = 0;
		}

		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &input);
			map[i].push_back(input);
			map[input].push_back(i);
		}

		int count = 0;
		for (int i = 1; i <= N; i++)
			if (check[i] == 0)
			{
				dfs(i);
				count++;
			}

		printf("%d\n", count);
	}
	return 0;
}