/*
	��ܿ����� ����
	2156������ ����ϴ�
	�ٸ����� 2156�� 2���̻��� �ǳʶۼ������� �̹����� ��� 1�� ���Ϸθ�
	�ǳʶۼ��ִ�.
*/
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	int dp[10001] = { 0 };
	int* arr = new int[N + 1];

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; i++)
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);

	printf("%d\n", dp[N]);
	return 0;
}