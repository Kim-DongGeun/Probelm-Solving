#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal1(int N, int M, vector<vector<int>> &map) // 1 x 4, 4 x 1
{
	int Sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 3; j++) {
			int sum = 0;
			for (int k = j; k < j + 4; k++)
				sum += map[i][k];
			Sum = max(sum, Sum);
		}
	}
	for(int i = 0 ; i < N - 3; i++)
		for (int j = 0; j < M; j++)
		{
			int sum = 0;
			for (int k = i; k < i + 4; k++)
				sum += map[k][j];
			Sum = max(sum, Sum);
		}

	return Sum;
}

int cal2(int N, int M, vector<vector<int>> &map) // 2 x 2
{
	int Sum = 0;
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M - 1; j++) {
			int sum = 0;
			for (int k = i; k < i + 2; k++)
				for(int l = j; l < j + 2; l++)
					sum += map[k][l];
			Sum = max(sum, Sum);
		}
	return Sum;
}

int cal3(int N, int M, vector<vector<int>> &map) // ¤¡ ¸ð¾ç
{
	int Sum = 0;
	for (int i = 0; i < N - 2; i++)
		for (int j = 0; j < M - 1; j++) {
			int sum = 0;
			sum += map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i + 2][j];
			Sum = max(sum, Sum);
		}
	return Sum;
}

int cal4(int N, int M, vector<vector<int>> &map) // 2 x 3
{
	int Sum = 0;
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M - 2; j++) {
			int sum = 0;
			sum += map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 1];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j + 2] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i][j + 2];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i][j + 2];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
			Sum = max(sum, Sum);
			sum = 0;
			sum += map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
			Sum = max(sum, Sum);
		}
	return Sum;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int>> map(N, vector<int>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) scanf("%d", &map[i][j]);

	int ans = 0;
	ans = max(ans, cal1(N, M, map));
	ans = max(ans, cal2(N, M, map));
	ans = max(ans, cal3(N, M, map));
	ans = max(ans, cal4(N, M, map));
	printf("%d\n", ans);
	return 0;
}