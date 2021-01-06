/*
	idea : �̺�Ž������ ���� ���̸� ������ ������ ���鼭 Ž��
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long arr[10001];

int main()
{
	int K, N;
	scanf("%d %d", &K, &N);
	long long big = 0, small = 1;

	for (int i = 1; i <= K; i++) {
		scanf("%lld", &arr[i]);
		big = max(big, arr[i]);
	}


	int sum;
	long long ans = 0;
	while (small <= big)
	{
		long long mid = (small + big) / 2;
		sum = 0;

		for (int i = 1; i <= K; i++)
			sum += arr[i] / mid;

		if (sum < N)
			big = mid - 1;
		else
		{
			ans = max(ans, mid);
			small = mid + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}