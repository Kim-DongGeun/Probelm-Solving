/*
	idea : 오른차순으로 정렬해서 더하면 최솟값
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
			ans += (long long)arr[j];
	}

	printf("%lld\n", ans);
	return 0;
}