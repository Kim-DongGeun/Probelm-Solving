#include <iostream>
#include <vector>
using namespace std;

int N, save;
vector<int> arr[100001];
vector<int> ans(100001);
bool check[100001];


void dfs(int cur)
{
	check[cur] = true;

	for (int i = 0; i < arr[cur].size(); i++)
	{
		if (check[arr[cur][i]] == false)
		{
			ans[arr[cur][i]] = cur;
			dfs(arr[cur][i]);
		}
	}
	
}

int main()
{
	scanf("%d", &N);

	int a, b;
	for (int i = 1; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(1);

	for(int i = 2 ; i <= N; i++)
		printf("%d\n", ans[i]);

	return 0;
}