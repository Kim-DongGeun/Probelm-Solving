#include <iostream>
using namespace std;

int arr[101];
int dp[100001] = { 0 };

int main() {
	int N, K;
	scanf_s("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf_s("%d", &arr[i]);
	
	dp[0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = arr[i]; j <= K; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}

	printf("%d\n", dp[K]);

	return 0;
}