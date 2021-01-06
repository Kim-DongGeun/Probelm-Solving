#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int blood[3];
int dp[66][66][66] = { 0, };
int ans = INT32_MAX;

int Plus[6][3] = {
	{9,3,1}, {3,9,1}, {9,1,3},
	{3,1,9}, {1,3,9}, {1,9,3}
};

int dfs(int x, int y, int z) {
	if (!x && !y && !z) return 0;

	int& ret = dp[x][y][z];
	if (ret != -1) return ret;

	ret = 987654321;

	for (int i = 0; i < 6; i++) {
		ret = min(ret, dfs(max(0, x - Plus[i][0]), max(0, y - Plus[i][1]), max(0, z - Plus[i][2])) + 1);
	}
	return ret;
}

int main() {
	int arr[3] = { 0,0,0 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(arr[0], arr[1], arr[2]) << '\n';
	return 0;
}