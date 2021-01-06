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

	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
			cout << " ";
		cout << "*";
		for (int j = 0; j < 2 * i - 1; j++)
			cout << " ";
		if (i == 0)
			cout << "\n";
		else 
			cout << "*\n";
	}
	for (int i = 0; i < 2 * N - 1; i++)
		cout << "*";
	cout << "\n";

	return 0;
}