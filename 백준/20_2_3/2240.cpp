#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[1001][2][33] = { 0, }; // 시간 / 자리 / 옮길수있는 횟수
int arr[1001];
int T, W;

int dfs(int depth, int cnt, int pos) {
	if (depth == T + 1) return 0;

	int& ref = dp[depth][pos][cnt];
	if (ref != -1) return ref; // 값이 있으면 그냥 리턴

	int MAX = 0;
	if (pos == arr[depth]) {
		if (cnt < W)
			MAX = max(dfs(depth + 1, cnt, pos) + 1, dfs(depth + 1, cnt + 1, pos ^ 1));
		else
			MAX = dfs(depth + 1, cnt, pos) + 1;
		return ref = MAX;
	}
	else {
		if (cnt < W)
			MAX = max(dfs(depth + 1, cnt, pos), dfs(depth + 1, cnt + 1, pos ^ 1) + 1);
		else
			MAX = max(MAX, dfs(depth + 1, cnt, pos));
		return ref = MAX;
	}


}

int main() {
	cin >> T >> W;

	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
		arr[i]--;
	}

	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 0, 0) << "\n";
	
	return 0;
}