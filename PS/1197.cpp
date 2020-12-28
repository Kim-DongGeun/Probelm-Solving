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

int v, e;
vector<pair<int, int>> edge[10001];
//vector<int> dist(10001, INT32_MAX);
vector<bool> visited(10001, false);

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}

	priority_queue<pair<int, int>> q;
	//dist[1] = 0;
	q.push({ 0, 1 });
	
	int ans = 0;
	while (!q.empty()) {
		int cur = q.top().second;
		int cost = -q.top().first;
		q.pop();

		if (visited[cur]) continue;
		visited[cur] = true;
		ans += cost;	

		for (auto x : edge[cur]) {
			int next = x.first;
			int ncost = x.second;
			if (!visited[next]) {
				//dist[next] = ncost;
				q.push({ -ncost, next });
			}
		}
	}
	cout << ans;
	return 0;
}

