#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;
	int N, num;
	string input;
	
	scanf("%d", &N);

	while (N--)
	{
		cin >> input;

		if (input == "push")
		{
			cin >> num;

			s.push(num);
		}
		else if (input == "pop")
		{
			if (s.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if (input == "size")
		{
			printf("%d\n", s.size());
		}
		else if (input == "empty")
		{
			printf("%d\n", s.empty());
		}
		else if (input == "top")
		{
			if (s.empty())
				printf("-1\n");
			else
				printf("%d\n", s.top());
		}
	}
	return 0;
}