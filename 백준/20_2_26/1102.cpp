#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 987654321

int N, P;
int W[17][17];
int dp[17][1 << 17];
char visit[17];

int dfs(int node, int visited, int light) {
	if (light == P) return 0;
	else if (visited == (1 << N) - 1) return INF;


	int& ret = dp[node][visited];
	if (ret != -1) return ret;

	ret = INF;

	for (int i = 0; i < N; i++) {
		if (!(visited & (1 << i))){ // 방문을 안했을 때
			if (visit[i] == 'Y') { // 켜져있으면
				ret = min(ret, dfs(i, visited | (1 << i), light + 1));
			}
			else { // 꺼져있으면
				int cnt = INF;
				for (int j = 0; j < N; j++) {
					if (W[j][i] != -1 && (visited & (1 << j))) { // 다른 켜져있는 곳을 방문했고 연결되는 길이 있으면
						cnt = min(cnt, W[j][i]); // 가능한곳중에서 최소값찾기
					}
				}
				ret = min(ret, dfs(i, visited | (1 << i), light + 1) + cnt);
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	
	memset(W, -1, sizeof(W));
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf(" %d", &W[i][j]);

	scanf("%s", &visit);
	scanf("%d", &P);

	int ans = dfs(0, 0, 0);
	
	printf("%d\n", ans == INF ? -1 : ans);

	return 0;
}