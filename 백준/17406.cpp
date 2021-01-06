#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

int Arr[51][51];
int arr[51][51];

int r[6], c[6], s[6];

void rotate(int R, int C, int S) {
	int temp[51][51];
	for (int l = 3; l <= 2 * S + 1; l += 2) {
		int t = (2 * S + 1 - l) / 2;
		for (int i = 0; i < l - 1; i++) {
			temp[R - S + i + t][C - S + t] = arr[R - S + i + 1 + t][C - S + t];
		}
	}

	for (int l = 3; l <= 2 * S + 1; l += 2) {
		int t = (2 * S + 1 - l) / 2;
		for (int i = 0; i < l - 1; i++) {
			temp[R - S + t][C + S - i - t] = arr[R - S + t][C + S - i - 1 - t];
		}
	}

	for (int l = 3; l <= 2 * S + 1; l += 2) {
		int t = (2 * S + 1 - l) / 2;
		for (int i = 0; i < l - 1; i++) {
			temp[R + S - i - t][C + S - t] = arr[R + S - i - 1 - t][C + S - t];
		}
	}

	for (int l = 3; l <= 2 * S + 1; l += 2) {
		int t = (2 * S + 1 - l) / 2;
		for (int i = 0; i < l - 1; i++) {
			temp[R + S - t][C - S + i + t] = arr[R + S - t][C - S + i + 1 + t];
		}
	}

	
for (int i = R - S; i <= R + S; i++)
	for (int j = C - S; j <= C + S; j++) 
		if(i != R || j != C) arr[i][j] = temp[i][j];

}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> r[i] >> c[i] >> s[i];
	}

	vector<int> v(k);
	for (int i = 0; i < k; i++) v[i] = i;

	int ans = 5001;
	do {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) arr[i][j] = Arr[i][j];

		for(int i = 0 ;i < k; i++){
			rotate(r[v[i]], c[v[i]], s[v[i]]);
		}
		int total = 5001;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++) {
				sum += arr[i][j];
			}
			total = min(total, sum);
		}
		ans = min(ans, total);
	} while (next_permutation(v.begin(), v.end()));

	cout << ans;


	return 0;
}