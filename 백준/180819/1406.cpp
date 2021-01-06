#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	getline(cin, input);

	int N, cusor;
	scanf_s("%d", &N);

	cusor = input.length();

	string temp;

	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		getline(cin, temp);
		string ch;
		if (temp.find(' ') != string::npos)
		{
			ch = temp[2];
			temp = temp[0];
		}

		if (temp == "L")
		{
			if (cusor != 0)
				cusor--;
		}
		else if (temp == "D")
		{
			if (cusor != input.length())
				cusor++;
		}
		else if (temp == "B")
		{
			if (cusor != 0)
			{
				input.erase(cusor - 1, 1);
				cusor--;
			}
		}
		else if (temp == "P")
		{
				input.insert(cusor, ch);
				cusor++;
		}
	}

	printf("%s\n", input.c_str());

	return 0;
}