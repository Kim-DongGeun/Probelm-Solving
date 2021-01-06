#include <iostream>
#include <algorithm>
using namespace std;

long long arr[1000001];

int main()
{
	int N, M;
	long long big = 0;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		big = max(big, arr[i]);
	}

	int ans = 0;
	long long small = 1;

	while (small <= big)
	{
		long long mid = (big + small) / 2;

		long long sum = 0;
		for (int i = 1; i <= N; i++)
		{
			if(arr[i] > mid)
				sum += arr[i] - mid;
		}

		if (sum < M)
			big = mid - 1;
		else
		{
			ans = max(ans, (int)mid);
			small = mid + 1;
		}
	}

	printf("%d\n", ans);
	return 0;
}