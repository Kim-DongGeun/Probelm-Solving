#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1000000000

vector<pair<int, int>> arr[20001];
vector<int> dist(20001);

int main() {
	int V, E, K, u, v, w;
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		arr[u].push_back(make_pair(v, w));
	}

	fill(dist.begin(), dist.end(), INF);
	priority_queue<pair<int, int>> q;
	q.push({ 0, K });
	dist[K] = 0;
	while (!q.empty()) {
		int cur = q.top().second;
		int cost = -q.top().first;
		q.pop();

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i].first;
			int nextcost = arr[cur][i].second;
			if (dist[next] > dist[cur] + nextcost) {
				dist[next] = dist[cur] + nextcost;
				q.push({ -dist[next], next });
			}
		}
	}
	for (int i = 1; i <= V; i++)
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	return 0;
}
