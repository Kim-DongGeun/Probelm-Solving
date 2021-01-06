#include <iostream>
#include <algorithm>
using namespace std;

#define INF 100001

int main() {
	int n, k, arr[101], dp[100001];
	cin >> n >> k;

	for (int i = 1; i <= k; i++)
		dp[i] = INF;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[arr[i]] = 1;
	}

	sort(arr, arr + n);
	

	for (int i = 1; i <= k; i++) {
		if (dp[i] == 1) continue;

		int cnt = INF;
		for (int j = 0; j < n && i >= arr[j]; j++) {
			cnt = min(cnt, dp[i - arr[j]]);
		}
		if(cnt != INF)
			dp[i] = cnt + 1;
	}
	if (dp[k] == INF)
		cout << -1 << endl;
	else 
		cout << dp[k] << endl;
	return 0;
}