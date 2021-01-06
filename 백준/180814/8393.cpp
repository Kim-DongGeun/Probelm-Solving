#include <iostream>
using namespace std;

int main()
{
	int N, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		sum += i + 1;
	cout << sum << "\n";
	return 0;
}