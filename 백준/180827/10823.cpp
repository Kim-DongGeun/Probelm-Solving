#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string input, s;
	long long sum = 0;

	while (cin >> input)
		s += input;

	istringstream sin(s);

	while (getline(sin, s, ','))
		sum += stoll(s);

	cout << sum << "\n";


	return 0;
}