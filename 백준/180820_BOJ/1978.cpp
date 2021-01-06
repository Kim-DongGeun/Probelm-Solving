#include <iostream>
using namespace std;

int main()
{
	int N, input, answer = 0;
	bool found = false;
	cin >> N;

	while (N--)
	{
		cin >> input;

		if (input == 1)
			continue;

		for (int i = 2; i <= (int)sqrt(input); i++)
		{
			if (input % i == 0)
			{
				found = true;
				break;
			}
		}

		if (!found)
			answer++;
		else
			found = false;
	}

	printf("%d\n", answer);
	return 0;
}