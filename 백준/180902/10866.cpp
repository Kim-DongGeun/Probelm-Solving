#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	deque<int> d;
	int N, num;
	string input;

	scanf("%d", &N);

	while (N--)
	{
		cin >> input;

		if (input == "push_front")
		{
			cin >> num;

			d.push_front(num);
		}
		else if (input == "push_back")
		{
			cin >> num;

			d.push_back(num);
		}
		else if (input == "pop_front")
		{
			if (d.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", d.front());
				d.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (d.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", d.back());
				d.pop_back();
			}
		}
		else if (input == "size")
		{
			printf("%d\n", d.size());
		}
		else if (input == "empty")
		{
			printf("%d\n", d.empty());
		}
		else if (input == "front")
		{
			if (d.empty())
				printf("-1\n");
			else
				printf("%d\n", d.front());
		}
		else if (input == "back")
		{
			if (d.empty())
				printf("-1\n");
			else
				printf("%d\n", d.back());
		}
	}
	return 0;
}