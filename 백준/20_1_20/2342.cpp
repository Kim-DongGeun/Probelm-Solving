#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <ctime>
using namespace std;

int arr[100001];
int dp[100001][5][5] = { 0, }; // ½ºÅ×ÀÌÁö, ¿Þ¹ß, ¿À¸¥¹ß

int Value(int cur, int next) {
	if (cur == 0) return 2;
	else if (abs(next - cur) == 1) return 3;
	else if (abs(next - cur) == 2) return 4;
	else if (abs(next - cur) == 3) return 3;
	return 1;
}

int main() {

	int n, index = 0;
	while (true) {
		cin >> arr[index];
		if (arr[index++] == 0) break;
	}
	index--;

	for (int i = 0; i <= index; i++)
		for (int j = 0; j <= 4; j++)
			for (int k = 0; k <= 4; k++) dp[i][j][k] = 10000000;

	dp[0][0][0] = 0;

	for (int i = 1; i <= index; i++) {
		for (int j = 0; j <= 4; j++) { // ¿Þ¹ß¿òÁ÷
			if (arr[i - 1] == j) continue; // ¿À¸¥¹ßÀÌ¶û °°À¸¸é ¾ÈµÊ
			for (int k = 0; k <= 4; k++) {
				int plus = Value(k, arr[i - 1]);
				dp[i][arr[i - 1]][j] = min(dp[i][arr[i - 1]][j], dp[i - 1][k][j] + plus);
			}
		}

		for (int j = 0; j <= 4; j++) { // ¿À¸¥¹ß¿òÁ÷
			if (arr[i - 1] == j) continue; // ¿Þ¹ßÀÌ¶û °°À¸¸é ¾ÈµÊ
			for (int k = 0; k <= 4; k++) {
				int plus = Value(k, arr[i - 1]);
				dp[i][j][arr[i - 1]] = min(dp[i][j][arr[i - 1]], dp[i - 1][j][k] + plus);
			}
		}
	}

	int ans = 10000000;
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			ans = min(ans, dp[index][i][j]);
	printf("%d\n", ans);
	return 0;
}