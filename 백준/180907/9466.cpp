#include <iostream>
using namespace std;

int map[100001];
int cnt;
bool check[100001];
bool cycle[100001];

void dfs(int cur)
{
	check[cur] = true;
	int next = map[cur];

	if (!check[next]) {
		dfs(next);
	}
	else
	{
		//����Ŭ�̸� ��ȸ�ϸ鼭 ���� üũ
		if (!cycle[next]) {
			for (int x = cur; map[x] != cur; x = map[x])
			{
				cnt++;
			}
			cnt++;
		}
	}
	cycle[cur] = true;
}

int main()
{
	int T, N;
	scanf("%d", &T);

	while (T--)
	{
		cnt = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			map[i] = 0;
			check[i] = false;
			cycle[i] = false;
		}

		//��
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &map[i]);
		}
		//Ž��	
		for (int i = 1; i <= N; i++)
		{
			if (!check[i])
				dfs(i);
		}

		printf("%d\n", N - cnt);
	}

	return 0;
}