#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt;
struct pos { int x1, y1, x2, y2; };
vector<pos> arr;
bool visited[3001] = { false, };
int N;

bool check(pos a, pos b) {
	if (max(a.x1, a.x2) < min(b.x1, b.x2)) return false;
	if (min(a.x1, a.x2) > max(b.x1, b.x2)) return false;
	if (max(a.y1, a.y2) < min(b.y1, b.y2)) return false;
	if (min(a.y1, a.y2) > max(b.y1, b.y2)) return false;

	int temp1 = (a.x2 - a.x1) * (b.y1 - a.y1) - (a.y2 - a.y1) * (b.x1 - a.x1);
	int temp2 = (a.x2 - a.x1) * (b.y2 - a.y1) - (a.y2 - a.y1) * (b.x2 - a.x1);

	if (temp1 * temp2 <= 0) return true;
	else return false;
}

void dfs(int cur) {
	visited[cur] = true;
	cnt++;

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			if (check(arr[cur], arr[i]) && check(arr[i], arr[cur]))
				dfs(i);
		}
	}
}

int main() {
	cin >> N;

	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2;
	}

	int count = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			cnt = 0;
			count++;
			dfs(i);
		}
		ans = max(ans, cnt);
	}

	cout << count << '\n' << ans << '\n';
	return 0;
}