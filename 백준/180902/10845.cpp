#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int N, num;
	string input;

	scanf("%d", &N);

	while (N--)
	{
		cin >> input;

		if (input == "push")
		{
			cin >> num;

			q.push(num);
		}
		else if (input == "pop")
		{
			if (q.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (input == "size")
		{
			printf("%d\n", q.size());
		}
		else if (input == "empty")
		{
			printf("%d\n", q.empty());
		}
		else if (input == "front")
		{
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		else if (input == "back")
		{
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.back());
		}
	}
	return 0;
}