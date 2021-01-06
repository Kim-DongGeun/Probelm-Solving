/*
	idea : 배열을 정렬한 후 모든 순서에 대해서 전부 계산한다.
		   next_permutation 함수는 다음번째 순열을 찾아주는 함수
		   다음순열이 있으면 true 없으면 false
*/
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int arr[8];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + N);

	int ans = 0;
	do
	{
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
			sum += abs(arr[i] - arr[i + 1]);
		ans = max(ans, sum);
	} while (next_permutation(arr, arr + N)); //다음순열을 찾아주고 없으면 false 리턴
	
	printf("%d\n", ans);
	return 0;
}