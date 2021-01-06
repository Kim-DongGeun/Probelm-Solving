#include <iostream>
using namespace std;

int arr[10001];

int main()
{
	long long N;
	int M;
	scanf("%lld %d", &N, &M);

	for (int i = 1; i <= M; i++)
		scanf("%d", &arr[i]);

	if (N <= M) //사람수가 놀이기구 수 보다 작으면 마지막사람이 탄 기구가 답
	{
		printf("%lld\n", N);
		return 0;
	}

	long long low = 0;
	long long high = 60000000000; //최대 시간
	long long time = 0;

	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long sum = M; //맨처음에는 기구수만큼 사람이 타게됨

		for (int i = 1; i <= M; i++)
			sum += (mid / (long long)arr[i]);// mid시간에 타고있는 k번쨰 사람

		if (sum < N) //N보다 작으면 전체 시간을 늘린다.
			low = mid + 1;
		else //작거나 같으면 전체 시간을 줄인다. 페라메티륵 서치 (이진탐색에서 더 최적의 해를 찾는 방법)
		{
			time = mid;
			high = mid - 1;
		}
	}

	long long cnt = M;
	for (int i = 1; i <= M; i++)
		cnt += ((time-1) / arr[i]); //찾은 시간 1분전에 타고있는 K번쨰 사람이 찾는다.

	for (int i = 1; i <= M; i++) //time시간에 타고있는 사람이 N번째 사람인지 기구 마다 체크한다.
	{
		if (time % arr[i] == 0) cnt++;
		if (cnt == N)
		{
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}