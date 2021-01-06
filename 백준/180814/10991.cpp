#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	if (N == 1)
	{
		cout << "*\n";
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1 - i; j > 0; j--)
			cout << " ";
		cout << "*";
		for (int j = 0; j < i; j++)
			cout << " *";
		cout << "\n";
	}
	return 0;
}