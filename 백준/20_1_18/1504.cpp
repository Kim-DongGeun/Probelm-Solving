#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, E, target1, target2, from, to, value;
vector<vector<pair<int, int>>> arr(801);
#define INF 800000

long long dijkstra(int start, int end) {
	vector<long long> dist(N+1);
	fill(dist.begin(), dist.end(), INF);

	priority_queue<pair<int, int>> q;

	q.push(make_pair(0, start));
	dist[start] = 0;

	while (!q.empty()) {
		int cost = -q.top().first;
		int here = q.top().second;

		q.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < arr[here].size(); i++) {
			int next = arr[here][i].first;
			int nextcost = arr[here][i].second;

			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				q.push(make_pair(-nextcost, next));
			}
		}
	}
	return dist[end];
}

int main() {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> from >> to >> value;
		arr[from].push_back(make_pair(to, value));
		arr[to].push_back(make_pair(from, value));
	}
	cin >> target1 >> target2;

	
	long long ans = dijkstra(target1, target2);

	long long dis1 = dijkstra(1, target1);
	long long dis2 = dijkstra(1, target2);
	long long Dis1 = dijkstra(N, target1);
	long long Dis2 = dijkstra(N, target2);

	long long ans1, ans2;
	ans1 = dis1 + Dis2;
	ans2 = dis2 + Dis1;

	if (ans == INF || (ans1 >= INF && ans2 >= INF)) printf("-1\n");
	else printf("%lld\n", (ans1 > ans2 ? ans2 : ans1) + ans);
	return 0;
}