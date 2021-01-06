#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int N, a;
	string input;
	queue<int> de;
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
				cout << de.front() << "\n";
				de.pop();
			}
			else
				cout << -1 << "\n";
		}
		else if (input == "size")
			cout << de.size() << "\n";
		else if (input == "empty")
			cout << de.empty() << "\n";
		else if (input == "front")
		{
			if (de.empty())
				cout << -1 << "\n";
			else
				cout << de.front() << "\n";
		}
		else if (input == "back")
		{
			if (de.empty())
				cout << -1 << "\n";
			else
				cout << de.back() << "\n";
		}
	}
	return 0;
}