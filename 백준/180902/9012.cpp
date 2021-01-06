#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main()
{
	int N;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		bool ok = false;
		string input;
		stack<char> s;
		
		getline(cin, input);

		for (char c : input)
		{
			if (c == '(')
				s.push('(');
			else if (c == ')')
			{
				if (s.empty())
				{
					printf("NO\n");
					ok = true;
					break;
				}
				else
				{
					s.pop();
				}
			}
		}
		if (s.empty() && !ok)
			printf("YES\n");
		if (!s.empty())
			printf("NO\n");
	}
	return 0;
}