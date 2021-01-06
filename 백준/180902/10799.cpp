#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int ans = 0;
	string input;
	stack<int> s;
	getline(cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			s.push(i);
		}
		else if (input[i] == ')')
		{
			if ((i - s.top()) == 1)
			{
				s.pop();
				ans += s.size();
			}
			else
			{
				s.pop();
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}