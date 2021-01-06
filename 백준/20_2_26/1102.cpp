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
		if (!(visited & (1 << i))){ // �湮�� ������ ��
			if (visit[i] == 'Y') { // ����������
				ret = min(ret, dfs(i, visited | (1 << i), light + 1));
			}
			else { // ����������
				int cnt = INF;
				for (int j = 0; j < N; j++) {
					if (W[j][i] != -1 && (visited & (1 << j))) { // �ٸ� �����ִ� ���� �湮�߰� ����Ǵ� ���� ������
						cnt = min(cnt, W[j][i]); // �����Ѱ��߿��� �ּҰ�ã��
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