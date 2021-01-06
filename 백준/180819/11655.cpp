#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;

	getline(cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 97 && input[i] <= 122)
		{
			if (input[i] + 13 <= 122)
				input[i] += 13;
			else
				input[i] -= 13;
		}
		else if (input[i] >= 65 && input[i] <= 90)
		{
			if (input[i] + 13 <= 90)
				input[i] += 13;
			else
				input[i] -= 13;
		}
	}

	printf("%s\n", input.c_str());

	return 0;
}