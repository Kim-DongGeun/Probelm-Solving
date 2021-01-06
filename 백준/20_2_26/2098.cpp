#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
using namespace std;

int W[17][17];
int dp[17][1 << 17]; // 현재까지 방문한 최소 비용
int N;

int tsp(int node, int visited) {
	if (visited == ((1 << N) - 1)) { // 전부 방문했으면
		if (W[node][1])  // 경로가 있으면
			return W[node][1];
	}

	int& ret = dp[node][visited];
	if (ret != 0) return ret;

	ret = 16000001;

	for (int i = 1; i <= N; i++) {
		if (!(visited & (1 << (i - 1))) && W[node][i]) { // 방문하지 않고 길이 있으면
			ret = min(ret, W[node][i] + tsp(i, visited | (1 << (i - 1))));
		}
	}
	return ret;
}


int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &W[i][j]);

	printf("%d\n",  tsp(1, 1));


	return 0;
}