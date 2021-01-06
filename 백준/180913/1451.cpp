/*
	idea : ���簢�� 3���� ������� �� �ִ� ��찡 6�����ۿ� ����.
		   ��츦 ���� �غ���.
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long d[101][101];
int map[101][101];

long long sum(int x1, int y1, int x2, int y2)
{
	return d[y2][x2] - d[y2][x1-1] - d[y1-1][x2] + d[y1-1][x1-1];
}

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	//�� �Է�
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", &map[i][j]);

	//d[i][j]�� map[1][1] ~ map[i][j]���� ��
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + map[i][j];

	//���η� �������� ���
	long long ans = 0;
	for(int i = 1; i <= M - 2; i++)
		for (int j = i + 1; j <= M - 1; j++)
		{
			long long a1 = sum(1, 1, i, N);
			long long a2 = sum(i + 1, 1, j, N);
			long long a3 = sum(j + 1, 1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	//���η� �������� ���
	for(int i = 1; i <= N-2; i++)
		for (int j = i + 1; j <= N - 1; j++)
		{
			long long a1 = sum(1, 1, M, i);
			long long a2 = sum(1, i + 1, M, j);
			long long a3 = sum(1, j + 1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	//T ���·� �������� ���
	for (int i = 1; i <= N-1; i++)
		for (int j = 1; j <= M - 1; j++)
		{
			long long a1 = sum(1, 1, M, i);
			long long a2 = sum(1, i + 1, j, N);
			long long a3 = sum(j+1, i+1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	// �� ���·� �������� ���
	for (int i = 1; i <= N-1; i++)
		for (int j = 1; j <= M - 1; j++)
		{
			long long a1 = sum(1, 1, j, i);
			long long a2 = sum(j+1, 1, M, i);
			long long a3 = sum(1, i + 1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	// |-- ���·� �������� ���
	for (int i = 1; i <= N - 1; i++)
		for (int j = 1; j <= M - 1; j++)
		{
			long long a1 = sum(1, 1, j, N);
			long long a2 = sum(j + 1, 1, M, i);	
			long long a3 = sum(j + 1, i + 1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	// --| ���·� �������� ���
	for (int i = 1; i <= N - 1; i++)
		for (int j = 1; j <= M-1; j++)
		{
			long long a1 = sum(1, 1, j, i);
			long long a2 = sum(1, i + 1, j, N);
			long long a3 = sum(j + 1, 1, M, N);
			ans = max(ans, a1*a2*a3);
		}

	printf("%lld\n", ans);
	return 0;
}