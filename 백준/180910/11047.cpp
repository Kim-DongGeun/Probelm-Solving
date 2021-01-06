#include <iostream>
using namespace std;

int arr[10];

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int ans = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (K / arr[i] < 1) continue;
		else
		{
			ans += K / arr[i];
			K = K - (K / arr[i]) * arr[i];
		}
	}

	printf("%d\n", ans);
	return 0;
}