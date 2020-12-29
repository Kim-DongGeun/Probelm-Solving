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

vector<pair<int, int>> edge[1001];
vector<bool> visited(1001);

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ c, b });
		edge[b].push_back({ c, a });
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
	int ans = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (visited[cur]) continue;
		visited[cur] = true;

		ans -= cost;

		for (auto x : edge[cur]) {
			int next = x.second;
			int ncost = x.first;

			if (!visited[next]) {
				pq.push({ -ncost, next });
			}
		}
	}

	cout << ans;

	return 0;
}

