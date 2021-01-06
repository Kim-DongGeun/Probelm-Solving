#include <iostream>
using namespace std;

int dp[300001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int D, N;
	int pizza, a;
	cin >> D >> N;

	for (int i = 1; i <= D; i++) {
		cin >> dp[i];
	}
	int prev = dp[1];
	for (int i = 2; i <= D; i++) {
		if (dp[i] < prev) {
			prev = dp[i];
		}
		else {
			dp[i] = prev;
		}
	}

	int idx = D;
	for (int i = 0; i < N; i++) {
		cin >> a;
		
		while (idx > 0) {
			if (dp[idx] >= a) {
				if(i != N - 1)
					idx--;
				break;
			}
			idx--;
		}
	}

	cout << idx << '\n';

	
	return 0;
}