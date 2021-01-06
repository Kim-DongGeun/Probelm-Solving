#include <iostream>
using namespace std;

int N;
int Map[101][101];
long long dp[101][101];


int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf_s("%d", &Map[i][j]);

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1)break;
			if (dp[i][j] != 0) {
				if(Map[i][j] + j < N)
					dp[i][j + Map[i][j]] += dp[i][j];
				if (Map[i][j] + i < N)
					dp[i + Map[i][j]][j] += dp[i][j];
			}
		}
	}

	printf("%lld\n", dp[N - 1][N - 1]);
	return 0;
}