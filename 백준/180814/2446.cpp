#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= 2 * N - 1; i++)
	{
		for (int k = 0; k < N - abs(N - i) - 1; k++)
			cout << " ";
		for (int j = 0; j < 2 * abs(N - i) + 1; j++)
			cout << "*";
		cout << "\n";
	}
	return 0;
}