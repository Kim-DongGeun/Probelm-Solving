/*
	����� ������� �κм���
	���� �� �����ϴ¼����� ���� �� �����ϴ� ������ ���� �ִ밡 �Ǵ� ������
	����� ������кκм����� ����
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, plus1 = 0, plus2 = 0, answer = 0;
	cin >> N;

	int arr[2][1001], dp[2][1001] = { 0 };

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[0][i];
		arr[1][N - i + 1] = arr[0][i];
		dp[0][i]++;
		dp[1][i]++;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[0][j] < arr[0][i])
				plus1 = max(plus1, dp[0][j]);
			if(arr[1][j] < arr[1][i])
				plus2 = max(plus2, dp[1][j]);
			
		}
		dp[0][i] += plus1;
		dp[1][i] += plus2;

		plus1 = 0, plus2 = 0;
	}

	for (int i = 1; i <= N; i++)
		answer = max(answer, dp[0][i] + dp[1][N - i + 1]);
	
	printf("%d\n", answer - 1);
	return 0;
}