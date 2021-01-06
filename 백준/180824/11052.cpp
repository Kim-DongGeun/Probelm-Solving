/*
	�������� dp���� ��ȭ�İ� memorization�� ���
	�ͼ����������� ������ �ʿ���
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int arr[1001];
	int dp[1001] = { 0 };

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	dp[1] = arr[1];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}