/*
	idea : 그냥 bfs문제
*/
#include <iostream>
#include <queue>
using namespace std;

int check[1000001] = { 0 };

int main()
{
	int F, S, G, U, D;

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	queue<int> q;
	q.push(S);
	check[S] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == G) break;

		int up = cur + U;
		int down = cur - D;

		if (up <= 1000000 && !check[up])
		{
			q.push(up);
			check[up] = check[cur] + 1;
		}
		if (down > 0 && !check[down]) {
			q.push(down);
			check[down] = check[cur] + 1;
		}
	}

	if (check[G] == 0) printf("use the stairs\n");
	else printf("%d\n", check[G] - 1);
	return 0;
}