#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, sum = 0;
	string input;

	cin >> N;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
		sum += input[i] - '0';
	cout << sum << endl;
	return 0;
}