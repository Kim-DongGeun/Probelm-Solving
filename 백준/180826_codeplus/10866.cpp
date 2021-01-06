#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	int N, a;
	string input;
	deque<int> de;
	cin >> N;

	while (N--)
	{
		cin >> input;

		if (input == "push_front")
		{
			cin >> a;
			de.push_front(a);
		}
		else if (input == "push_back")
		{
			cin >> a;
			de.push_back(a);
		}
		else if (input == "pop_front")
		{
			if (!de.empty())
			{
				cout << de.front() << "\n";
				de.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (input == "pop_back")
		{
			if (!de.empty())
			{
				cout << de.back() << "\n";
				de.pop_back();
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