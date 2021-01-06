#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	int sum = 0;

	while (getline(cin, input, ','))
	{
		sum++;
	}

	cout << sum << "\n";
	return 0;
}