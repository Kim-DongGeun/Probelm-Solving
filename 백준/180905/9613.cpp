#include<iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)return a;
	else
		gcd(b, a%b);
}

int main()
{
	long long arr[101];
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int N;
		scanf("%d", &N);
		
		for (int i = 1; i <= N; i++)
			scanf("%lld", &arr[i]);

		long long sum = 0;
		for (int i = 1; i < N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				sum += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}