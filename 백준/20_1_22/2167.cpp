#include <iostream>
using namespace std;

int Map[301][301];

int main() {
	int N, M, K;
	int i, j, x, y;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> Map[i][j];

	
	cin >> K;
	for (int I = 0; I < K; I++) {
		cin >> i >> j >> x >> y;
		int sum = 0;
		for (int J = i - 1; J < x; J++)
			for (int k = j - 1; k < y; k++)
				sum += Map[J][k];
		printf("%d\n", sum);
	}

	return 0;
}