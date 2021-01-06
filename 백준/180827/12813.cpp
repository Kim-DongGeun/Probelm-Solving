#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main()
{
	string input;

	cin >> input;
	bitset<100000> b1(input);

	cin >> input;
	bitset<100000> b2(input);

	cout << (b1 & b2) << "\n";
	cout << (b1 | b2) << "\n";
	cout << (b1 ^ b2) << "\n";
	cout << (~b1) << "\n";
	cout << (~b2) << "\n";

	return 0;
}