#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	getline(cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		if(input[i] >= 65 && input[i] <= 90)
		{
			if (input[i] > 77)
				input[i] -= 13;
			else
				input[i] += 13;
		}
		else if (input[i] >= 97 && input[i] <= 122)
		{
			if (input[i] > 109)
				input[i] -= 13;
			else
				input[i] += 13;
		}
	}
	cout << input << "\n";
	return 0;
}