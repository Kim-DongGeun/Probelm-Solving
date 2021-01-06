#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Map[1000001];
bool visited[10000001] = { false, };
int dp[1000001][2] = { 0, };


void dfs(int node) {
	dp[node][0] = 0; // �����尡 �󸮾���;ƴϸ� 0
	dp[node][1] = 1; // �����尡 �󸮾���͸� 1

	for (int i = 0; i < Map[node].size(); i++) {
		int nextnode = Map[node][i];
		if (!visited[nextnode]) {
			visited[nextnode] = true;
			dfs(nextnode);
			dp[node][0] += dp[nextnode][1]; // �����尡 �󸮾���Ͱ� �ƴϸ� �ڽĳ��� ������ �󸮾����
			dp[node][1] += min(dp[nextnode][0], dp[nextnode][1]); // �����尡 �󸮾�����̸� �ڽ��� ����
		}
	}
}

int main() {
	int N, u, v;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		Map[u].push_back(v);
		Map[v].push_back(u);
	}

	visited[1] = true;
	dfs(1);

	printf("%d\n", min(dp[1][0], dp[1][1]));
	return 0;
}