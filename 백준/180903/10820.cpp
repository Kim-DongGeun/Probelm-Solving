#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	while (getline(cin, input))
	{
		int big = 0, small = 0, space = 0, num = 0;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] >= 65 && input[i] <= 90)
				big++;
			else if (input[i] >= 97 && input[i] <= 122)
				small++;
			else if (input[i] == 32)
				space++;
			else if (input[i] >= 48 && input[i] <= 57)
				num++;
		}
		printf("%d %d %d %d\n", small, big, num, space);
	}
	return 0;
}