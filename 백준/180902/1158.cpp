#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	queue<int> q;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		q.push(i);


	printf("<");
	while (q.size() != 1)
	{
		for (int i = 1; i < M; i++)
		{
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>", q.front());
	return 0;
}