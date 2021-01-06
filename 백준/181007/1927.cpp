/*
	idea : 큐를 이용하면되고 최소힙을 만드려면 마이너스를 붙혀서
			푸쉬해준다.
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> q;
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int x;
		scanf("%d", &x);

		if (x) q.push(-x);
		else
		{
			printf("%d\n", q.empty() ? 0 : -q.top());
			if (!q.empty()) q.pop();
		}
	}
	return 0;
}