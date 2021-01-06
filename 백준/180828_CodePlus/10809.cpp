#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input;

	cin >> input;

	for (int i = 'a'; i <= 'z'; i++)
	{
		auto it = find(input.begin(), input.end(), i);
		if (it == input.end())
			cout << -1 << ' ';
		else
			cout << it - input.begin() << ' ';
	}
		

	return 0;
}