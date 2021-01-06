#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, top = -1, Int;
	int stack[10000];
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
			stack[++top] = Int;
		}
		else if (input == "pop")
		{
			if (top == -1)
				cout << -1 << "\n";
			else
				cout << stack[top--] << "\n";
		}
		else if (input == "size")
		{
			cout << top + 1 << "\n";
		}
		else if (input == "empty")
		{
			if (top == -1)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (input == "top")
		{
			if (top == -1)
				cout << -1 << "\n";
			else
				cout << stack[top] << "\n";
		}
	}



	return 0;
}