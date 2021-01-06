#include <iostream>
#include <cstring>
using namespace std;

int order[7][3] = {
	{0,0,1}, {0,1,0}, {1,0,0},
	{0,1,1}, {1,0,1}, {1,1,0},
	{1,1,1}
};

int ans = 0;
bool visited[7];

bool check(int a, int b, int c, int arr[]) {
	if (a - arr[0] >= 0 && b - arr[1] >= 0 && c - arr[2] >= 0) return true;
	else return false;
}

void dfs(int a, int b, int c, int cnt) {

	bool out = true;
	for (int i = 0; i < 7; i++) {
		if (check(a, b, c, order[i]) && !visited[i]) {
			out = false;
			visited[i] = true;
			dfs(a - order[i][0], b - order[i][1], c - order[i][2], cnt + 1);
			visited[i] = false;
		}
	}
	if (out) ans = ans < cnt ? cnt : ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		ans = 0;
		memset(visited, false, sizeof(visited));

		dfs(a, b, c, 0);

		cout << ans << '\n';
	}
	return 0;
}