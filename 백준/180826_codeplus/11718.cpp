/*
	scanf로 풀려고했지만 잘안됨
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;

	while (true)
	{
		getline(cin, input);
		if (input == "")
			break;
		cout << input << "\n";
	}
	return 0;
}