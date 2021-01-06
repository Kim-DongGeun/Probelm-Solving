#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string input;
	cin >> input;

	for (int i = 'a'; i <= 'z'; i++)
		cout << count(input.begin(), input.end(), i) << ' ';
	return 0;
}