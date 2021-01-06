#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

struct Pos { int to, time;
bool operator<(Pos a) const {
	return time < a.time;
}
};

vector<Pos> Map[501];
bool visited[501];
bool circle = false;
int value = 0;
bool Minus = false;

void dfs(int node, int first, int depth, int cnt) {
	if (visited[node]) {
		circle = true;
		value = node;
		return;
	}

	visited[node] = true;

	
	for (int i = 0; i < Map[node].size(); i++) {
		dfs(Map[node][i].to, first, depth + 1, cnt + Map[node][i].time);
		if (circle) return;
	}
		
}

void DFS(int node, int first, int depth, int cnt) {
	if (visited[node]) {
		circle = true;
		if (cnt < 0) Minus = true;
		return;
	}

	visited[node] = true;


	for (int i = 0; i < Map[node].size(); i++) {
		DFS(Map[node][i].to, first, depth + 1, cnt + Map[node][i].time);
		if (circle) return;
	}

}

int main() {
	int N, M, u, v, t;
	cin >> N >> M;

	for(int i = 0 ;i < M; i++){
		cin >> u >> v >> t;
		Map[u].push_back({ v,t });
	}
	
	dfs(1, 1, 0, 0);
	if (circle) {
		memset(visited, false, sizeof(visited));
		circle = false;
		DFS(value, value, 0, 0);
	}
		

	if (circle && Minus) {
		printf("-1\n");
		return 0;
	}

	int dist[501];
	for (int i = 1; i <= N; i++) dist[i] = 100000000;
	priority_queue<Pos> q;
	q.push({ 1, 0 });
	dist[1] = 0;
	while (!q.empty()) {
		int cur = q.top().to;
		int cost = -q.top().time;
		q.pop();

		for (int i = 0; i < Map[cur].size(); i++) {
			int next = Map[cur][i].to;
			int nextcost = dist[cur] + Map[cur][i].time;
			if (dist[next] > nextcost) {
				dist[next] = nextcost;
				q.push({ next, -nextcost });
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (dist[i] == 100000000) printf("-1\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}