/*
	수열의 연속하는 요소의 합의 최대
	처음에는 재귀형태 풀었지만 시간초과
	점화식 dp[i] = dp[i-1] + input if(dp[i-1]+input > input)
	else dp[i] = input
	답을 비교할때 answer = 0으로 초기화해서 시간잡아먹음
	-1000 <= answer <= 1000
*/
#include <iostream>
#include <algorithm>
using namespace std;


//시간초과
/*int cal(int start, int end, int arr[])
{
	int sum = 0;
	if (start > end)
		return 0;
	for (int i = start; i <= end; i++)
		sum += arr[i];
	//if(arr[start] < arr[end])
		sum = max(cal(start + 1, end, arr), sum);
	//else if(arr[start] > arr[end])
		sum = max(cal(start, end - 1, arr), sum);
	/*else
	{
		if(arr[start+1] < arr[end-1])
			sum = max(cal(start + 1, end, arr), sum);
		else
			sum = max(cal(start, end - 1, arr), sum);
	}

	return sum;
}
*/

int main()
{
	int N, answer = -1001, input;
	cin >> N;

	int dp[100001] = { 0 };

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &input);

		dp[i] = max(input, dp[i - 1] + input);

		answer = max(answer, dp[i]);
	}

	printf("%d\n", answer);
	return 0;
}