#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= 2 * N - 1; i++)
	{
		for (int j = 0; j < abs(N - i); j++)
			cout << " ";
		for (int k = 0 ;k < N - abs(N - i); k++)
			cout << "*";
		cout << "\n";
	}
	return 0;
}