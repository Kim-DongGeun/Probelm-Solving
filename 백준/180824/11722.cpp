/*
	�����ϴ� ����� ��������
	������ �Ųٷ��Ͽ� LIS����Ǯ�� ��Ĵ�� ǰ
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, plus = 0, answer = 0;
	cin >> N;

	int arr[1001], dp[1001] = { 0 };

	for (int i = N; i >= 1; i--)
	{
		cin >> arr[i];
		dp[i]++;
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				plus = max(plus, dp[j]);
			}
		}
		dp[i] += plus;
		plus = 0;
		answer = max(answer, dp[i]);
	}

	printf("%d\n", answer);
	return 0;
}