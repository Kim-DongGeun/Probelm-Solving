#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int N, a;
	string input;
	stack<int> de;
	cin >> N;

	while (N--)
	{
		cin >> input;

		if (input == "push")
		{
			cin >> a;
			de.push(a);
		}
		else if (input == "pop")
		{
			if (!de.empty())
			{
				cout << de.top() << "\n";
				de.pop();
			}
			else
				cout << -1 << "\n";
		}
		else if (input == "size")
			cout << de.size() << "\n";
		else if (input == "empty")
			cout << de.empty() << "\n";
		else if (input == "top")
		{
			if (de.empty())
				cout << -1 << "\n";
			else
				cout << de.top() << "\n";
		}
	}
	return 0;
}