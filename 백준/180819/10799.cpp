#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	cin >> input;
	int hight = 0, answer = 0;

	for (int i = 0; i < input.length() - 1; i++)
	{
		if (input[i] == '(' && input[i + 1] == ')')
			input.replace(i, 2, " ");
	}

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
			hight++;
		else if (input[i] == ' ')
			answer += hight;
		else if (input[i] == ')')
		{
			answer++;
			hight--;
		}
	}

	printf("%d\n", answer);
	return 0;
}