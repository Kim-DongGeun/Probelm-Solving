#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, count = 0;
	cin >> N;

	string input;

	for (int i = 0; i < N; i++)
	{
		cin >> input;

		for (int j = 0; j < input.length() && count >= 0; j++)
		{
			if (input[j] == '(')
				count++;
			else if (input[j] == ')')
				count--;
		}

		if (count == 0)
			printf("YES\n");
		else
			printf("NO\n");

		count = 0;
	}

	return 0;
}