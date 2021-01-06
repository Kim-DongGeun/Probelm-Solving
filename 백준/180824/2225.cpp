/*
	합분해
	중복조합으로풀면
	쉽게풀수있다.
*/
#include <iostream>
using namespace std;

long long arr[401][201] = { 0 };

long long cal(int N, int M)
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (i == j || j == 0)
				arr[i][j] = 1;
			else
				arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]) % 1000000000;
		}
	}
	return arr[N][M];
}

int main()
{
	int N, K;
	cin >> N >> K;

	printf("%lli\n", cal(N + K - 1, N));
	return 0;
}