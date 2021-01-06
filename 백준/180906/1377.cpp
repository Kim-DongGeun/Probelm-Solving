#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[500001];


int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}

	sort(arr + 1, arr + N + 1);

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int sum = arr[i].second - i;
		ans = max(ans, sum);
	}
	printf("%d\n", ans+1);
	return 0;
}