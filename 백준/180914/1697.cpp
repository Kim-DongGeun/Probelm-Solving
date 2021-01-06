/*
		idea : ���� ���ں��� ������ ���ڱ��� bfs�� ���� Ž���ؼ� �ִܰŸ��� ã��
*/
#include <iostream>
#include <queue>
using namespace std;

int check[100001] = { 0 };

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	check[N] = 1;
	queue<int> q;
	q.push(N);

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		if (x == K) break;

		int next[3] = { x + 1, x - 1, 2 * x };
		for (int i = 0; i < 3; i++)
		{
			if (next[i] >= 0 && next[i] <= 100000 && !check[next[i]])
			{
				check[next[i]] = check[x] + 1;
				q.push(next[i]);
			}
		}
	}
	printf("%d\n", check[K]-1); //ó�� �Ÿ��� 1�� �ؼ� 1������
	return 0;
}