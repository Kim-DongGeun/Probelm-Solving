#include <iostream>
using namespace std;

int arr[201][101];

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	arr[0][0] = 1;
	for (int i = 1; i <= N + M; i++) {
		arr[i][0] = 1;
		for (int j = 1; j < i && j <= M; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			if (arr[i][j] > 1000000000) arr[i][j] = 1000000000;
		}
		if (i <= M)arr[i][i] = 1;
	}
	K--;
	if (arr[N + M][M] <= K) {
		printf("-1\n");
		return 0;
	}

	for (int i = N + M - 1; i >= 0; i--) {
		if (i >= M && arr[i][M] > K) printf("a");
		else {
			printf("z");
			K -= arr[i][M];
			M--;
		}
	}


	return 0;
}