#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, front = 0, back = 0, Int;
	int queue[10000];
	string input;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		getline(cin, input);

		if (input.find(' ') != string::npos)
		{
			Int = atoi(input.substr(input.find_first_of(' ') + 1).c_str());
			input = input.substr(0, input.find_first_of(' '));
		}

		if (input == "push")
		{
			queue[back++] = Int;
		}
		else if (input == "pop")
		{
			if (back <= front)
				cout << -1 << "\n";
			else
				cout << queue[front++] << "\n";
		}
		else if (input == "size")
		{
			cout << back - front << "\n";
		}
		else if (input == "empty")
		{
			if (back <= front)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (input == "front")
		{
			if (back <= front)
				cout << -1 << "\n";
			else
				cout << queue[front] << "\n";
		}
		else if (input == "back")
		{
			if (back <= front)
				cout << -1 << "\n";
			else
				cout << queue[back-1] << "\n";
		}
	}
	return 0;
}