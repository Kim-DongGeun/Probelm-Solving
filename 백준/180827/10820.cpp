#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	while (getline(cin, input))
	{
		int small = 0, big = 0, space = 0, num = 0;
		for (char a : input)
		{
			if (a >= 65 && a <= 90)
				big++;
			else if (a >= 97 && a <= 122)
				small++;
			else if (a >= 48 && a <= 57)
				num++;
			else if (a == 32)
				space++;
		}
		cout << small << " " << big << " " << num << " " << space << "\n";
	}
	return 0;
}