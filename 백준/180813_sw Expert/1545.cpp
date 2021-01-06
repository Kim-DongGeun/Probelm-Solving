#include <iostream>
using namespace std;

int main()
{
	int input;
	cin >> input;
	while (input >= 0)
	{
		cout << input-- << " ";
	}
	return 0;
}