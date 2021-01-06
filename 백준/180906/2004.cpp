#include <iostream>
using namespace std;

int main()
{
	long long N, M, upTwo = 0, upFive = 0, bottomTwo = 0, bottomFive = 0;
	scanf("%lld %lld", &N, &M);

	long long arr[3] = { N, M, N - M };

	for (long long j = 2; j <= arr[0]; j *= 2)
	{
		upTwo += arr[0] / j;
	}
	for (long long j = 5; j <= arr[0]; j *= 5)
	{
		upFive += arr[0] / j;
	}


	for (long long i = 1; i < 3; i++)
	{
		for (long long j = 2; j <= arr[i]; j *= 2)
		{
			bottomTwo += arr[i] / j;
		}
		for (long long j = 5; j <= arr[i]; j *= 5)
		{
			bottomFive += arr[i] / j;
		}
	}

	long long two = upTwo - bottomTwo;
	long long five = upFive - bottomFive;

	two < five ? printf("%lld\n", two) : printf("%lld\n", five);
	return 0;
}