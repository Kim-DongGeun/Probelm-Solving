//개어려움 보류
//공유기 문제
/*
	idea : 최대거리 - 최소거리를 반으로 나누어서 그것이 최소거리 라고 생각하고 공유기를 설치한뒤 공유기의 갯수가 많거나 같으면 간격을 늘리고
			공유기의 갯수가 적으면 간격을 줄여서 설치하면서 최적의 값을 찾는다. (파라메트릭 서치 이용 - 최적해를 찾는 알고리즘)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[200001];

int main()
{
	int N, C, ans;

	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	int left = 1; //최소거리
	int right = arr[N-1] - arr[0]; //최대거리

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 1;
		int now = arr[0];

		for (int i = 1; i < N; i++)
		{
			if (arr[i] - now >= mid)
			{
				cnt++;
				now = arr[i];
			}
		}

		if (cnt >= C) //공유기 갯수가 많으면 간격을 늘린다.
		{
			ans = mid;
			left = mid + 1;
		}
		else //공유기 갯수가 적으면 간격을 줄인다.
			right = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}