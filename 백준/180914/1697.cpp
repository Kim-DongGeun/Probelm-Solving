/*
		idea : 시작 숫자부터 마지막 숫자까지 bfs로 전부 탐색해서 최단거리를 찾음
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
	printf("%d\n", check[K]-1); //처음 거리를 1로 해서 1을뺴줌
	return 0;
}