#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };

using namespace std;

int arr[1001][1001];
int n, m, X;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> n >> m >> X;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = 1000001;
		}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}



	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, arr[i][X] + arr[X][i]);
	cout << ans;

	return 0;
}