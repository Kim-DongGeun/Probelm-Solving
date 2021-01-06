#include <iostream>
using namespace std;

int arr[301];
pair<int, int> dp[1000001][2];

void dfs(int cur) {
	dp[cur][0] = 
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dfs(0);

	return 0;
}