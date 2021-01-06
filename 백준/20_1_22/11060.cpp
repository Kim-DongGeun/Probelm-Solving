#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int arr[1001], dp[1001];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 100000000;
	}

	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= arr[i] && i + j < N; j++)
			dp[i + j] = min(dp[i + j], dp[i] + 1);
	}
	printf("%d\n", dp[N - 1] == 100000000 ? -1 : dp[N - 1]);
	return 0;
}