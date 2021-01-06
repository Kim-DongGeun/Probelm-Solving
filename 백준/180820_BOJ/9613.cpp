#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int big, int small)
{
	if (small == 0)
		return big;
	return gcd(small, big % small);
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int T;
		long long answer = 0;
		cin >> T;
		int arr[100];

		for (int j = 0; j < T; j++)
			cin >> arr[j];

		for (int j = 0; j < T - 1; j++)
		{
			for (int k = j + 1; k < T; k++)
				answer += gcd(arr[j], arr[k]);
				//answer += gcd(max(arr[j], arr[k]), min(arr[j], arr[k]));
		}
		cout << answer << "\n";
	}
	return 0;
}