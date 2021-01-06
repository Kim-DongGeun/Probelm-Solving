#include <iostream>
using namespace std;

int main() {
	int Map[51][51];
	int N, M;
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf_s("%1d", &Map[i][j]);

	int limit = N > M ? M : N;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < limit && i + k < N && j + k < M; k++) {
				if (Map[i][j] == Map[i + k][j] && Map[i][j] == Map[i][j + k] && Map[i][j] == Map[i + k][j + k])
					ans = ans < k ? k : ans;
			}
		}
	}
	printf("%d\n", (ans + 1) * (ans + 1));
	return 0;
}