#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	long long sum = 0;

	while (getline(cin, input, ','))
	{
		sum += stoll(input);
	}

	cout << sum << "\n";
	return 0;
}